#include<iostream>
using namespace std;

struct node {
	int data;
	node *next;
} *ptr, *np;

class stack {
	node *top;
public:
	stack(){
		top = NULL;
	}
	void push(int info){
		np = new node;
		np->data = info;
		np->next = NULL;
		if(top == NULL)
			top = np;
		else {
			np->next = top;
			top = np;
		}
	}
	void pop(){
		if(top == NULL)
			cout<<"underflow\n";
		else {
			np = top;
			top = top->next;
			delete(np);
		}
	}
	void deleteStack(){
		ptr = top;
		while(ptr){
			np = ptr;
			ptr = ptr->next;
			delete(np);
		}
		top = NULL;
	}
	void display(){
		if(top == NULL)
			cout<<"stack is empty\n";
		else {
			ptr = top;
			while(ptr != NULL){
				cout<<ptr->data<<"->";
				ptr = ptr->next;
			}
			cout<<"!!!\n";
		}
	}
};

int main(){

	stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.display();
	s1.pop();
	s1.pop();
	s1.display();
	s1.deleteStack();
	s1.display();

}