#pragma once
#include"Mobile.h"

class Car:public Mobile
{
public:
    Car(LTexture* image, float x, float y,double angle, string color, int direction);
    Car();
    ~Car();
    void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
private:
    SDL_Rect spriteClips;
};
