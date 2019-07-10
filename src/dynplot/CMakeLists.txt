set(dynplot_HEADERS
    camera.hpp
    clipper.hpp
    display.hpp
    light.hpp
    mesh.hpp
    model.hpp
    objloader.hpp
    plotter.hpp
    shader.hpp
    stb_image.h
    texture.hpp
    vboindexer.hpp
    writer.hpp
)

set(dynplot_SOURCES
    camera.cpp
    clipper.cpp
    display.cpp
    mesh.cpp
    model.cpp
    objloader.cpp
    plotter.cpp
    shader.cpp
    texture.cpp
    vboindexer.cpp
    writer.cpp
)

add_library(DynPlot SHARED ${dynplot_SOURCES})

target_include_directories(DynPlot PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${FREETYPE_INCLUDE_DIRS}
    ${GLFW3_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
)

set_property(TARGET DynPlot PROPERTY CXX_STANDARD 11)
set_property(TARGET DynPlot PROPERTY CXX_STANDARD_REQUIRED ON)

add_simd(DynPlot)

install(TARGETS DynPlot
    RUNTIME DESTINATION ${DYNPLOT_BINARY_INSTALL_DIR}
    LIBRARY DESTINATION ${DYNPLOT_LIBRARY_INSTALL_DIR}
    ARCHIVE DESTINATION ${DYNPLOT_LIBRARY_INSTALL_DIR})

install(FILES ${dynplot_HEADERS} DESTINATION ${DYNPLOT_INCLUDE_INSTALL_DIR})
