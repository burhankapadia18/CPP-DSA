#include<iostream>
using namespace std;

class node {
public:
	int data;
	node *link;
} *np, *ptr;

class ll {
	node *head;
public:
	ll(){
		head = NULL;
	}
	node *createnode(int info){
		np = new node;
		np->data = info;
		np->link = NULL;
		return np;
	}
	void insert(int info){
		np = createnode(info);
		if(head == NULL)
			head = np;
		else{
			np->link = head;
			head = np;
		}
	}
	void display(){
		ptr = head;
		while(ptr != NULL){
			cout<<ptr->data<<"->";
			ptr = ptr->link;
		}
		cout<<"!!!\n";
	}
	void cycleCreator(){
		ptr = head;
		while(ptr->link != NULL){
			if(ptr->data == 6)
				np = ptr;
			ptr = ptr->link;
		}
		ptr->link = np;
	}
	// floyd cycle finding algorithm (given below)
	// time complexity:O(n)
	// space complexity:O(1)
	void does_LL_has_loop(){
		node *sptr=head, *fptr=head;
		while(sptr && fptr && fptr->link){
			sptr = sptr->link;
			fptr = fptr->link->link;
			if(sptr == fptr){
				cout<<"linked list has loop";
				return;
			}
		}
		cout<<"linked list doesn't have loop";
	}
};

int main(){

	ll l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert(7);
	l1.insert(8);
	l1.insert(9);
	l1.insert(10);
	l1.display();
	//l1.cycleCreator();
	l1.does_LL_has_loop();
	//l1.display();

}