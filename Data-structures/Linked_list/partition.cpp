#include<bits/stdc++.h>
using namespace std;

node *partition(node *head, int x){
    //divides linkedlist around a value x such that all nodes less than x come
    //before all nodes greater than or equal to x
    node *bs = NULL;
    node *be = NULL;
    node *as = NULL;
    node *ae = NULL;

	node *next;

    while(head != NULL){
		next = head->next;
		head->next = NULL;
        if(head->data < x){
            if(bs == NULL){
                bs = be = head;
            }
            else {
                be->next = head;
                be = head;
            }
        }
        else {
            if(as == NULL)
                as = ae = head;
            else {
                ae->next = head;
                ae = head;
            }
        }
        head = next;
    }
    if(bs == NULL)
        return as;
    
	be->next = as;

    return bs;
}

node *partition(node *head, int x){
    
    node *h = head, *t = head;
	while(head != NULL){
		node *nxt = head->next;
		if(head->data < x){
			head->next = h;
			h = head;
		}
		else {
			t->next = head;
			t = head;
		}
		head = nxt;
	}
	t->next = NULL;

	return h;
}