#pragma once
#include"Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void Enqueue(Mobile*);
    void TurnRouteDown();
    void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void linkedlist_move_signal();
    void Move();
    void Move_x();
    int getSize() {return size;}
    bool Is_colliding(Mobile*,Mobile*);
    Node* get_head();
    bool check_collision(Node* headOfOther);

private:
    Node* head;
    Node* tail;
    int size = 0;

};
