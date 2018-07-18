#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include"Screen.h"
#include"Node.h"
#include"Character.h"
#include "Word.h"
#include "Button.h"
#include "LTexture.h"
#include "Screen.h"
#include"Point.h"
class MainMenu : public Screen
{
    public:
        MainMenu(LTexture*, LTexture*, int, int);
        MainMenu();
        ~MainMenu();
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        string text;
        Point p;
        void handle_event(SDL_Event, bool*, bool*, int*);

    protected:
        SDL_Event e;
};

#endif // MAINMENU_H
