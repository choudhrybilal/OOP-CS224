#include"Ambulance.h"

using namespace std;

Ambulance::Ambulance()
{

}

Ambulance::~Ambulance()
{
    cout<<"Ambulance Deallocated"<<endl;
}

Ambulance::Ambulance(LTexture* image, float x, float y, double angle, int direction):Mobile(image, x, y, angle, turning_direction)
{
    //Frame 0
    spriteClips[ 0 ].x = 112;
    spriteClips[ 0 ].y = 6;
    spriteClips[ 0 ].w = 50;
    spriteClips[ 0 ].h = 108;

    //Frame 1
    spriteClips[ 1 ].x = 162;
    spriteClips[ 1 ].y = 6;
    spriteClips[ 1 ].w = 50;
    spriteClips[ 1 ].h = 108;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    health = new HealthBar(x, y);
    this->direction = this->angle;
    this->turning_direction = direction;
}

void Ambulance::Move()
{
    x += 0.01;
}

void Ambulance::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % LIGHT_FRAMES ], this->angle, NULL, SDL_FLIP_NONE, gRenderer );
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xAA, 0x00);
    health->set_point(x, y);
    health->Draw( gRenderer );
    if (frame % 500 == 0)
    {
        health->decrease_health();
    }
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
