#include "Route.h"
#include"LinkedList.h"
#include"Mobile.h"
#include"LTexture.h"
#include<SDL.h>
#include<SDL_image.h>

Route::Route(int direction)
{
    this->direction = direction;
}

Route::~Route()
{

}

int Route::get_route()
{
    return 0;
}

void Route::set_route(int)
{

}

void Route::get_on_route(Mobile* mobile)
{
    list1.Enqueue(mobile);
}

void Route::render_all_cars(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    list1.Render(frame, gRenderer, debug);
}

void Route::move_all_cars()
{
    list1.Move();
}

void Route::move_signal()
{
    list1.linkedlist_move_signal();
}

void Route::TurnL()
{
    list1.TurnRouteDown();
}

bool Route::check_collision(Node* headOfOther)
{

    return list1.check_collision(headOfOther);
}

Node* Route::get_head()
{
    return list1.get_head();
}
