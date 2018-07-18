#pragma once
#include "Mobile.h"
#include "HealthBar.h"
#include "Screen.h"
#include "LinkedList.h"
#include "Route.h"
#include <cstdlib>

class Ambulance:public Mobile
{
public:
    Ambulance();
    ~Ambulance();
    Ambulance(LTexture* image, float x, float y, double angle, int direction_ambulance);
    void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
protected:
    enum ANIMATION_FRAMES {LIGHT_FRAMES = 2};
    SDL_Rect spriteClips[ LIGHT_FRAMES ];
    HealthBar* health;
};
