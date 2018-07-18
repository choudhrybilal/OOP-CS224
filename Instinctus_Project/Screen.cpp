#include "Screen.h"


Screen::Screen()
{
    Screen_height = 600;
    Screen_width = 600;
    buttons = NULL;
}

Screen::Screen(LTexture* image, int x, int y)
{
    SpriteSheetDisplay = image;

    spriteClips.x =   0;
    spriteClips.y =   0;
    spriteClips.w = 600;
    spriteClips.h = 600;

    point.x = x;
    point.y = y;
}

Screen::~Screen()
{
    SpriteSheetDisplay = NULL;
}

void handleEvent(SDL_Event e, bool* mouseClicked, bool* quit)
{

}
