#include "MainMenu.h"
using namespace std;

MainMenu::MainMenu()
{
    text = "";
}

MainMenu::~MainMenu()
{

}

MainMenu::MainMenu(LTexture* image, LTexture* image1, int x, int y):Screen(image1, x, y)
{
    SpriteSheetDisplay = image;

    spriteClips.x =   0;
    spriteClips.y =   0;
    spriteClips.w = 600;
    spriteClips.h = 600;

    point.x = x;
    point.y = y;

    buttons = new Button[3];

    string arr[3];
    arr[0] = "START";
    arr[1] = "RESUME";
    arr[2] = "EXIT";

    for (int i = 0; i < 3; i++)
    {
        buttons[i]= Button(image1, 260, 200 + i*100, arr[i]);
    }
}

void MainMenu::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    SpriteSheetDisplay->Render( 0, 0, &spriteClips, 0, NULL, SDL_FLIP_NONE, gRenderer );
    for (int i = 0; i < 3; i++)
    {
        buttons[i].Render(gRenderer, false);
    }
    if(debug == true)
    {
        SDL_Rect rect = { point.x - Screen_width/2, point.y - Screen_height/2, Screen_width, Screen_height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void MainMenu::handle_event(SDL_Event e, bool* mouse_click, bool* quit, int* cases)
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
                if (p.x > 180 && p.x < 440 && p.y > 200 && p.y <250)
                {
                    *mouse_click  = true;
                    *cases = 2;
                }

                else if (x > 130 && x < 470 && y > 300 && y <350)
                {
                    *mouse_click = true;
                    *cases = 4;
                    cout <<x<<" "<<y<<endl;
                }

                else if (x > 180 && x < 440 && y > 400 && y <450)
                {
                    *quit = true;
                    *mouse_click = true;
                }
            }
        }

        if (e.type == SDL_MOUSEBUTTONUP && *mouse_click == true)
        {
            *mouse_click = false;
        }
    }
}
