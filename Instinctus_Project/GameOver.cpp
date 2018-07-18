#include "GameOver.h"
using namespace std;

GameOver::GameOver()
{

}

GameOver::~GameOver()
{

}

GameOver::GameOver(LTexture* image, LTexture* image1, int x, int y):Screen(image, x, y)
{
    SpriteSheetDisplay = image;

    spriteClips.x = 0;
    spriteClips.y = 0;
    spriteClips.w = 600;
    spriteClips.h = 600;

    gameover_buttons = new Button[3];

    string options_array[2];
    options_array[0] = "MENU";
    options_array[1] = "QUIT";

    for (int i = 0; i < 2; i++)
    {
        gameover_buttons[i]= Button(image1, 250, 250 + i*100, options_array[i]);
    }

    point.x = x;
    point.y = y;
}

void GameOver::game_over_event(SDL_Event e, bool* mouse_click, bool* quit, int* switch_case)
{
    //If mouse event happened
    if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
    {
        if (e.type == SDL_MOUSEBUTTONDOWN && *mouse_click == false)
        {
            Point p;
            int x,y;
            SDL_GetMouseState(&x,&y);
            p.x = x;
            p.y = y;

            if (e.button.button == SDL_BUTTON_LEFT)
            {
                SDL_GetMouseState(&x,&y);
                if (p.x > 160 && p.x < 430 && p.y > 250 && p.y <305)
                {
                    *mouse_click  = true;
                    *switch_case = 1;
                }

                if (p.x > 160 && p.x < 430 && p.y > 350 && p.y < 405)
                {
                    *mouse_click  = true;
                    *quit = true;
                }
            }
        }

        if (e.type == SDL_MOUSEBUTTONUP && *mouse_click == true)
        {
            *mouse_click = false;
        }
    }
}

void GameOver::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    SpriteSheetDisplay->Render( 0, 0, &spriteClips, 0, NULL, SDL_FLIP_NONE, gRenderer );
    for (int i = 0; i < 2; i++)
    {
        gameover_buttons[i].Render(gRenderer, false);
    }
    if(debug == true)
    {
        SDL_Rect rect = { point.x - Screen_width/2, point.y - Screen_height/2, Screen_width, Screen_height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
