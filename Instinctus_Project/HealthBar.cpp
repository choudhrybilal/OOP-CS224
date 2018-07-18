#include "HealthBar.h"
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_rect.h>

HealthBar::HealthBar(float x, float y)
{
    p.x = x;
    p.y  = y;
    health = 50;
    rect_outline = {p.x, p.y, 50, 10};
    fill_rect = {p.x, p.y, health, 10};
}

void HealthBar::decrease_health()
{
    if (health > 0)
    {
        health -= 1;
    }
}
void HealthBar::set_point(float x, float y)
{
    p.x = x;
    p.y = y;
    rect_outline = {p.x, p.y, 50, 10};
    fill_rect = {p.x, p.y, health, 10};
}
HealthBar::~HealthBar()
{

}

void HealthBar::Draw(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer,255, 0, 0, 255);
    SDL_RenderFillRect( gRenderer, &rect_outline );
    SDL_SetRenderDrawColor(gRenderer,0, 255, 0, 255);
    SDL_RenderFillRect( gRenderer, &fill_rect );
}
