#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next, *prev;
	node(int info){
		data = info;
		next = prev = NULL;
	}
};

int countPairs(struct node* first, struct node* second, int value) 
{ 
    int count = 0; 
    while (first != NULL && second != NULL &&  first != second && second->next != first) 
    { 
        if ((first->data + second->data) == value) 
        { 
            count++; 
            first = first->next; 
            second = second->prev; 
        } 
        else if ((first->data + second->data) > value) 
            second = second->prev; 
        else
            first = first->next; 
    } 
  
    return count; 
} 
int countTriplets(struct node *head, int x) 
{  
    if (head == NULL) 
        return 0; 
  
    node *current, *first, *last; 
    int count = 0; 
    last = head; 
    while (last->next != NULL) 
        last = last->next; 
  
    for (current = head; current != NULL; current = current->next) 
    { 
        first = current->next; 
        count += countPairs(first, last, x - current->data); 
    } 
  
    return count; 
}
