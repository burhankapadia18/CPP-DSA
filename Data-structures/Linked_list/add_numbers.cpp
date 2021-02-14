#include<bits/stdc++.h>
using namespace std;


// add to numbers represented as linkedlist
node *add(node *head1, node *head2, int carry=0){

    if(head1==NULL && head2==NULL & carry==0)
        return NULL;

    int value = carry;
    if(head1 != NULL)
        value += head1->data;
    if(head2 != NULL)
        value += head2->data;
    node *result = new node(value%10);
    carry = value/10;
    if(head1 != NULL || head2 != NULL)
        result->next = add(head1==NULL?NULL:head1->next, head2==NULL?NULL:head2->next, carry);
   
    return result;
}


//add 1 to a number respresented as linkedlist
void add_one_util(node *head, int &carry){

	if(head->next==NULL){
		int val = head->data + 1;
		head->data = val%10;
		carry = val/10;
		return;
	}

	add_one_util(head->next, carry);
	int val = head->data + carry;
	head->data = val%10;
	carry = val/10;
}
node *add_one(node *head){
	if(head==NULL)
		return NULL;
	
	int carry = 0;
	add_one_util(head,carry);
	if(carry != 1)
		return head;
	node *newhead = new node(carry);
	newhead->next = head;
	return newhead;
}