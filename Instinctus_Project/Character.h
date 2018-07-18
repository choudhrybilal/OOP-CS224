#pragma once
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include"LTexture.h"
#include <iostream>
#include"Point.h"

class Character
{
public:
    Character();
    Character(LTexture* image, float x, float y, char c);
    ~Character();
    void Render(SDL_Renderer* gRenderer, bool debug);
    void SetPosition(Point&);
    void SetPosition(float, float);
    int GetFrameWidth();
    int GetFrameHeight();

private:
    Point position;
    int character_value;
    int width;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;
};

