#include<iostream>
using namespace std;

class node {
public:
	int data;
	node *link;
} *np,*ptr;

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
	// T(n) = O(n)+O(n)~=O(n)
	// using 2 loops
	void nth_node_from_last_1(int n){
		int count = 0;
		ptr = head;
		while(ptr != NULL){
			count++;
			ptr = ptr->link;
		}
		if(count <= n){
			cout<<"not enough nodes\n";
			return;
		}
		n = count - n;
		ptr = head;
		while(n > 0){
			ptr = ptr->link;
			n--;
		}
		cout<<ptr->data;
	}
	// efficient approach T(n) = O(n)
	// using single loop
	void nth_node_from_last_2(int n){
		np = ptr = head;
		while(ptr != NULL){
			if(n < 1)
				np = np->link;
			ptr = ptr->link;
			n--;
		}
		cout<<np->data;
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
	l1.nth_node_from_last_2(4);

}