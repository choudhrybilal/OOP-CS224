#pragma once
#include"Node.h"

class Queue
{
private:
    Node* head;
    Node* tail;
    bool collision;
public:
    Queue();
    ~Queue();
    void Enqueue(Mobile*);
    void Comparison();
    void Clean();
    void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void Move();
};
