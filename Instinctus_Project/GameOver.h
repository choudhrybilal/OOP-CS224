#ifndef GameOver_H
#define GameOver_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Screen.h"
#include "Node.h"
#include "Character.h"
#include "Word.h"
#include "Button.h"
#include "LTexture.h"
#include "Point.h"

class GameOver : public Screen
{
    public:
        GameOver(LTexture*, LTexture*, int, int);
        GameOver();
        ~GameOver();
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void game_over_event(SDL_Event, bool*, bool*, int*);

    protected:
        Point p;
};

#endif // GameOver_H
