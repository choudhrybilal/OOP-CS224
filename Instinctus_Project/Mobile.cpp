#include "Mobile.h"
#include <math.h>

Mobile::Mobile()
{

}

Mobile::Mobile(LTexture* image, float x, float y, double angle, int turning_direction)
{
    spriteSheetTexture = image;

    this->x = x;
    this->y = y;
    this->angle = angle;
    this->alive = true;
    this->direction = this->angle;
    this->turning_direction = turning_direction;
    crossed_signal = false;
}

Mobile::~Mobile()
{
    spriteSheetTexture = NULL;
}

SDL_Rect Mobile::Get_box()
{
    return bounding_box;
}

void Mobile::TurnRouteDown()
{
    if (direction == 0) // From down side route
    {
        if (turning_direction == LEFT)
        {
            if (y < 480)
            {
                if (angle != -90)
                {
                    x += cos((angle--)*M_PI/180 )*0.1;
                    y += sin((angle--)*M_PI/180 )*0.5;
                    x -= 0.1;
                    y -= 2;
                }
                x-=0.1;
            }
        }

        if (turning_direction == RIGHT)
        {
            if (y < 260)
            {
                if (angle != 90)
                {
                    x += cos((angle++)*M_PI/180 )*0.1;
                    y += sin((angle++)*M_PI/180 )*0.5;
                    x += 0.5;
                    y -= 1;
                }
                x+=0.1;
            }
        }

        if (turning_direction == UP)
        {
            y -= 0.1;
        }
    }

    else if (direction == 180) // From up side route
    {
        if (turning_direction == RIGHT)
        {
            if (y > 210)
            {
                if (angle != 90)
                {
                    x += cos((angle--)*M_PI/180 )*0.1;
                    y += sin((angle--)*M_PI/180 )*0.5;
                    x += 0.1;
                    y += 1;
                }
                x+=0.1;
            }
        }
        if (turning_direction == LEFT)
        {
            if (y > 350)
            {
                if (angle != 270)
                {
                    x -= cos((angle++)*M_PI/180 )*0.1;
                    y += sin((angle++)*M_PI/180 )*0.15;
                    x -= 1;
                    y += 1;
                }
                x-= 0.1;
            }
        }
        if (turning_direction == DOWN)
        {
            y += 0.1;
        }
    }

    else if (direction == 90) // From left side route
    {
        if (turning_direction == UP)
        {
            if (x > 200)
            {
                if (angle != 0)
                {
                    x += cos((angle--)*M_PI/180 )*0.1;
                    y += sin((angle--)*M_PI/180 )*0.15;
                    x += 1;
                    y -= 1;
                }
                y-=0.1;
            }
        }
        if (turning_direction == DOWN)
        {
            if (x > 350)
            {
                if (angle != 180)
                {
                    x += cos((angle++)*M_PI/180 )*0.1;
                    y += sin((angle++)*M_PI/180 )*0.15;
                    x += 1;
                    y += 1;
                }
                y+=0.1;
            }
        }

        if (turning_direction == RIGHT)
        {
            x += 0.1;
        }
    }

    else if (direction == -90) // From right side route
    {
        if (turning_direction == DOWN)
        {
            if (x < 400)
            {
                if (angle != -180)
                {
                    x += cos((angle--)*M_PI/180 )*0.1;
                    y += sin((angle--)*M_PI/180 )*0.15;
                    x -= 1;
                    y += 1;
                }
                y+=0.1;
            }
        }

        else if (turning_direction == UP)
        {
            if (x < 280)
            {
                if (angle != 0)
                {
                    x += cos((angle++)*M_PI/180 )*0.1;
                    y += sin((angle++)*M_PI/180 )*0.15;
                    x -= 1;
                    y -= 1;
                }
                y-=0.1;

            }
        }
    }
}

void Mobile::Move()
{
    if (angle == 0)
    {
        y = y - 0.05;
        if(y < 440)
            crossed_signal = true;
    }
    if (angle == 180)
    {
        y = y + 0.05;
        if(y > 155)
        {
            crossed_signal = true;
        }
    }
    if (angle == 90)
    {

        x = x + 0.05;
        if(x > 172)
        {
            crossed_signal = true;
        }
    }
    if (angle == -90)
    {

        x = x - 0.05;
        if(x < 450)
        {
            crossed_signal = true;
        }
    }
    TurnRouteDown();
    OutOfScreen();
}

int Mobile::GetWidth()
{
    return width;
}

int Mobile::GetHeight()
{
    return height;
}

float Mobile::GetX()
{
    return x;
}
float Mobile::GetY()
{
    return y;
}

void Mobile::OutOfScreen()
{
    if (x > 600 || y > 600 || x < -400 || y < -400)
    {
        this->alive = false;
    }
}
