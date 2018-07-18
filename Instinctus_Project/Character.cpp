#include"Character.h"
#include<iostream>

using namespace std;

Character::Character()
{
    width = 44;
    height = 48;
    character_value = 0;
}

Character::Character(LTexture* image, float x, float y, char value)
{
    spriteSheetTexture = image;
    character_value = 0;

    //Frame 0
    //char value;
    spriteClips.w = 44;
    spriteClips.h = 48;

    int upper_threshold = 65;
    int lower_threshold = 97;
    int integer_threshold = 49;

    //Decoding the ascii value of the passed character
    int upper_total = value - upper_threshold;      //Doing calculation for upper case letters
    int lower_total = value - lower_threshold;      //Doing calculation for lower case letters
    int int_total = value - integer_threshold;      //Doing calculation for integers letters

    if (value >= 65 && value <= 75) //Various if, else condition are being used to access characters from different x and y coordinates of the image
    {
        spriteClips.x = upper_total*44;
        spriteClips.y = 0;
    }
    else if (value >= 76 && value <= 86 )
    {
        spriteClips.x = (upper_total-11)*44;
        spriteClips.y = 48;
    }
    else if (value >= 87 && value <= 90 )
    {
        spriteClips.x = (upper_total-22)*44;
        spriteClips.y = 96;
    }
    else if (value >= 97 && value <= 103 )
    {
        spriteClips.x = (lower_total)*44 + 176;
        spriteClips.y = 96;
    }

    else if (value >= 104 && value <= 114)
    {
        spriteClips.x = (lower_total-7)*44;
        spriteClips.y = 144;
    }
    else if (value >= 115 && value <= 122)
    {
        spriteClips.x = (lower_total-18)*44;
        spriteClips.y = 192;
    }
    else if (value >= 48 && value < 51)
    {
        spriteClips.x = (int_total+1)*44 + 352;
        spriteClips.y = 192;
    }
    else if (value >= 51 && value <= 57)
    {
        spriteClips.x = (int_total-2)*44;
        spriteClips.y = 238;
    }
    else if (value == 46)
    {
        spriteClips.x = 44*7;
        spriteClips.y = 238;
    }
    else if (value == 44)
    {
        spriteClips.x = 44*8;
        spriteClips.y = 238;
    }

    else if (value == 59)
    {
        spriteClips.x = 44*9;
        spriteClips.y = 238;
    }
    else if (value == 58)
    {
        spriteClips.x = 44*10;
        spriteClips.y = 238;
    }
    position.x = x;
    position.y = y;
    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

Character::~Character()
{
    char n = character_value + 97;
}

void Character::Render(SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void Character::SetPosition(Point& position)
{
    this->position.x = position.x - width/2;
    this->position.y = position.y - height/2;
}

void Character::SetPosition(float x, float y)
{
    this->position.x = x - width/2;
    this->position.y = y - height/2;
}

int Character::GetFrameWidth()
{
    return width;
}
int Character::GetFrameHeight()
{
    return height;
}
