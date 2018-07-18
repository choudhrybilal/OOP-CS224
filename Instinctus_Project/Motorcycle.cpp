#include"Motorcycle.h"

using namespace std;

Motorcycle::Motorcycle()
{

}

Motorcycle::~Motorcycle()
{
    cout<<"Motorcycle Deallocated"<<endl;
}

Motorcycle::Motorcycle(LTexture* image, float x, float y,double angle, string color, int direction):Mobile(image, x, y, angle, turning_direction)
{
    if (color == "YELLOW")
    {
        spriteClips.x = 157;
        spriteClips.y = 94;
        spriteClips.w = 32;
        spriteClips.h = 73;
    }
    else if (color == "BLUE")
    {
        spriteClips.x = 363;
        spriteClips.y = 95;
        spriteClips.w = 32;
        spriteClips.h = 73;
    }
    else if (color == "RED")
    {
        spriteClips.x = 207;
        spriteClips.y = 286;
        spriteClips.w = 32;
        spriteClips.h = 73;
    }

    this->width = spriteClips.w;
    this->height = spriteClips.h;
    this->direction = this->angle;
    this->turning_direction = direction;
}

void Motorcycle::Move()
{
    x += 0.1;
}

void Motorcycle::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x- width/2 , y - height/2, &spriteClips, this->angle, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
