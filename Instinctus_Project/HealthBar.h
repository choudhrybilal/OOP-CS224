#pragma once
#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include"LTexture.h"
#include<SDL.h>
#include"SDL.h"
#include"Point.h"
#include<SDL_image.h>
#include"Point.h"

class HealthBar
{
    public:
        HealthBar(float, float);
        void Draw(SDL_Renderer* gRenderer);
        ~HealthBar();
        void set_point(float x, float y);
        void decrease_health();

    protected:
        Point p;
        int health;
        SDL_Rect rect_outline;
        SDL_Rect fill_rect;

    private:
};

#endif // HEALTHBAR_H
