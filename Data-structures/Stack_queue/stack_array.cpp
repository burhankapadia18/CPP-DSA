#include<iostream>
using namespace std;

class stack {
	int array[100];
	int top, size;
public:
	stack(){
		top = -1;
		size = 100;
	}
	void push(int data){
		if(top == size){
			cout<<"overflow!!!\n";
		}
		else{
			array[++top] = data;
		}
	}
	void pop(){
		if(top == -1){
			cout<<"underflow!!!\n";
		}
		else
			top--;
	}
	void deleteStack(){
		top = -1;
	}
	void display(){
		if(top == -1){
			cout<<"stack is empty";
		}
		else{
			for(int i = top; i > -1; i--){
				cout<<array[i]<<"->";
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

}