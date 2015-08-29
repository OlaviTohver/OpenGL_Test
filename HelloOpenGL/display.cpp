/*
 * display.cpp
 *
 *  Created on: 22.08.2015
 *      Author: olavi
 *      gwgkwegqwegqlweg
 */

#include "display.h"
#include <iostream>
#include <GL/glew.h>


Display::Display(int width,int height, const std::string& title) {
	//Initialize SDL library and shit
	SDL_Init(SDL_INIT_EVERYTHING);
	//Set an OpenGL window attributes before window creation
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	//Create a window with the specified position, dimensions, and flags.
	m_window=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_OPENGL);
	//Create an OpenGL context for use with an OpenGL window, and make it current.
	m_glContext=SDL_GL_CreateContext(m_window);
	// Get GLEW status information
	GLenum status =glewInit();
	// If GLEW has problem with initializing
	if (status !=GLEW_OK)
	{
		std::cerr<<"GLEW failed to initialize!"<<std::endl;
	}
	//Setting boolean FALSE to indicate that window is currently open
	b_isClosed=false;
}

Display::~Display()
{
//Delete an OpenGL context.
	SDL_GL_DeleteContext(m_glContext);
	// Destroy a window.
	SDL_DestroyWindow(m_window);
	/*
	 *  This function cleans up all initialized subsystems. You should
	 *  call it upon all exit conditions.
	 */
	SDL_Quit();
}
void Display::UpdateScreen()
{
/*Swap the OpenGL buffers for a window, if double-buffering is supported */
	SDL_GL_SwapWindow(m_window);

	SDL_Event e;
	/*Polls for currently pending events.
	Return 1 if there are any pending events, or 0 if there are none available.
	*/
	while(SDL_PollEvent(&e))
{
	// Checks if user requested quit
	if (e.type==SDL_QUIT)
	{
	//Window is closed
	b_isClosed=true;
	}
 }
}
bool Display::IsClosed()
{
	return b_isClosed;
}
