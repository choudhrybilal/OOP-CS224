#pragma once
#include"Mobile.h"

class Motorcycle:public Mobile
{
public:
    Motorcycle();
    ~Motorcycle();
    Motorcycle(LTexture* image, float x, float y,double angle, string color, int direction_motorcycle);
    void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
private:
    SDL_Rect spriteClips;
};
