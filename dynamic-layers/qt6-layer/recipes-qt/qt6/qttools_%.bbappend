# mesa bbapend file configure as PACKAGECONFIG:append:class-target:amd-x86 = " gallium-llvm"
# so both llvm and Clang available in ${RECIPE_SYSROOT}.
# llvm relatvie cmake file install into qttools ${RECIPE_SYSROOT}, cause qttools configure error,
# so remove llvm and only keep clang for qtoots configure.
SSTATE_EXCLUDEDEPS_SYSROOT:append:amd-x86 = " \
    .*->.*llvm.* \
"
