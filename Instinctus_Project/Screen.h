#pragma once
#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include"Mobile.h"
#include "Point.h"
#include <stdio.h>
#include "Button.h"
#include "Word.h"
#include "Character.h"
#include <iostream>
#include "ImageLoad.h"
class Screen
{
public:
    Screen();
    ~Screen();
    Screen(LTexture* image, int x, int y);
    void handleEvent(SDL_Event e, bool* mouseClicked, bool* quit);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug) = 0;

protected:
    LTexture* SpriteSheetDisplay;
    SDL_Rect spriteClips;
    Point point;
    int Screen_width;
    int Screen_height;
    Button* buttons;
    Button* gameover_buttons;

};
