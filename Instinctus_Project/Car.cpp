#include"Car.h"
using namespace std;

Car::Car()
{

}

Car::~Car()
{
    cout<<"Car Deallocated"<<endl;
}

Car::Car(LTexture* image, float x, float y,double angle, string color, int direction):Mobile(image, x, y, angle, turning_direction)
{
    if (color == "ORANGE")
    {
        spriteClips.x = 100;
        spriteClips.y = 0;
        spriteClips.w = 50;
        spriteClips.h = 101;
    }
    else if (color == "YELLOW")
    {
        spriteClips.x = 0;
        spriteClips.y = 0;
        spriteClips.w = 50;
        spriteClips.h = 101;
    }
    else if (color == "BLUE")
    {
        spriteClips.x = 50;
        spriteClips.y = 0;
        spriteClips.w = 50;
        spriteClips.h = 101;
    }

    this->width = spriteClips.w;
    this->height = spriteClips.h;
    this->direction = this->angle;
    this->turning_direction = direction;
}

void Car::Move()
{
    x += 0.1;
}

void Car::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x- width/2 , y - height/2, &spriteClips, this->angle, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
