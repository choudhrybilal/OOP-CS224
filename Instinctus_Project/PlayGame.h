#pragma once
#include "Screen.h"
#include "Car.h"
#include "Point.h"
#include "Mobile.h"
#include "Route.h"
#include "LinkedList.h"
#include <cstdlib>
#include "Motorcycle.h"
#include "Truck.h"
#include "Ambulance.h"
#include "TrafficSignal.h"
#include "Person.h"
#include "Character.h"
#include "Word.h"

class PlayGame: public Screen
{
public:
    PlayGame();
    PlayGame(LTexture*, LTexture*, int, int);
    void Update_signal( bool move_from_up,bool move_from_left,bool move_from_right,bool move_from_down);
    float getx();
    float gety();
    void make_signal(LTexture* signal_image);
    void Render(long int&, SDL_Renderer*, bool);
    void make_new_mobile(int*, LTexture* car_image, LTexture* truck_image, LTexture* motorcycle_image, LTexture* ambulance_image, LTexture* person_image, long int& frame);
    string int_to_string(int);
    void set_score();
    int get_score();
    ~PlayGame();
    void generate_cars(LTexture &gSpriteSheetCar,long int& frame);
    bool colliding(Route*, Route*,Route*,Route*);
    void save_game(ofstream& readfile);
    void load_game(ifstream& readfile);

protected:
    Mobile* car = NULL;
    Mobile* ambulance = NULL;
    Mobile* person = NULL;
    Mobile* truck = NULL;
    Mobile* motorcycle = NULL;

    Route* route_up;
    Route* route_left;
    Route* route_right;
    Route* route_down;

    Word* word;
    float x;
    float y;
    bool move_from_up ;
    bool move_from_left ;
    bool move_from_right ;
    bool move_from_down ;

    //TRAFFIC SIGNAL LIGHTS
    TrafficSignal* lights_route_up;
    TrafficSignal* lights_route_down;
    TrafficSignal* lights_route_left;
    TrafficSignal* lights_route_right;

    int score;
    bool game_end;

};
