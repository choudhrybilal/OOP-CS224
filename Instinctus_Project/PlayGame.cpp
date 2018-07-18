#include "PlayGame.h"
#include<sstream>
#include "LTexture.h"
#include "ImageLoad.h"
#include <fstream>
using namespace std;

PlayGame::PlayGame()
{

}

PlayGame::~PlayGame()
{
    delete route_up;
    delete route_down;
    delete route_left;
    delete route_right;
    delete lights_route_up;
    delete lights_route_down;
    delete lights_route_left;
    delete lights_route_right;
}

PlayGame::PlayGame(LTexture* image, LTexture* fontimage, int x, int y):Screen(image, x, y)
{
    lights_route_up = NULL;
    lights_route_left = NULL;
    lights_route_down = NULL;
    lights_route_right = NULL;
    route_up = new Route(_UP);
    route_left = new Route(_LEFT);
    route_right = new Route(_RIGHT);
    route_down = new Route(_DOWN);
    move_from_up = true;
    move_from_left = true;
    move_from_right = true;
    move_from_down = true;

    word = new Word(fontimage, 140, 135, "5");
    SpriteSheetDisplay = image;

    spriteClips.x =   0;
    spriteClips.y =   0;
    spriteClips.w = 600;
    spriteClips.h = 600;

    point.x = x;
    point.y = y;

    score = 5;
    game_end = false;
}

void PlayGame::Update_signal( bool move_from_up,bool move_from_left,bool move_from_right,bool move_from_down)
{
    this->move_from_down = move_from_down;
    this->move_from_left = move_from_left;
    this->move_from_right = move_from_right;
    this->move_from_up = move_from_up;
}


void PlayGame::make_new_mobile(int* switch_case, LTexture* car_image, LTexture* truck_image, LTexture* motorcycle_image, LTexture* ambulance_image, LTexture* person_image, long int& frame)
{
    // CARS
    Mobile* car = NULL;
    int random_x_car = 0;
    int random_y_car = 0;
    string random_color_car = "";
    int random_colorVal_car = 0;
    int car_turn_direction;

    // -----> GENERATING CARS
    if(frame%7000 == 0)
    {
        // -----> Generating CARS
        for (int i = 0; i < 1; i++) //Cars from up route
        {
            int car_from_up = rand() % 3;
            if(car_from_up != 2 && move_from_up)
            {
                random_x_car = rand() % 70 + 350;
                random_colorVal_car = rand() % 3;
                car_turn_direction = rand() % 3;
                if (random_colorVal_car == 0)
                {
                    random_color_car = "YELLOW";
                }
                if (random_colorVal_car == 1)
                {
                    random_color_car = "BLUE";
                }
                if (random_colorVal_car == 2)
                {
                    random_color_car = "ORANGE";
                }
                if (car_turn_direction == 0)
                {
                    car = new Car(car_image, random_x_car, 700, 180, random_color_car, DOWN);
                }
                if (car_turn_direction == 1)
                {
                    car = new Car(car_image, random_x_car, 700, 180, random_color_car, LEFT);
                }
                if (car_turn_direction == 2)
                {
                    car = new Car(car_image, random_x_car, 700, 180, random_color_car, RIGHT);
                }
                route_up->get_on_route(car);
            }
        }

        for (int i = 0; i < 1; i++) //Cars from left route
        {
            int car_from_left = rand() % 4;
            if(car_from_left<2 && move_from_left)
            {
                random_y_car = rand()% 70 + 210;
                random_colorVal_car = rand() % 3;
                car_turn_direction = rand() % 3;
                if (random_colorVal_car == 0)
                {
                    random_color_car = "YELLOW";
                }
                if (random_colorVal_car == 1)
                {
                    random_color_car = "BLUE";
                }
                if (random_colorVal_car == 2)
                {
                    random_color_car = "ORANGE";
                }
                if (car_turn_direction == 0)
                {
                    car = new Car(car_image, -100, random_y_car, 90, random_color_car, UP);
                }
                if (car_turn_direction == 1)
                {
                    car = new Car(car_image, -100, random_y_car, 90, random_color_car, DOWN);
                }
                if (car_turn_direction == 2)
                {
                    car = new Car(car_image, -100, random_y_car, 90, random_color_car, RIGHT);
                }
                route_left->get_on_route(car);
            }
        }

        for (int i = 0; i < 1; i++) //Cars from right route
        {
            int car_from_right = rand() % 4;
            if(car_from_right < 3 && move_from_right)
            {
                random_y_car = rand()% 70 + 350;
                random_colorVal_car = rand() % 3;
                car_turn_direction = rand() % 3;
                if (random_colorVal_car == 0)
                {
                    random_color_car = "YELLOW";
                }
                if (random_colorVal_car == 1)
                {
                    random_color_car = "BLUE";
                }
                if (random_colorVal_car == 2)
                {
                    random_color_car = "ORANGE";
                }
                if (car_turn_direction == 0)
                {
                    car = new Car(car_image, 700, random_y_car, -90, random_color_car, UP);
                }
                if (car_turn_direction == 1)
                {
                    car = new Car(car_image, 700, random_y_car, -90, random_color_car, DOWN);
                }
                if (car_turn_direction == 2)
                {
                    car = new Car(car_image, 700, random_y_car, -90, random_color_car, LEFT);
                }
                route_right->get_on_route(car);
            }
        }

        for (int i = 0; i < 1; i++) //Cars from down route
        {
            int car_from_down = rand() % 4;
            if(car_from_down < 3 && move_from_down)
            {
                random_x_car = rand()% 70 + 210;
                random_colorVal_car = rand() % 3;
                car_turn_direction = rand() % 3;
                if (random_colorVal_car == 0)
                {
                    random_color_car = "YELLOW";
                }
                if (random_colorVal_car == 1)
                {
                    random_color_car = "BLUE";
                }
                if (random_colorVal_car == 2)
                {
                    random_color_car = "ORANGE";
                }
                if (car_turn_direction == 0)
                {
                    car = new Car(car_image, random_x_car, 700, 0, random_color_car, LEFT);
                }
                if (car_turn_direction == 1)
                {
                    car = new Car(car_image, random_x_car, 700, 0, random_color_car, UP);
                }
                if (car_turn_direction == 2)
                {
                    car = new Car(car_image, random_x_car, 700, 0, random_color_car, RIGHT);
                }
                route_down->get_on_route(car);
            }
        }
    }

    // TRUCKS
    Mobile* truck = NULL;
    int random_x_truck = 0;
    int random_y_truck = 0;
    string random_color_truck = "";
    int random_colorVal_Truck = 0;
    int truck_turn_direction;

    // -----> Generating Trucks
    if(frame%7000 == 2000)
    {
        for (int i = 0; i < 1; i++) //Trucks from up route
        {
            int truck_from_up = rand() % 4;
            if(truck_from_up < 2  && move_from_up)
            {
                random_x_truck = rand() % 40 + 360;
                random_colorVal_Truck = rand() % 3;
                truck_turn_direction = rand() % 3;
                if (random_colorVal_Truck == 0)
                {
                    random_color_truck = "ORANGE";
                }
                if (random_colorVal_Truck == 1)
                {
                    random_color_truck = "GREEN";
                }
                if (truck_turn_direction == 0)
                {
                    truck = new Truck(truck_image, random_x_truck, -200, 180, random_color_truck, DOWN);
                }
                if (truck_turn_direction == 1)
                {
                    truck = new Truck(truck_image, random_x_truck, -200, 180, random_color_truck, LEFT);
                }
                if (truck_turn_direction == 2)
                {
                    truck = new Truck(truck_image, random_x_truck, -200, 180, random_color_truck, RIGHT);
                }
                route_up->get_on_route(truck);
            }
        }

        for (int i = 0; i < 1; i++) //Trucks from left route
        {
            int truck_from_left = rand() % 4;
            if(truck_from_left < 2 && move_from_left)
            {
                random_y_truck = rand()% 40 + 210;
                random_colorVal_Truck = rand() % 3;
                truck_turn_direction = rand() % 3;
                if (random_colorVal_Truck == 0)
                {
                    random_color_truck = "ORANGE";
                }
                if (random_colorVal_Truck == 1)
                {
                    random_color_truck = "GREEN";
                }
                if (truck_turn_direction == 0)
                {
                    truck = new Truck(truck_image, -200, random_y_truck, 90, random_color_truck, UP);
                }
                if (truck_turn_direction == 1)
                {
                    truck = new Truck(truck_image, -200, random_y_truck, 90, random_color_truck, DOWN);
                }
                if (truck_turn_direction == 2)
                {
                    truck = new Truck(truck_image, -200, random_y_truck, 90, random_color_truck, RIGHT);
                }
                route_left->get_on_route(truck);
            }
        }

        for (int i = 0; i < 1; i++) //Trucks from right route
        {
            int truck_from_right = rand() % 4;
            if(truck_from_right < 2 && move_from_right)
            {
                random_y_truck = rand()% 40 + 350;
                random_colorVal_Truck = rand() % 3;
                truck_turn_direction = rand() % 3;
                if (random_colorVal_Truck == 0)
                {
                    random_color_truck = "ORANGE";
                }
                if (random_colorVal_Truck == 1)
                {
                    random_color_truck = "GREEN";
                }
                if (truck_turn_direction == 0)
                {
                    truck = new Truck(truck_image, 800, random_y_truck, -90, random_color_truck, UP);
                }
                if (truck_turn_direction == 1)
                {
                    truck = new Truck(truck_image, 800, random_y_truck, -90, random_color_truck, DOWN);
                }
                if (truck_turn_direction == 2)
                {
                    truck = new Truck(truck_image, 800, random_y_truck, -90, random_color_truck, LEFT);
                }
                route_right->get_on_route(truck);
            }
        }

        for (int i = 0; i < 1; i++) //Trucks from down route
        {
            int truck_from_down = rand() % 4;
            if(truck_from_down < 2 && move_from_down)
            {
                random_x_truck = rand()% 40 + 210;
                random_colorVal_Truck = rand() % 3;
                truck_turn_direction = rand() % 3;
                if (random_colorVal_Truck == 0)
                {
                    random_color_truck = "ORANGE";
                }
                if (random_colorVal_Truck == 1)
                {
                    random_color_truck = "GREEN";
                }
                if (truck_turn_direction == 0)
                {
                    truck = new Truck(truck_image, random_x_truck, 800, 0, random_color_truck, UP);
                }
                if (truck_turn_direction == 1)
                {
                    truck = new Truck(truck_image, random_x_truck, 800, 0, random_color_truck, LEFT);
                }
                if (truck_turn_direction == 2)
                {
                    truck = new Truck(truck_image, random_x_truck, 800, 0, random_color_truck, RIGHT);
                }
                route_down->get_on_route(truck);
            }
        }
    }

    // MOTORCYCLE
    Mobile* motorcycle = NULL;
    int random_x_motorcycle = 0;
    int random_y_motorcycle = 0;
    string random_color_motorcycle = "";
    int random_colorVal_motorcycle = 0;
    int motorcycle_turn_direction;

    // -----> Generating MOTORCYCLE
    if(frame%7000 == 3000)
    {
        for (int i = 0; i < 1; i++) //Motorcycles from up route
        {
            int motorcycle_from_up = rand() % 4;
            if(motorcycle_from_up < 3  && move_from_up)
            {
                random_x_motorcycle = rand() % 70 + 360;
                random_colorVal_motorcycle = rand() % 3;
                motorcycle_turn_direction = rand() % 3;
                if (random_colorVal_motorcycle == 0)
                {
                    random_color_motorcycle = "YELLOW";
                }
                if (random_colorVal_motorcycle == 1)
                {
                    random_color_motorcycle = "BLUE";
                }
                if (random_colorVal_motorcycle == 2)
                {
                    random_color_motorcycle = "RED";
                }
                if (motorcycle_turn_direction == 0)
                {
                    motorcycle = new Motorcycle(motorcycle_image, random_x_motorcycle, -300, 180, random_color_motorcycle, DOWN);
                }
                if (motorcycle_turn_direction == 1)
                {
                    motorcycle = new Motorcycle(motorcycle_image, random_x_motorcycle, -300, 180, random_color_motorcycle, LEFT);
                }
                if (motorcycle_turn_direction == 2)
                {
                    motorcycle = new Motorcycle(motorcycle_image, random_x_motorcycle, -300, 180, random_color_motorcycle, RIGHT);
                }
                route_up->get_on_route(motorcycle);
            }
        }

        for (int i = 0; i < 1; i++) //Motorcycles from left route
        {
            int motorcycle_from_left = rand() % 4;
            if(motorcycle_from_left < 3 && move_from_left)
            {
                random_y_motorcycle = rand()% 70 + 210;
                random_colorVal_motorcycle = rand() % 3;
                motorcycle_turn_direction = rand() % 3;
                if (random_colorVal_motorcycle == 0)
                {
                    random_color_motorcycle = "YELLOW";
                }
                if (random_colorVal_motorcycle == 1)
                {
                    random_color_motorcycle = "BLUE";
                }
                if (random_colorVal_motorcycle == 2)
                {
                    random_color_motorcycle = "RED";
                }
                if (motorcycle_turn_direction == 0)
                {
                    motorcycle = new Motorcycle(motorcycle_image, -300, random_y_motorcycle, 90, random_color_motorcycle, UP);
                }
                if (motorcycle_turn_direction == 1)
                {
                    motorcycle = new Motorcycle(motorcycle_image, -300, random_y_motorcycle, 90, random_color_motorcycle, DOWN);
                }
                if (motorcycle_turn_direction == 2)
                {
                    motorcycle = new Motorcycle(motorcycle_image, -300, random_y_motorcycle, 90, random_color_motorcycle, RIGHT);
                }
                route_left->get_on_route(motorcycle);
            }
        }

        for (int i = 0; i < 1; i++) //Motorcycles from right route
        {
            int motorcycle_from_right = rand() % 4;
            if(motorcycle_from_right < 3 && move_from_right)
            {
                random_y_motorcycle = rand()% 30 + 320;
                random_colorVal_motorcycle = rand() % 3;
                motorcycle_turn_direction = rand() % 3;
                if (random_colorVal_motorcycle == 0)
                {
                    random_color_motorcycle = "YELLOW";
                }
                if (random_colorVal_motorcycle == 1)
                {
                    random_color_motorcycle = "BLUE";
                }
                if (random_colorVal_motorcycle == 2)
                {
                    random_color_motorcycle = "RED";
                }
                if (motorcycle_turn_direction == 0)
                {
                    motorcycle = new Motorcycle(motorcycle_image, 900, random_y_motorcycle, -90, random_color_motorcycle, UP);
                }
                if (motorcycle_turn_direction == 1)
                {
                    motorcycle = new Motorcycle(motorcycle_image, 900, random_y_motorcycle, -90, random_color_motorcycle, DOWN);
                }
                if (motorcycle_turn_direction == 2)
                {
                    motorcycle = new Motorcycle(motorcycle_image, 900, random_y_motorcycle, -90, random_color_motorcycle, LEFT);
                }
                route_right->get_on_route(motorcycle);
            }
        }

        for (int i = 0; i < 1; i++) //Motorcycles from down route
        {
            int motorcycle_from_down = rand() % 4;
            if(motorcycle_from_down < 3 && move_from_down)
            {
                random_x_motorcycle = rand()% 50 + 235;
                random_colorVal_motorcycle = rand() % 3;
                motorcycle_turn_direction = rand() % 3;
                if (random_colorVal_motorcycle == 0)
                {
                    random_color_motorcycle = "YELLOW";
                }
                if (random_colorVal_motorcycle == 1)
                {
                    random_color_motorcycle = "BLUE";
                }
                if (random_colorVal_motorcycle == 2)
                {
                    random_color_motorcycle = "RED";
                }
                if (motorcycle_turn_direction == 0)
                {
                    motorcycle = new Motorcycle(motorcycle_image, random_x_motorcycle, 900, 0, random_color_motorcycle, UP);
                }
                if (motorcycle_turn_direction == 1)
                {
                    motorcycle = new Motorcycle(motorcycle_image, random_x_motorcycle, 900, 0, random_color_motorcycle, LEFT);
                }
                if (motorcycle_turn_direction == 2)
                {
                    motorcycle = new Motorcycle(motorcycle_image, random_x_motorcycle, 900, 0, random_color_motorcycle, RIGHT);
                }
                route_down->get_on_route(motorcycle);
            }
        }
    }

    // AMBULANCE
    Mobile* ambulance = NULL;
    int random_x_ambulance = 0;
    int random_y_ambulance = 0;
    int ambulance_turn_direction;

    // -----> Generating AMBULANCE
    if(frame%50000 == 19000)
    {
        for (int i = 0; i < 1; i++) //Ambulances from up route
        {
            int ambulance_from_up = rand() % 100;
            if(ambulance_from_up <= 30  && move_from_up)
            {
                random_x_ambulance = rand() % 10 + 350;
                ambulance_turn_direction = rand() % 3;
                if (ambulance_turn_direction == 0)
                {
                    ambulance = new Ambulance(ambulance_image, random_x_ambulance, -360, 180, DOWN);
                }
                if (ambulance_turn_direction == 1)
                {
                    ambulance = new Ambulance(ambulance_image, random_x_ambulance, -360, 180, LEFT);
                }
                if (ambulance_turn_direction == 2)
                {
                    ambulance = new Ambulance(ambulance_image, random_x_ambulance, -360, 180, RIGHT);
                }
                route_up->get_on_route(ambulance);
            }
        }

        for (int i = 0; i < 1; i++) //Ambulances from left route
        {
            int ambulance_from_left = rand() % 100;
            if(ambulance_from_left <= 30 && move_from_left)
            {
                random_y_ambulance = rand()% 10 + 235;
                ambulance_turn_direction = rand() % 3;
                if (ambulance_turn_direction == 0)
                {
                    ambulance = new Ambulance(ambulance_image, -360, random_y_ambulance, 90, UP);
                }
                if (ambulance_turn_direction == 1)
                {
                    ambulance = new Ambulance(ambulance_image, -360, random_y_ambulance, 90, DOWN);
                }
                if (ambulance_turn_direction == 2)
                {
                    ambulance = new Ambulance(ambulance_image, -360, random_y_ambulance, 90, RIGHT);
                }
                route_left->get_on_route(ambulance);
            }
        }

        for (int i = 0; i < 1; i++) //Ambulances from right route
        {
            int ambulance_from_right = rand() % 100;
            if(ambulance_from_right <= 30 && move_from_right)
            {
                random_y_ambulance = rand()% 10 + 350;
                ambulance_turn_direction = rand() % 3;
                if (ambulance_turn_direction == 0)
                {
                    ambulance = new Ambulance(ambulance_image, 960, random_y_ambulance, -90, UP);
                }
                if (ambulance_turn_direction == 1)
                {
                    ambulance = new Ambulance(ambulance_image, 960, random_y_ambulance, -90, DOWN);
                }
                if (ambulance_turn_direction == 2)
                {
                    ambulance = new Ambulance(ambulance_image, 960, random_y_ambulance, -90, LEFT);
                }
                route_right->get_on_route(ambulance);
            }
        }

        for (int i = 0; i < 1; i++) //Ambulances from down route
        {
            int ambulance_from_down = rand() % 100;
            if(ambulance_from_down <= 30 && move_from_down)
            {
                random_x_ambulance = rand()% 10 + 235;
                ambulance_turn_direction = rand() % 3;
                if (ambulance_turn_direction == 0)
                {
                    ambulance = new Ambulance(ambulance_image, random_x_ambulance, 960, 0, UP);
                }
                if (ambulance_turn_direction == 1)
                {
                    ambulance = new Ambulance(ambulance_image, random_x_ambulance, 960, 0, LEFT);
                }
                if (ambulance_turn_direction == 2)
                {
                    ambulance = new Ambulance(ambulance_image, random_x_ambulance, 960, 0, RIGHT);
                }
                route_down->get_on_route(ambulance);
            }
        }
    }

    // PERSON
    Mobile* person = NULL;
    int random_x_person = 0;
    int random_y_person = 0;
    string random_color_person = "";
    int random_colorVal_person = 0;

    // -----> Generating PEOPLE
    if(frame%7000 == 5500)
    {
        for (int i = 0; i < 1; i++) //People from up route
        {
            int people_from_up = rand() % 100;
            if(people_from_up <= 30)
            {
                random_x_person = 458;
                random_colorVal_person = rand() % 3;
                if (random_colorVal_person == 0)
                {
                    random_color_person = "BLUE";
                }
                if (random_colorVal_person == 1)
                {
                    random_color_person = "RED";
                }
                if (random_colorVal_person == 2)
                {
                    random_color_person = "GREEN";
                }
                person = new Person(person_image, random_x_person, -100, 180, random_color_person, DOWN);
                route_up->get_on_route(person);
            }
        }

        for (int i = 0; i < 1; i++) //People from left route
        {
            int people_from_left = rand() % 100;
            if(people_from_left <= 30)
            {
                random_y_person = 140;
                random_colorVal_person = rand() % 3;
                if (random_colorVal_person == 0)
                {
                    random_color_person = "BLUE";
                }
                if (random_colorVal_person == 1)
                {
                    random_color_person = "RED";
                }
                if (random_colorVal_person == 2)
                {
                    random_color_person = "GREEN";
                }
                person = new Person(person_image, -100, random_y_person, 90, random_color_person, RIGHT);
                route_left->get_on_route(person);
            }
        }

        for (int i = 0; i < 1; i++) //People from right route
        {
            int people_from_right = rand() % 100;
            if(people_from_right <= 30)
            {
                random_y_person = 460;
                random_colorVal_person = rand() % 3;
                if (random_colorVal_person == 0)
                {
                    random_color_person = "BLUE";
                }
                if (random_colorVal_person == 1)
                {
                    random_color_person = "RED";
                }
                if (random_colorVal_person == 2)
                {
                    random_color_person = "GREEN";
                }
                person = new Person(person_image, 600, random_y_person, -90, random_color_person, LEFT);
                route_right->get_on_route(person);
            }
        }

        for (int i = 0; i < 1; i++) //People from down route
        {
            int people_from_down = rand() % 100;
            if(people_from_down <= 30)
            {
                random_y_person = 700;
                random_colorVal_person = rand() % 3;
                if (random_colorVal_person == 0)
                {
                    random_color_person = "BLUE";
                }
                if (random_colorVal_person == 1)
                {
                    random_color_person = "RED";
                }
                if (random_colorVal_person == 2)
                {
                    random_color_person = "GREEN";
                }
                person = new Person(person_image, 155, random_y_person, 0, random_color_person, UP);
                route_down->get_on_route(person);
            }
        }
    }
    ++frame;

    game_end = colliding(route_up, route_left,route_down,route_right);

    if(!true)
    {
        cout<<"Game Over"<<endl;
        *switch_case = 3;
    }
}

void PlayGame::make_signal(LTexture* signal_image)
{
    // -----> Generating TRAFFIC SIGNAL LIGHTS
    lights_route_up = new TrafficSignal(signal_image, 306, 105, 180); // Route UP lights
    lights_route_down = new TrafficSignal(signal_image, 306, 505, 0); // Route DOWN lights
    lights_route_left = new TrafficSignal(signal_image, 105, 302, 90); // Route LEFT lights
    lights_route_right = new TrafficSignal(signal_image, 500, 302, -90); // Route RIGHT lights
}

void PlayGame::set_score()
{
    if(score > 0)
    {
        score--;
    }
}

int PlayGame::get_score()
{
    return score;
}

void PlayGame::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    SpriteSheetDisplay->Render( 0, 0, &spriteClips, 0, NULL, SDL_FLIP_NONE, gRenderer );
    word->ChangeText(int_to_string(score));
    word->Render(gRenderer, false);
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );

    //Up route
    route_up->render_all_cars(frame, gRenderer, false);
    if(move_from_up)
    {

        route_up->move_all_cars();
    }
    /*else
    {
        route_up->move_signal();
    }*/

    route_up->TurnL();

    //Left route
    route_left->render_all_cars(frame, gRenderer, false);
    if(move_from_left)
    {
        route_left->move_all_cars();
    }
    else
    {
        route_left->move_signal();
    }
    route_left->TurnL();

    //Right route
    route_right->render_all_cars(frame, gRenderer, false);
    if(move_from_right)
    {
        route_right->move_all_cars();
    }
    else
    {
        route_right->move_signal();
    }
    route_right->TurnL();

    //Down route
    route_down->render_all_cars(frame, gRenderer, false);
    if(move_from_down)
    {
        route_down->move_all_cars();
    }
    else
    {
        route_down->move_signal();
    }
    route_down->TurnL();

    //Rendering Traffic Signal lights
    lights_route_up->Render(frame, gRenderer, move_from_up, false);
    lights_route_down->Render(frame, gRenderer, move_from_down, false);
    lights_route_left->Render(frame, gRenderer, move_from_left, false);
    lights_route_right->Render(frame, gRenderer, move_from_right, false);

    SDL_RenderPresent( gRenderer );
    ++frame;
    if(debug == true)
    {
        SDL_Rect rect = { point.x - Screen_width/2, point.y - Screen_height/2, Screen_width, Screen_height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

}


bool PlayGame::colliding(Route* route_up,Route* route_left,Route* route_down,Route* route_right)
{
    bool one_true = false;

    for(int i = 0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            if(i==0)
            {
                if(j==0)
                {
                    one_true = one_true || route_up->check_collision(route_down->get_head());
                }
                if(j==1)
                {
                    one_true = one_true || route_up->check_collision(route_left->get_head());
                }
                if(j==2)
                {
                    one_true = one_true || route_up->check_collision(route_right->get_head());
                }
            }

            if(i==1)
            {
                if(j==0)
                {
                    one_true = one_true || route_down->check_collision(route_left->get_head());
                }
                if(j==1)
                {
                    one_true = one_true || route_down->check_collision(route_right->get_head());
                }

            }

            if(i==2)
            {
                if(j==0)
                {
                    one_true = one_true ||route_left->check_collision(route_right->get_head());
                }

            }
        }
    }
    return one_true;
}

string PlayGame::int_to_string(int num)
{
    std::stringstream character;
    character<<num;
    return character.str();
}

void PlayGame::save_game(ofstream& readfile)
{
    if(car!=NULL)
    {
        readfile<<car->GetX()<<endl;
        readfile<<car->GetY()<<endl;
    }
    if(truck!=NULL)
    {
        readfile<<truck->GetX()<<endl;
        readfile<<truck->GetY()<<endl;
    }
    if(motorcycle!=NULL)
    {
        readfile<<motorcycle->GetX()<<endl;
        readfile<<motorcycle->GetY()<<endl;
    }
    if(ambulance!=NULL)
    {
        readfile<<ambulance->GetX()<<endl;
        readfile<<ambulance->GetY()<<endl;
    }
    if(person!=NULL)
    {
        readfile<<person->GetX()<<endl;
        readfile<<person->GetY()<<endl;
    }
    readfile<<lights_route_up->state<<endl;
    readfile<<lights_route_down->state<<endl;
    readfile<<lights_route_left->state<<endl;
    readfile<<lights_route_right->state<<endl;
}
void PlayGame::load_game(ifstream& readfile)
{
    string data;
    int line=1;
    while(getline(readfile, data))
    {
        if (line==1)
        {
            int x;
            stringstream convert(data);
            convert>>x;
            lights_route_up->state = x;
        }
        if (line==2)
        {
            int x;
            stringstream convert(data);
            convert>>x;
            lights_route_down->state = x;
        }
        if (line==3)
        {
            int x;
            stringstream convert(data);
            convert>>x;
            lights_route_left->state = x;
        }
        if (line==4)
        {
            int x;
            stringstream convert(data);
            convert>>x;
            lights_route_right->state = x;
        }
    }
}
