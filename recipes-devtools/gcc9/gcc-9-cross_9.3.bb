require recipes-devtools/gcc9/gcc-${PV}.inc
inherit cross

INHIBIT_DEFAULT_DEPS = "1"
EXTRADEPENDS = ""
DEPENDS = "virtual/${TARGET_PREFIX}binutils ${EXTRADEPENDS} ${NATIVEDEPS}"

python () {
    if d.getVar("TARGET_OS").startswith("linux"):
        d.setVar("EXTRADEPENDS", "linux-libc-headers")
}

PN = "gcc-9-cross-${TARGET_ARCH}"

# Ignore how TARGET_ARCH is computed.
TARGET_ARCH[vardepvalue] = "${TARGET_ARCH}"

require gcc-configure-common.inc

# While we want the 'gnu' hash style, we explicitly set it to sysv here to
# ensure that any recipe which doesn't obey our LDFLAGS (which also set it to
# gnu) will hit a QA failure.
LINKER_HASH_STYLE ?= "sysv"

EXTRA_OECONF += "--enable-poison-system-directories"
EXTRA_OECONF:append:sh4 = " \
    --with-multilib-list= \
    --enable-incomplete-targets \
"

EXTRA_OECONF += "\
    --with-system-zlib \
"

EXTRA_OECONF:append:libc-baremetal = " --without-headers"
EXTRA_OECONF:remove:libc-baremetal = "--enable-threads=posix"
EXTRA_OECONF:remove:libc-newlib = "--enable-threads=posix"

EXTRA_OECONF_PATHS = "\
    --with-gxx-include-dir=/not/exist${target_includedir}/c++/${BINV} \
    --with-sysroot=/not/exist \
    --with-build-sysroot=${STAGING_DIR_TARGET} \
"

ARCH_FLAGS_FOR_TARGET += "-isystem${STAGING_DIR_TARGET}${target_includedir}"


do_configure:prepend () {
	install -d ${RECIPE_SYSROOT}${target_includedir}
	touch ${RECIPE_SYSROOT}${target_includedir}/limits.h
}

do_compile () {
	export CC="${BUILD_CC}"
	export AR_FOR_TARGET="${TARGET_SYS}-ar"
	export RANLIB_FOR_TARGET="${TARGET_SYS}-ranlib"
	export LD_FOR_TARGET="${TARGET_SYS}-ld"
	export NM_FOR_TARGET="${TARGET_SYS}-nm"
	export CC_FOR_TARGET="${CCACHE} ${TARGET_SYS}-gcc"
	export CFLAGS_FOR_TARGET="${TARGET_CFLAGS}"
	export CPPFLAGS_FOR_TARGET="${TARGET_CPPFLAGS}"
	export CXXFLAGS_FOR_TARGET="${TARGET_CXXFLAGS}"
	export LDFLAGS_FOR_TARGET="${TARGET_LDFLAGS}"

	# Prevent native/host sysroot path from being used in configargs.h header,
	# as it will be rewritten when used by other sysroots preventing support
	# for gcc plugins
	oe_runmake configure-gcc
	sed -i 's@${STAGING_DIR_TARGET}@/host@g' ${B}/gcc/configargs.h
	sed -i 's@${STAGING_DIR_HOST}@/host@g' ${B}/gcc/configargs.h

	# Prevent sysroot/workdir paths from being used in checksum-options.
	# checksum-options is used to generate a checksum which is embedded into
	# the output binary.
	oe_runmake TARGET-gcc=checksum-options all-gcc
	sed -i 's@${DEBUG_PREFIX_MAP}@@g' ${B}/gcc/checksum-options
	sed -i 's@${STAGING_DIR_HOST}@/host@g' ${B}/gcc/checksum-options

	oe_runmake all-host configure-target-libgcc
	(cd ${B}/${TARGET_SYS}/libgcc; oe_runmake enable-execute-stack.c unwind.h md-unwind-support.h sfp-machine.h gthr-default.h)
}

INHIBIT_PACKAGE_STRIP = "1"

# Compute how to get from libexecdir to bindir in python (easier than shell)
BINRELPATH = "${@os.path.relpath(d.expand("${STAGING_DIR_NATIVE}${prefix_native}/bin/${TARGET_SYS}"), d.expand("${libexecdir}/gcc/${TARGET_SYS}/${BINV}"))}"

do_install () {
	( cd ${B}/${TARGET_SYS}/libgcc; oe_runmake 'DESTDIR=${D}' install-unwind_h-forbuild install-unwind_h )
	oe_runmake 'DESTDIR=${D}' install-host

	install -d ${D}${target_base_libdir}
	install -d ${D}${target_libdir}

	# Link gfortran to g77 to satisfy not-so-smart configure or hard coded g77
	# gfortran is fully backwards compatible. This is a safe and practical solution. 
	if [ -n "${@d.getVar('FORTRAN')}" ]; then
		ln -sf ${STAGING_DIR_NATIVE}${prefix_native}/bin/${TARGET_PREFIX}gfortran ${STAGING_DIR_NATIVE}${prefix_native}/bin/${TARGET_PREFIX}g77 || true
		fortsymlinks="g77 gfortran"
	fi

	# Insert symlinks into libexec so when tools without a prefix are searched for, the correct ones are
	# found. These need to be relative paths so they work in different locations.
	dest=${D}${libexecdir}/gcc/${TARGET_SYS}/${BINV}/
	install -d $dest
	for t in ar as ld ld.bfd ld.gold nm objcopy objdump ranlib strip gcc cpp $fortsymlinks; do
		ln -sf ${BINRELPATH}/${TARGET_PREFIX}$t $dest$t
		ln -sf ${BINRELPATH}/${TARGET_PREFIX}$t ${dest}${TARGET_PREFIX}$t
	done

	# Remove things we don't need but keep share/java
	for d in info man share/doc share/locale share/man share/info; do
		rm -rf ${D}${STAGING_DIR_NATIVE}${prefix_native}/$d
	done

	# libquadmath headers need to  be available in the gcc libexec dir
	install -d ${D}${libdir}/gcc/${TARGET_SYS}/${BINV}/include/
	cp ${S}/libquadmath/quadmath.h ${D}${libdir}/gcc/${TARGET_SYS}/${BINV}/include/
	cp ${S}/libquadmath/quadmath_weak.h ${D}${libdir}/gcc/${TARGET_SYS}/${BINV}/include/

	# We use libiberty from binutils
	find ${D}${exec_prefix}/lib -name libiberty.a | xargs rm -f
	find ${D}${exec_prefix}/lib -name libiberty.h | xargs rm -f

	find ${D}${libdir}/gcc/${TARGET_SYS}/${BINV}/include-fixed -type f -not -name "README" -not -name limits.h -not -name syslimits.h | xargs rm -f
}

do_package[noexec] = "1"
do_packagedata[noexec] = "1"
do_package_write_ipk[noexec] = "1"
do_package_write_rpm[noexec] = "1"
do_package_write_deb[noexec] = "1"

inherit chrpath

python gcc9_stash_builddir_fixrpaths() {
    # rewrite rpaths, breaking hardlinks as required
    process_dir("/", d.getVar("BUILDDIRSTASH"), d, break_hardlinks = True)
}

BUILDDIRSTASH = "${WORKDIR}/stashed-builddir/build"
do_gcc9_stash_builddir[dirs] = "${B}"
do_gcc9_stash_builddir[cleandirs] = "${BUILDDIRSTASH}"
do_gcc9_stash_builddir[postfuncs] += "gcc9_stash_builddir_fixrpaths"
do_gcc9_stash_builddir () {
	dest=${BUILDDIRSTASH}
	hardlinkdir . $dest
	# Makefile does move-if-change which can end up with 'timestamp' as file contents so break links to those files
	rm $dest/gcc/include/*.h
	cp gcc/include/*.h $dest/gcc/include/
}
addtask do_gcc9_stash_builddir after do_compile before do_install
SSTATETASKS += "do_gcc9_stash_builddir"
do_gcc9_stash_builddir[sstate-inputdirs] = "${BUILDDIRSTASH}"
do_gcc9_stash_builddir[sstate-outputdirs] = "${COMPONENTS_DIR}/${BUILD_ARCH}/gcc9-stashed-builddir-${TARGET_SYS}"
do_gcc9_stash_builddir[sstate-fixmedir] = "${COMPONENTS_DIR}/${BUILD_ARCH}/gcc9-stashed-builddir-${TARGET_SYS}"

python do_gcc9_stash_builddir_setscene () {
    sstate_setscene(d)
}
addtask do_gcc9_stash_builddir_setscene

