#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *prev, *next;
    node(int info){
        data = info;
        prev = next = NULL;
    }
};
class Deque {
public:
    node *front, *rear;
    Deque(){
        front = rear = NULL:
    }
    void insertFront(int data){
        node *p = new node(data);
        if(front == NULL){
            front = rear = p;
            return;
        }
        front->prev = p;
        p->next = front;
        front = p;
    }
    void insertLast(int data){
        node *p = new node(data);
        if(front == NULL){
            front = rear = p;
            return;
        }
        rear->next = p;
        p->prev = rear;
        rear = p;
    }
    void deleteFront(){
        if(front == NULL){
            cout<<"empty";
            return;
        }
        node *p = front;
        front = front->next;
        front->prev = NULL;
        delete(p);
    }
    void deleteLast(){
        if(rear == NULL){
            cout<<"empty";
            return;
        }
        node *p = rear;
        rear = rear->prev;
        rear->next = NULL;
        delete(p);
    }
};