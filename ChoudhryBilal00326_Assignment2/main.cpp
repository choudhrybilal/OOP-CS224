/*
Summer Semester 2018, Habib University,
Object Oriented Programming & Methodologies(CS224),
Assignment # 02,

Instructor: Dr. Umair Azfar Khan,
TA: Ahmed Ali(aa02190),

Choudhry Bilal Mazhar (cm00326)
*/

#include <iostream>
#include<stdio.h>
#include<time.h>
#include <stdlib.h>

using namespace std;

int arrows, weapons, item;
int health = 20;
int days = 1;

int days_passed()
{
    days = days +1;
    return 0;
}

int giveup()
{
    string giveup[5] = {"Death by starvation!\n", "Death by disease!\n", "Death by dehydration!\n", "Death by avada kadavera!\n", "Death by snake bite!\n"};
    srand (time(NULL));
    int random1 = rand() % 6;
    cout << "\nRastan has decided to give up!" <<endl;
    cout << giveup[random1] <<endl;
    cout <<"Game Over!!!" <<endl;
    exit(0);
}

int food_supplies = 10;

int food_add()
{
    food_supplies = food_supplies + 5;
    cout <<"Rastan has found food!" <<endl;
    cout <<"Food supplies for 5 more days!" <<endl;
    return 0;
}

int food_left()
{
    food_supplies = food_supplies - 1;
    if (food_supplies == 0)
    {
        cout << "Rastan has ran out of food supplies!" <<endl;
        cout << "Rastan Died!\nGAME OVER!!!" <<endl;
    }
    else
        return 0;
    return 0;
}

int tracks = 0;

int carvan_tracks()
{
    tracks = tracks + 1;
    cout << "Rastan found carvan tracks!" <<endl;
    if(tracks==6)
    {
        cout << "\nRastan has reached Persia!" <<endl;
        cout << "Game End!!!" <<endl;
        exit(0);
    }
    return 0;
}

int healer()
{
    health = 20;
    cout << "\nRastan has found a healer!\nRastan's health restored!\nHealth = 20" <<endl;
    return 0;
}

int moveforward()
{
    string forward[5] = {"Rastan comes across food and water!", "Rastan comes across a hidden chest that contains a weapon or arrows!", "Rastan comes across a 3 bandits!", "Rastan comes across a healer who heals him!", "Rastan comes across caravan tracks!"};
    srand (time(NULL));
    int random2 = rand() % 6;
    cout <<"\n" << forward[random2]<< endl;
    if (random2==0)
    {   food_add();
        cout << "\nEnough food left for: " << food_supplies << " days." << endl;
    }
    if (random2==1)
    {   cout << "WEAPON OR ARROWS" << endl;
    }
    if (random2==2)
    {   cout << "BANDITS" << endl;
    }
    if (random2==3)
    {
        healer();
    }
    if (random2==4)
    {
        carvan_tracks();
    }
    return 0;
}

int movement()
{
    cout << "\nDay "<< days <<": Enter 'F' to move forward or 'G' to give up --> ";
    char userinput; // case sensitive
    cin >> userinput;
    if (userinput=='F')
    {   cout << "\nRastan has consumed food supply for a day." << endl;
        days_passed();
        food_left();
        cout << "Enough food left for: " << food_supplies << " days." << endl;
        moveforward();
    }
    else if (userinput=='G')
    {
        giveup();
    }
    else
    {
        cout << "\nINVALID INSTRUCTION!\nTRY AGAIN!" <<endl;
        movement();
    }
    cout << "\nx-----------------------------------------------------------------------------------------------x" <<endl;
    if(health>>0 || food_supplies>>0);
    {
        movement();
    }
return 0;
}

//int combat()
//{
//
//}

int main()
{
    cout << "ADVENTURE GAME!" << endl;
    cout << "\nPlot: \n\n'A young man Rastan was on his way to Persia from Delhi before he got separated from his caravan." <<endl;
    cout << "Armed only with a dagger, Rastan has nowhere to go except to move forward." <<endl;
    cout << "But his path is laden with awards and mischief. \nHe does not know what he will encounter across the next corner." <<endl;
    cout << "After a good nights rest, he chooses to move forward and brace himself for the things to come.'" << endl;
    cout << "\nRastan's Health = 20, Food Suplies = 10 days" <<endl;
    cout << "\nx-----------------------------------------------------------------------------------------------x" <<endl;
    movement();

}
