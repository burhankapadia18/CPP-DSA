#include<iostream>
using namespace std;

class Cnode {
public:
	int data;
	Cnode *next;
	Cnode(int info){
		data = info;
		next = NULL;
	}
};

class CLL {
	
public:
	Cnode *head;
	CLL(){
		head = NULL;
	} 
	void inesrtBeg(int info){
		Cnode *np = new Cnode(info);
		if(head == NULL){
			head = np;
			head->next = np;
		}
		else{
			np->next = head;
			Cnode *ptr = head;
			do{
				ptr = ptr->next;
			}while(ptr->next != head);
			ptr->next = np;
			head = np;
		}
	}
	void insertEnd(int info){
		if(head == NULL){
			inesrtBeg(info); return;
		}
		Cnode *np = new Cnode(info), *ptr = head;
		while(ptr->next != head){
			ptr = ptr->next;
		}
		ptr->next = np;
		np->next = head;
	}
	void deleteBeg(){
		if(head == NULL){
			cout<<"list is empty"; return;
		}
		Cnode *ptr = head, *aux = head;
		do{
			aux = aux->next;
		}while(aux->next != head);
		head = head->next;
		aux->next = head;
		delete(ptr);
	}
	void deleteEnd(){
		if(head == NULL){
			cout<<"list is empty"; return;
		}
		Cnode *ptr = head, *aux;
		do{
			aux = ptr;
			ptr = ptr->next;
		}while(ptr->next != head);
		aux->next = head;
		delete(ptr);
	}
	void display(){
		if(head == NULL){
			cout<<"list is empty"; return;
		}
		Cnode *ptr = head;
		do{
			cout<<ptr->data<<"->";
			ptr = ptr->next;
		}while(ptr != head);
		cout<<"!!!\n";
	}
};

int main(){

	#ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

	CLL c1;
	int data; char c = 'y';
	while(c != 'n'){
		cin>>data>>c;
		c1.inesrtBeg(data);
	}
	c1.display();
	return 0;

}