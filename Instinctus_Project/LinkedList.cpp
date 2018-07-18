#include"LinkedList.h"
#include"LTexture.h"
#include<iostream>

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::Enqueue(Mobile* mobile)
{

    if(head == NULL)
    {
        head = new Node;
        head->mobile = mobile;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->mobile = mobile;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

Node* LinkedList::get_head()
{
    return head;
}

void LinkedList::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    Node* temp = head;
    while(temp!=NULL)
    {

        temp->mobile->Render(frame, gRenderer, debug);
        temp=temp->next;
    }
}

void LinkedList::Move()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->mobile->Move();
        temp=temp->next;
    }
}

void LinkedList::linkedlist_move_signal()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->mobile->crossed_signal)
        {
            temp->mobile->Move();
        }
            temp=temp->next;
    }
}

void LinkedList::TurnRouteDown()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->mobile->TurnRouteDown();
        temp=temp->next;
    }
}

bool LinkedList::check_collision(Node* headOfOther)
{
    Node* temp = head;
    while(temp!=NULL)
    {
            Node* temp2 = headOfOther;
            while(temp2!=NULL)
            {

                if(Is_colliding(temp->mobile,temp2->mobile))
                {
                    return true;
                }
                temp2=temp2->next;
            }

        temp=temp->next;
    }
    return false;
}

bool LinkedList::Is_colliding(Mobile* m1, Mobile* m2)
{
    if((m1->GetX() < 600) && (m1->GetY() < 600) && (m2->GetX() < 600) && (m2->GetY() < 600) && (m1->GetX() > 0) && (m1->GetY() > 0) && (m2->GetX() > 0) && (m2->GetY() > 0) )
    {


        SDL_Rect m1Box = m1->Get_box();
        SDL_Rect m2Box = m2->Get_box();

        int m1left = m1Box.x;
        int m1right = m1Box.x + m1Box.w;
        int m1down = m1Box.y + m1Box.h;
        int m1up = m1Box.y;

        int m2left = m2Box.x;
        int m2right = m2Box.x + m2Box.w;
        int m2down = m2Box.y + m2Box.h;
        int m2up = m2Box.y;

        if(m1right < m2left)
            return false;
        if(m1left>m2right)
            return false;
        if(m1up<m2down)
            return false;
        if(m1down>m2up)
            return false;
        return true;
    }
}
