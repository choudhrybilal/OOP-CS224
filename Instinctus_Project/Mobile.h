#pragma once
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include"LTexture.h"


using namespace std;

enum DIRECTION {UP, DOWN, LEFT, RIGHT};

class Mobile
{
    public:
        Mobile();
        virtual ~Mobile();
        Mobile(LTexture* image, float x, float y, double angle, int turning_direction);
        int GetWidth();
        int GetHeight();
        float GetX();
        float GetY();
        double getAngle();
        void Move();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug) = 0;
        bool crossed_signal;
        bool alive;
        void TurnRouteDown();
        void OutOfScreen();
        int GetType();
        SDL_Rect Get_box();

    protected:
        float x;
        float y;
        int width;
        int height;
        double angle = 0;
        float a;
        int turning_direction;
        int direction;
        int car_turn_direction, direction_truck, direction_motorcycle, direction_ambulance;
        int type;
        SDL_Rect bounding_box;

        LTexture* spriteSheetTexture;

};



