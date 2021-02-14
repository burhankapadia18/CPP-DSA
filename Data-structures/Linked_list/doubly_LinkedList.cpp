#include<iostream>

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

class DLL {
public:
	node *head;
	DLL(){
		head = NULL;
	}
	void insertBeg(int info){
		node *np = new node(info);
		if(head == NULL)
			head = np;
		else {
			head->prev = np;
			np->next = head;
			head = np;
		}
	}
	void insertEnd(int info){
		if(head == NULL){
			insertBeg(info); return;
		}
		node *np = new node(info), *ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = np;
		np->prev = ptr;
	}
	void insertSpecific(int info ,int pos){
		if(pos == 1){
			insertBeg(info);
			return ;
		}
		node *np = new node(info), *ptr = head;
		pos--;
		while(pos != 1){
			ptr = ptr->next;
			pos--;
		}
		np->next = ptr->next;
		ptr->next = np;
		np->prev = ptr;
	}
	void deleteBeg(){
		if(head == NULL){
			cout<<"list is empty!!!\n";
		}
		else{
			node *np = head;
			head = head->next;
			delete(np);
		}
	}
	void deleteEnd(){
		if(head == NULL){
			cout<<"list is empty"; return;
		}
		node *aux, *ptr = head;
		while(ptr->next != NULL){
			aux = ptr;
			ptr = ptr->next;
		}
		aux->next = NULL;
		delete(ptr);
	}
	void deleteSpecific(int pos){
		node *ptr = head, *prev;
		if(pos == 1){
			deleteBeg(); return;
		}
		while(pos != 1 && ptr != NULL){
			prev = ptr;
			ptr = ptr->next;
			pos--;
		}
		if(ptr == NULL){
			cout<<"position doesn't exist\n";
			return;
		}
		if(ptr->next == NULL && pos == 1){
			deleteEnd();
			return;
		}
		prev->next = ptr->next;
		ptr->next->prev = prev;
		delete(ptr);
	}
	void display(){
		if(head == NULL){
			cout<<"empty!!\n";
			return;
		}
		node *ptr = head;
		while(ptr != NULL){
			cout<<ptr->data<<" ";
			ptr = ptr->next;
		}
		cout<<"\n";
	}
	void reverse(){
		node *temp, *ptr, *next = head;
		while(next != NULL){
			ptr = next;
			next = ptr->next;
			temp = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = temp;
		}
		head = ptr;
		return;
	}
	void deleteAll()
	{
		while(head != NULL)
		{
			node *p = head;
			head = head->next;
			delete(p);
		}
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

	int n, data;
	cin>>n;
	DLL d1;
	while(n--)
	{
		cin>>data;
		d1.insertEnd(data);
	}

	d1.display();

	d1.deleteAll();
	return 0;
}