#pragma once
#include"Mobile.h"

struct Node
{
    Mobile* mobile;
    Node* next;
    Node* prev;

    ~Node()
    {
        delete mobile;
    }
};
