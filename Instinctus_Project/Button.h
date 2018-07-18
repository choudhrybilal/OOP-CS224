#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "LTexture.h"
#include "string"
#include "Point.h"
#include "Character.h"
#include "Word.h"
#include "ImageLoad.h"
using namespace std;

class Button: public Word
{
public:
    Button();
    ~Button();
    Button(LTexture* image, float x, float y, string word_pass);
    void Render(SDL_Renderer* gRenderer, bool debug);
    int get_frame_height();
    int get_frame_width();

private:
    int word_len;
    Point position;
    Word* word_object;
    int width;
    int height;
    SDL_Rect LeftButton;
    SDL_Rect RightButton;
    SDL_Rect CenterButton;

    LTexture* left_button;
    LTexture* right_button;
    LTexture* center_button;
    LTexture* spriteSheetTexture;

};

#endif // BUTTON_H
