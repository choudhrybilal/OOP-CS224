#ifndef SplashScreen_H
#define SplashScreen_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Screen.h"

class SplashScreen : public Screen
{
    public:
        SplashScreen(LTexture* image1, int, int);
        SplashScreen();
        ~SplashScreen();
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);

};

#endif // SplashScreen_H
