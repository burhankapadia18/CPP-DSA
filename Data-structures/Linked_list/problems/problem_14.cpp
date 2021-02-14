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
	void create_cycle(int val){
		ptr = head;
		while(ptr->link != NULL){
			if(ptr->data == val)
				np = ptr;
			ptr = ptr->link;
		}
		ptr->link = np;
	}
	// floyd cycle finding algorithm (given below)
	// time complexity:O(n)
	// space complexity:O(1)
	void find_length_of_loop(){
		node *sptr=head, *fptr=head;
		int loopExists=0;
		while(sptr && fptr && fptr->link){
			sptr = sptr->link;
			fptr = fptr->link->link;
			if(sptr == fptr){
				loopExists = 1;
				break;
			}
		}
		if(loopExists){
			int count = 0;
			fptr = fptr->link;
			while(fptr != sptr){
				count++;
				fptr = fptr->link;
			}
			cout<<"lenght of loop is "<<count;
		}
		else {
			cout<<"linked list has no loop";
		}
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
	l1.create_cycle(6);
	l1.find_length_of_loop();
	//l1.display();

}