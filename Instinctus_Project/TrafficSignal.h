#ifndef TRAFFICSIGNAL_H
#define TRAFFICSIGNAL_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "LinkedList.h"
#include "LTexture.h"

enum ANIMATION {STOP, GO};

class TrafficSignal
{
    public:
        TrafficSignal();
        ~TrafficSignal();
        void switch_signal(int);
        TrafficSignal(LTexture* image, float x, float y, double angle);
        void Render(long int& frame, SDL_Renderer* gRenderer,bool, bool debug);
        int state;

    private:
        float x;
        float y;
        int width;
        int height;
        double angle = 0;

        SDL_Rect spriteClips[2];
        LTexture* spriteSheetTexture;
};

#endif // TRAFFICSIGNAL_H
