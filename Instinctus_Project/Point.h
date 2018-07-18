#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class Point
{
    public:
        Point();
        Point(float, float);
        float get_x();
        float get_y();
        void set_x(float);
        void set_y(float);
        float x;
        float y;
};

#endif // POINT_H
