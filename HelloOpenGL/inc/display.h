/*
 * display.h
 *
 *  Created on: 22.08.2015
 *      Author: olavi
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL/SDL.h>
#include <string>

class Display {
public:
	Display(int width,int height, const std::string& title);
	//Update screen (swapping window and openGL buffers)
	void UpdateScreen();
	bool IsClosed();
	virtual ~Display();
protected:
private:

	SDL_Window* m_window;		//Pointer to window
	SDL_GLContext m_glContext;	//Context of the window
	bool b_isClosed;			//Boolean for setting window status

};

#endif /* DISPLAY_H_ */
