AC_PREREQ([2.64])

m4_define([build_shell_major_version], [0])
m4_define([build_shell_minor_version], [0])
m4_define([build_shell_micro_version], [0])
m4_define([build_shell_version],
          [build_shell_major_version.build_shell_minor_version.build_shell_micro_version])

AC_INIT([build_shell],
        [build_shell_version],
        [https://github.com/jorgen/build_shell],
        [build_shell],
        [https://github.com/jorgen/build_shell])

AC_SUBST([BUILD_SHELL_VERSION_MAJOR], [build_shell_major_version])
AC_SUBST([BUILD_SHELL_VERSION_MINOR], [build_shell_minor_version])
AC_SUBST([BUILD_SHELL_VERSION_MICRO], [build_shell_micro_version])
AC_SUBST([BUILD_SHELL_VERSION], [build_shell_version])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
m4_include([m4/ax_cxx_compile_stdcxx_11.m4])

AM_INIT_AUTOMAKE([1.11 foreign no-dist-gzip dist-xz])

#AM_SILENT_RULES([yes])

CXXFLAGS="$CXXFLAGS -Wall -Wextra -ggdb"

AC_LANG(C++)

AC_CANONICAL_HOST

compilers=""
case $host_os in
  darwin* )
    compilers="clang++"
    ;;
  *)
    compilers=""
    ;;
esac

AC_PROG_CXX([$compilers])

AX_CXX_COMPILE_STDCXX_11([ext])

if test "x$CXX" = "xclang++"; then
    CXXFLAGS="$CXXFLAGS -stdlib=libc++"
    LDFLAGS="$LDFLAGS -stdlib=libc++"
else
    CXXFLAGS="$CXXFLAGS -pthread"
    LDFLAGS="$LDFLAGS -pthread"
fi

AC_ARG_ENABLE(developer-build, [  --enable-developer-build],,
        enable_developer_build=yes)
AM_CONDITIONAL(ENABLE_DEVELOPER_BUILD, test x$enable_developer_build = xyes)

AC_DEFUN([AC_PROG_BASH], [AC_CHECK_PROG(HAS_BASH_EXEC,bash,yes)])
AC_PROG_BASH
if test x"${HAS_BASH_EXEC}" != x"yes" ; then
    AC_MSG_ERROR([Buildshell rellies on a bash executable being in the path.])
fi

AC_SUBST(GCC_CFLAGS)

AC_CONFIG_FILES([Makefile
		 src/Makefile
                 src/build_shell/Makefile
                 src/jsonmod/Makefile
		 src/build_shell-version.h
                 data/Makefile])
AC_OUTPUT
