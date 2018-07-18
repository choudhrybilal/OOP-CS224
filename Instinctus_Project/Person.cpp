#include"Person.h"
using namespace std;

Person::Person()
{

}

Person::~Person()
{
    cout<<"Person Deallocated"<<endl;
}

Person::Person(LTexture* image, float x, float y,double angle, string color,int direction):Mobile(image, x, y, angle, turning_direction)
{
    if (color == "BLUE")
    {
        spriteClips.x = 127;
        spriteClips.y = 137;
        spriteClips.w = 33;
        spriteClips.h = 23;
    }
    else if (color == "RED")
    {
        spriteClips.x = 93;
        spriteClips.y = 137;
        spriteClips.w = 33;
        spriteClips.h = 23;
    }
    else if (color == "GREEN")
    {
        spriteClips.x = 93;
        spriteClips.y = 113;
        spriteClips.w = 33;
        spriteClips.h = 23;
    }

    this->width = spriteClips.w;
    this->height = spriteClips.h;

    this->direction = this->angle;
    this->turning_direction = direction;
}

void Person::Move()
{
    x +=0.01;
}

void Person::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x- width/2 , y - height/2, &spriteClips, this->angle, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
