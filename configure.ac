# Initialize AC: ACINIT( package_name, version, bug_report_address)
AC_INIT([DynPlot], [1.0.0])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src])

LT_INIT

# Initialize Automake
AM_INIT_AUTOMAKE

# Check the OS
AM_CONDITIONAL([DARWIN], [test $(uname) = Darwin])

PKG_PROG_PKG_CONFIG
PKG_CONFIG="$PKG_CONFIG --static"

PKG_CHECK_MODULES([GLFW], [glfw3])

# It is required if any libraries are built in the package
AC_PROG_RANLIB

# Check a C++ compiler
AC_LANG(C++)

# Set C++ compiler
AC_PROG_CXX(g++-6)

# Makefiles location
AC_CONFIG_FILES([Makefile src/Makefile])

# Produce configure file
AC_OUTPUT
