#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include "Character.h"
#include "string"

using namespace std;

class Word
{
public:
    Word();
    Word(LTexture* image, float x, float y, string word_pass);
    ~Word();
    void SetChar(string word);
    void Render(SDL_Renderer* gRenderer, bool debug);
    void SetPosition(Point&);
    void SetPosition(float, float);
    int GetFrameWidth();
    int GetFrameHeight();
    void ChangeText(string);

private:
    Point position;
    string characters;
    int word_length;
    Character* char_pointer;
    int width;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;

};

