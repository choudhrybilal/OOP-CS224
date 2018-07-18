#include "SplashScreen.h"

using namespace std;

SplashScreen::SplashScreen()
{

}

SplashScreen::~SplashScreen()
{

}

SplashScreen::SplashScreen(LTexture* image, int x, int y):Screen(image, x, y)
{
    SpriteSheetDisplay = image;

    spriteClips.x = 0;
    spriteClips.y = 0;
    spriteClips.w = 600;
    spriteClips.h = 600;

    point.x = x;
    point.y = y;

}

void SplashScreen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    SpriteSheetDisplay->Render( 0, 0, &spriteClips, 0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { point.x - Screen_width/2, point.y - Screen_height/2, Screen_width, Screen_height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
