/*
Habib University, Summer Semester 2018,
Object Oriented Programming & Design Methodologies(CS224),
Project: INSTINCTUS; Smart Traffic Signal at Intersection: CPP SDL Based game,

Instructor: Dr. Umair Azfar Khan

By:
    Choudhry Bilal Mazhar(cm00326)
    Muhammad Talha (mt00727)
*/

#include <iostream>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <math.h>
#include <time.h>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

#include "LTexture.h"
#include "LinkedList.h"
#include "Node.h"
#include "Mobile.h"
#include "Car.h"
#include "Truck.h"
#include "Route.h"
#include "Motorcycle.h"
#include "Person.h"
#include "TrafficSignal.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "PlayGame.h"
#include "GameOver.h"
#include "ImageLoad.h"

using namespace std;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

bool init();
bool loadMedia();
void close();

//SDL_Texture* loadTexture( string path );
SDL_Window* gWindow = NULL;
SDL_Texture* gTexture = NULL;
SDL_Renderer* gRenderer = NULL;

Mix_Music* gMusic = NULL;

ImageLoad i_load;

bool init();
bool loadMedia();
void close();

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        gWindow = SDL_CreateWindow( "SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }

                //Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
            }
        }
    }
    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load Background Image
    if( !i_load.gbackGround.LoadFromFile( "Images/3LaneBackground.png", gRenderer  ) )
    {
        printf( "Failed to load background texture!\n" );
        success = false;
    }

    //Load Cars Image
    if( !i_load.gSpriteSheetCar.LoadFromFile( "Images/myCars.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet for cars!\n" );
        success = false;
    }

    //Load Trucks Image
    if( !i_load.gSpriteSheetTruck.LoadFromFile( "Images/ambulance_truck.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet for trucks!\n" );
        success = false;
    }

    //Load Motorcycles Image
    if( !i_load.gSpriteSheetMotorcycle.LoadFromFile( "Images/Vehicles.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet for motorcycles!\n" );
        success = false;
    }

    //Load Ambulance Image
    if( !i_load.gSpriteSheetAmbulance.LoadFromFile( "Images/ambulance_truck.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet for ambulances!\n" );
        success = false;
    }

    //Load People Image
    if( !i_load.gSpriteSheetPerson.LoadFromFile( "Images/People.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet for people!\n" );
        success = false;
    }

    //Load Traffic Signal Image
    if( !i_load.gSpriteSheetTrafficSignal.LoadFromFile( "Images/TrafficLights.JPG", gRenderer) )
    {
        printf( "Failed to load sprite sheet for traffic lights!\n" );
        success = false;
    }

    //Load Splash Screen
    if( !i_load.gSpriteSheetSplashScreen.LoadFromFile( "Images/Instinctus.png", gRenderer) )
    {
        printf( "Failed to load sprite sheet for traffic lights!\n" );
        success = false;
    }

    //Load MainMenu Screen
    if( !i_load.gSpriteSheetMainMenu.LoadFromFile( "Images/menuscreen.JPG", gRenderer) )
    {
        printf( "Failed to load sprite sheet for traffic lights!\n" );
        success = false;
    }

    //Load Buttons in MainMenu Screen
    if( !i_load.gSpriteSheetOptions.LoadFromFile( "Images/fontSprite.png", gRenderer) )
    {
        printf( "Failed to load sprite sheet for traffic lights!\n" );
        success = false;
    }

    //Load Game Over Screen
    if( !i_load.gSpriteSheetGameOver.LoadFromFile( "Images/gameover.png", gRenderer) )
    {
        printf("Failed to load sprite sheet for Game Over Screen!\n");
        success = false;
    }

    //Load Background Sound Effects
    gMusic = Mix_LoadMUS( "Sounds/Traffic.wav" );
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded images
    i_load.gbackGround.Free();
    i_load.gSpriteSheetCar.Free();
    i_load.gSpriteSheetTruck.Free();
    i_load.gSpriteSheetMotorcycle.Free();
    i_load.gSpriteSheetAmbulance.Free();
    i_load.gSpriteSheetPerson.Free();
    i_load.gSpriteSheetTrafficSignal.Free();
    i_load.gSpriteSheetSplashScreen.Free();
    i_load.gSpriteSheetMainMenu.Free();
    i_load.gSpriteSheetGameOver.Free();

    //Free the music
    Mix_FreeMusic(gMusic);
    gMusic = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    ofstream readfile;
    ifstream savefile;
    char filename[50] = "saves.txt";
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;
            srand(time(NULL));
            int keyPressDelay = 0;
            int switch_case = 0;
            bool mouse_click = false;

            //Event handler
            SDL_Event e;
            long int frame = 0;
            // LinkedList l;

            int signal_route1 = 0;
            int signal_route2 = 0;
            int signal_route3 = 0;
            int signal_route4 = 2;
            bool signal_click = false;
            bool move_from_up = true;
            bool move_from_left = true;
            bool move_from_right = true;
            bool move_from_down = true;

            //SPLASH SCREEN POINTER DECLARATION
            SplashScreen* splash_screen = NULL;

            // MAIN MENU
            MainMenu* menu = NULL;
            menu = new MainMenu(&i_load.gSpriteSheetMainMenu, &i_load.gSpriteSheetOptions, (float) SCREEN_WIDTH/2, (float) SCREEN_HEIGHT/2);

            // PLAY GAME
            PlayGame* play = NULL;
            play = new PlayGame(&i_load.gbackGround, &i_load.gSpriteSheetOptions, (float) SCREEN_WIDTH/2, (float) SCREEN_HEIGHT/2);
            play->make_signal(&i_load.gSpriteSheetTrafficSignal);

            // GAME OVER
            GameOver* game_over = NULL;
            game_over = new GameOver(&i_load.gSpriteSheetGameOver, &i_load.gSpriteSheetOptions, (float) SCREEN_WIDTH/2, (float) SCREEN_HEIGHT/2);

            //While application is running
            while( !quit )
            {
                if( Mix_PlayingMusic() == 0 )
                {
                    //Play the music
                    Mix_PlayMusic( gMusic, -1 );
                }

                //Defining Switch switch_case
                switch(switch_case)
                {
                case 0:
                {
                    if (splash_screen == NULL)
                    {
                        splash_screen = new SplashScreen(&i_load.gSpriteSheetSplashScreen, 0, 0);
                        splash_screen->Render(frame, gRenderer, false);
                        SDL_RenderPresent( gRenderer );
                        SDL_Delay(5000);
                        break;
                    }
                }
                case 1:
                {

                    menu->Render(frame, gRenderer, false);
                    SDL_RenderPresent( gRenderer );
                    menu->handle_event(e, &mouse_click, &quit, &switch_case);
                    break;
                }
                case 2:
                {

                    play->make_new_mobile(&switch_case, &i_load.gSpriteSheetCar, &i_load.gSpriteSheetTruck, &i_load.gSpriteSheetMotorcycle, &i_load.gSpriteSheetAmbulance, &i_load.gSpriteSheetPerson, frame);
                    play->Update_signal(move_from_up,move_from_left,move_from_right,move_from_down);
                    play->Render(frame, gRenderer, false);
                    SDL_RenderPresent( gRenderer );
                    ++frame;
                    if (play->get_score() < 1)
                    {
                        switch_case = 3;
                    }
                    break;
                }
                case 3:
                {
                    game_over->Render(frame, gRenderer, false);
                    SDL_RenderPresent( gRenderer );
                    game_over->game_over_event(e, &mouse_click, &quit, &switch_case);
                    break;
                }
                }

                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                }

                //Keyboard control keys defined
                const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

                if(currentKeyStates[ SDL_SCANCODE_RIGHT ]) //Right arrow key
                {
                    if(keyPressDelay > 300)
                    {
                        move_from_right = !move_from_right;
                        keyPressDelay = 0;
                        cout << "Right key pressed; " << boolalpha;
                        if(move_from_right == true)
                            cout << "Right Route: GREEN" << endl;
                        else
                            cout << "Right Route: RED" << endl;
                    }
                }

                if(currentKeyStates[ SDL_SCANCODE_LEFT ]) //Left arrow key
                {
                    if(keyPressDelay > 300)
                    {
                        move_from_left = !move_from_left;
                        keyPressDelay = 0;
                        cout<<"LEFT key pressed; " << boolalpha;
                        if(move_from_left == true)
                            cout << "Left Route: GREEN" << endl;
                        else
                            cout << "Left Route: RED" << endl;
                    }
                }

                if(currentKeyStates[ SDL_SCANCODE_UP ]) //Up arrow key
                {
                    if(keyPressDelay > 300)
                    {
                        move_from_up = !move_from_up;
                        keyPressDelay = 0;
                        cout<<"UP key pressed; " << boolalpha;
                        if(move_from_up == true)
                            cout << "Up Route: GREEN" << endl;
                        else
                            cout << "Up Route: RED" << endl;
                    }
                }

                if(currentKeyStates[ SDL_SCANCODE_DOWN ]) //Down arrow key
                {
                    if(keyPressDelay > 300)
                    {
                        move_from_down = !move_from_down;
                        keyPressDelay = 0;
                        cout<<"DOWN key pressed; " << boolalpha;
                        if(move_from_down == true)
                            cout << "Down Route: GREEN" << endl;
                        else
                            cout << "Down Route: RED" << endl;
                    }
                }

                if(currentKeyStates[ SDL_SCANCODE_ESCAPE ]) //Down arrow key
                {
                    if(keyPressDelay > 300)
                    {
                        readfile.open(filename);
                        play->save_game(readfile);
                        readfile.close();
                        switch_case = 1;
                    }
                }

                ++keyPressDelay;
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}
