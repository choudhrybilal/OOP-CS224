#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::Enqueue(Mobile* Mobile)
{
    if(head == NULL)
    {
        head = new Node;
        head->mobile = Mobile;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->mobile = Mobile;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void Queue::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->mobile->Render(frame, gRenderer, debug);
        temp=temp->next;
    }
}

void Queue::Move()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->mobile->Move();
        temp=temp->next;
    }
}
