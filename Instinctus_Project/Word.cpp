#include "Word.h"
#include <iostream>

using namespace std;

Word::Word()
{
    position.x = 0;
    position.y = 0;
}

Word::Word(LTexture* image, float x, float y, string word_pass)
{
    this->SetChar(word_pass);
    spriteSheetTexture = image;
    position.x = x;
    position.y = y;
    int length = word_pass.length();
    char_pointer= new Character[length];  //Dynamic array to store the word of any length
    int axis_shift = -length/2;           //To start from the mid character

    for (int i=0; i< length; i++)         //Assigning each character of the passed argument in the pointer array with appropriate shift (44/character)
    {
        char_pointer[i] = Character(image, x + (axis_shift * 44), y, word_pass[i]);
        axis_shift++;
    }
}

void Word::ChangeText(string word_pass)
{
    this->SetChar(word_pass);
    int length = word_pass.length();
    delete char_pointer;
    char_pointer= new Character[length];  //Dynamic array to store the word of any length
    int axis_shift = -length/2;            //To start from the mid character

    for (int i=0; i< length; i++)           //Assigning each character of the passed argument in the pointer array with appropriate shift (44/character)
    {
        char_pointer[i] = Character(spriteSheetTexture, position.x + (axis_shift * 44), position.y, word_pass[i]);
        axis_shift++;
    }
}

Word::~Word()
{
    spriteSheetTexture = NULL;
}

void Word::Render(SDL_Renderer* gRenderer, bool debug)
{
    for (int i=0; i< characters.length(); i++)
    {
        char_pointer[i].Render(gRenderer, debug);           //Rendering each character in a loop
    }
}

void Word::SetPosition(Point& position)
{
    this->position.x = position.x - width/2;
    this->position.y = position.y - height/2;
}

void Word::SetPosition(float x, float y)
{
    this->position.x = x - width/2;
    this->position.y = y - height/2;
}

void Word::SetChar(string word)
{
    characters = word;
}

int Word::GetFrameWidth()
{
    return width;
}

int Word::GetFrameHeight()
{
    return height;
}


