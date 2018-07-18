#include "TrafficSignal.h"

using namespace std;

TrafficSignal::TrafficSignal()
{
}

TrafficSignal::~TrafficSignal()
{
}

TrafficSignal::TrafficSignal(LTexture* image, float x, float y, double angle)
{
    spriteSheetTexture = image;

    //RED -----> [STOP]
    spriteClips[STOP].x = 4;
    spriteClips[STOP].y = 4;
    spriteClips[STOP].w = 20;
    spriteClips[STOP].h = 40;

    //GREEN -----> [GO]
    spriteClips[GO].x = 33;
    spriteClips[GO].y = 23;
    spriteClips[GO].w = 20;
    spriteClips[GO].h = 39;

    state = STOP;
    this->angle = angle;

    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;
    this->x = x;
    this->y = y;
}

void TrafficSignal::Render(long int& frame, SDL_Renderer* gRenderer, bool move_enable ,bool debug)
{
    if(move_enable)
        state = GO;
    else
        state = STOP;

    spriteSheetTexture->Render( x- width/2 , y - height/2, &spriteClips[state], this->angle, NULL, SDL_FLIP_NONE, gRenderer );

    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
void TrafficSignal::switch_signal(int state)
{
    this->state = state;
}
