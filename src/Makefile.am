lib_LTLIBRARIES = libdynplot.la

libdynplot_la_SOURCES = \
	camera.cpp dynplot/camera.h \
	clipper.cpp dynplot/clipper.h \
	display.cpp dynplot/display.h \
	dynplot/light.h \
	mesh.cpp dynplot/mesh.h \
	model.cpp dynplot/model.h \
	objloader.cpp dynplot/objloader.hpp \
	plotter.cpp dynplot/plotter.h \
	shader.cpp dynplot/shader.h \
	dynplot/stb_image.h \
	texture.cpp dynplot/texture.h \
	vboindexer.cpp dynplot/vboindexer.hpp \
	writer.cpp dynplot/writer.h

libdynplot_la_HEADERS = dynplot.hh

main_CFLAGS = $(GLFW_CFLAGS)

if DARWIN
OPENGL = -framework OpenGL
else
OPENGL = -lGL
endif

libdynplot_la_LDFLAGS = \
	$(GLFW_LIBS) \
	-lfreetype \
	-lGLEW \
	$(OPENGL)

libdynplot_ladir = $(includedir)

dynplotincludedir = $(includedir)/dynplot
dynplotinclude_HEADERS =\
	dynplot/camera.h \
	dynplot/clipper.h \
	dynplot/display.h \
	dynplot/light.h \
	dynplot/mesh.h \
	dynplot/model.h \
	dynplot/objloader.hpp \
	dynplot/plotter.h \
	dynplot/shader.h \
	dynplot/stb_image.h \
	dynplot/texture.h \
	dynplot/vboindexer.hpp \
	dynplot/writer.h
