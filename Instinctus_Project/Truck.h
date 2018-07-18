#pragma once
#include"Mobile.h"

class Truck:public Mobile
{
public:
    Truck();
    ~Truck();
    Truck(LTexture* image, float x, float y,double angle, string color, int direction_truck);
    void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
private:
    SDL_Rect spriteClips;
};
