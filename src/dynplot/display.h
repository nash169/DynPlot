#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <stdio.h>

class Display
{
public:
	Display( const std::string& title, int width, int height );

	Display();

	virtual ~Display();

	void Clear(float r, float b, float g, float a);

	void Update();

	void SetRecorder(const std::string& savePath);

	bool isClosed();

protected:

private:
	GLFWwindow* m_window;

	bool m_isClosed, record;
	int x, y, *buffer, dummy;

	char *fname;
	FILE *ffmpeg;

};

#endif // DISPLAY_H
