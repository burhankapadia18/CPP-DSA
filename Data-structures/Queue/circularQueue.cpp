#include<bits/stdc++.h>
using namespace std;

const int size = 100;
class Cqueue {
	int arr[size];
public:
	int front, rear;
	Cqueue(){
		front = rear = -1;
	}
	void push(int data){
		if((front==0 && rear==size-1)||(front==rear+1))
			return;
		if(rear==-1)
			front = rear = 0;
		else if(rear == size-1)
			rear = 0;
		else 
			rear++;
		arr[rear] = data;
	}
	void pop(){
		if(front==-1)
			return;
		if(front==rear)
			front = rear = -1;
		else if(front==size-1)
			front = 0;
		else front++;
	}
	void display(){
		int i=0;
		if(front==-1)
			return;
		if(rear>=front){
			for(i=front; i<=rear; i++)
				cout<<arr[i]<<" ";
		}
		else {
			for(i=front; i<size; i++)
				cout<<arr[i]<<" ";
			for(i=0; i<=rear; i++)
				cout<<arr[i]<<" ";
		}
		cout<<'\n';
	}
};

int main(){

	#ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

	int n, data;
	cin>>n;
	Cqueue Q;
	while(n--){
		cin>>data;
		Q.push(data);
	}

	Q.display();

	return 0;
}