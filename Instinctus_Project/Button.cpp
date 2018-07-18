#include "Button.h"

Button::Button() //Constructor
{
    word_len = 0;
}

Button::~Button() //Destructor
{
    spriteSheetTexture = NULL;
}

Button::Button(LTexture* image, float x, float y, string word_pass) //Overloaded constructor
{
    left_button = image;
    right_button = image;
    center_button = image;

    word_len = word_pass.length();
    word_object = new Word(image, x + 65, y + 30, word_pass);

    LeftButton.x = 0;
    LeftButton.y = 446;
    LeftButton.w = 51;
    LeftButton.h = 51;

    //Frame 1 Middle button part
    CenterButton.x = 51;
    CenterButton.y = 446;
    CenterButton.w = 51;
    CenterButton.h = 51;

    //Frame 2 Right button part
    RightButton.x = 102;
    RightButton.y = 446;
    RightButton.w = 51;
    RightButton.h = 51;

    position.x = x;
    position.y = y;

    this->width = CenterButton.w;
    this->height = CenterButton.h;

}
void Button::Render(SDL_Renderer* gRenderer, bool debug) //Rendering right, left and center button and designated positions
{
    left_button->Render(position.x - ((word_len / 2) * 44), position.y, &LeftButton, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    right_button->Render(position.x + (44 * (word_len / 2)) + 30, position.y, &RightButton, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    for(int j = -3 + 1; j < 3 + 1; j++)
    {
        center_button->Render(position.x + (j * 44), position.y, &CenterButton, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    word_object->Render(gRenderer, debug);
}

int Button::get_frame_height()
{
    return height;
}
int Button::get_frame_width()
{
    return width;
}
