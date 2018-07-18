#pragma once
#include"Mobile.h"

class Person:public Mobile
{
public:
    Person(LTexture* image, float x, float y,double angle, string color,int);
    Person();
    ~Person();
    void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
private:
    int priority;
    SDL_Rect spriteClips;
};
