#include"Truck.h"

using namespace std;

Truck::Truck()
{

}

Truck::~Truck()
{
    cout<<"Truck Deallocated"<<endl;
}

Truck::Truck(LTexture* image, float x, float y,double angle, string color, int direction):Mobile(image, x, y, angle, turning_direction)
{
    if (color == "ORANGE")
    {
        spriteClips.x = 0;
        spriteClips.y = 0;
        spriteClips.w = 65;
        spriteClips.h = 118;
    }
    else if (color == "GREEN")
    {
        spriteClips.x = 68;
        spriteClips.y = 5;
        spriteClips.w = 46;
        spriteClips.h = 110;
    }

    this->width = spriteClips.w;
    this->height = spriteClips.h;
    this->direction = this->angle;
    this->turning_direction = direction;
}

void Truck::Move()
{
    x += 0.1;
}

void Truck::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x- width/2 , y - height/2, &spriteClips, this->angle, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
