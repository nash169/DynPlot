cmake_minimum_required(VERSION 3.0)

# Set the name of your project here
project(dynplot)

option(ENABLE_SIMD "Build with all SIMD instructions on the current local machine" ON)

find_package(PkgConfig)
find_package(Freetype)

# Find libraries and dependencies
# pkg_search_module(Freetype REQUIRED freetype2)
pkg_search_module(glfw3 REQUIRED glfw3)
pkg_search_module(glew REQUIRED glew)
pkg_search_module(glm REQUIRED glm)

set(DYNPLOT_BINARY_INSTALL_DIR bin)
set(DYNPLOT_LIBRARY_INSTALL_DIR lib${LIB_SUFFIX})
set(DYNPLOT_INCLUDE_INSTALL_DIR include/dynplot)

function(add_simd TARGET)
  if(ENABLE_SIMD)
    if(CMAKE_COMPILER_IS_GNUCXX)
      execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} -dumpfullversion -dumpversion OUTPUT_VARIABLE GCC_VERSION)
      set(CXX_COMPILER_VERSION ${GCC_VERSION})
      target_compile_options(${TARGET} PUBLIC -march=native)
      if(GCC_VERSION VERSION_GREATER 7.0)
        target_compile_options(${TARGET} PUBLIC -faligned-new)
      endif()
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
      target_compile_options(${TARGET} PUBLIC -march=native -faligned-new)
    endif()
  endif()
endfunction()

add_subdirectory(src)
