#ifndef ROUTE_H
#define ROUTE_H
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "Ambulance.h"
#include "LinkedList.h"
#include "TrafficSignal.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Node.h"

using namespace std;

enum _DIRECTION {_UP, _DOWN, _LEFT, _RIGHT};

class Route
{
    public:
        Route(int direction);
        ~Route();
        int get_route();
        LinkedList getList();
        void set_route(int);
        void get_on_route(Mobile*);
        void move_all_cars();
        void move_signal();
        void TurnL();
        void render_all_cars(long int&, SDL_Renderer*, bool);
        bool check_collision(Node* headOfOther);
        Node* get_head();

    private:
        int direction;
        LinkedList list1;
};

#endif // ROUTE_H
