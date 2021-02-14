#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;
	node(int info){
		data = info;
		next = NULL;
	}
};

class linkedList{
public:
	node *head;
	linkedList(){
		head = NULL;
	}
	void insert(int value){
		node *np = new node(value);
		if(head == NULL){
			head = np;
		}
		else{
			np->next = head;
			head = np;
		}
	}
	void insertEnd(int value){
		if(head == NULL){
			insert(value); return;
		}
		node *np = new node(value), *ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = np;
	}
	void insertSpecific(int pos, int info){
		if(pos == 1){
			insert(info);
			return ;
		}
		node *np = new node(info);
		pos--;
		node *ptr = head;
		while(pos != 1){
			ptr = ptr->next;
			pos-- ;
		}
		np->next = ptr->next;
		ptr->next = np;
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
		node *prev, *np = head;
		while(np->next != NULL){
			prev = np;
			np = np->next;
		}
		prev->next = NULL;
		delete(np);
	}
	void deleteSpecific(int pos){
		node *np = head ,*prev;
		if(pos == 1){
			deleteBeg();
			return;
		}
		while(pos != 1 && np != NULL){
			prev = np;
			np = np->next;
			pos--;
		}
		if(np == NULL){
			cout<<"position doesn't exist\n";
			return;
		}
		prev->next = np->next;
		delete(np);
	}
	void deleteAll(){
		node *np = head, *aux;
		while(np != NULL){
			aux = np->next;
			delete(np);
			np = aux;
		}
		head = NULL;
	}
	void display(){
		if(head == NULL){
			cout<<"stack is empty";
		}
		else{
			node *np = head;
			while(np != NULL){
				cout<<np->data<<" ";
				np = np->next;
			}
			cout<<'\n';
		}
	}
	void print_recursively(node *p){
		if(p == NULL){
			cout<<"!!!\n";
			return;
		}
		cout<<p->data<<"->";
		print_recursively(p->next);
	}
	void print_reverse(node *p){
		if(p == NULL){
			//cout<<"!!!";
			return;
		}
		print_reverse(p->next);
		cout<<p->data<<"->";
	}
	void reverse_ll1(){
		//iterative method
		node *current = head, *prev=NULL, *next;
		while(current != NULL){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void reverse_ll2(node *p){
		//recursive method
		if(p->next == NULL){
			head = p;
			return;
		}
		reverse_ll2(p->next);
		p->next->next = p;
		p->next = NULL;
	}
};

node *intersection_of_sorted_ll(node *head1, node *head2){
	node *newhead = NULL, *last;
	while(head1 != NULL && head2 != NULL){
		if(head1->data == head2->data){
			// insert into 3rd list
			if(newhead == NULL){
				node *ptr = new node(head1->data);
				newhead = ptr;
				last = ptr;
			} else {
				node *ptr = new node(head1->data);
				last->next = ptr;
				last = ptr;
			}
			head1 = head1->next;
			head2 = head2->next;
		}
		else {
			if(head1->data < head2->data)
				head1 = head1->next;
			else 
				head2 = head2->next;
		}
	}
	return newhead;
}


int main(){

	
	#ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

	linkedList s1, s2;
	
	int n, data;
	cin>>n;
	while(n--){
		cin>>data;
		s1.insertEnd(data);
	}
	// cin>>n;
	// while(n--){
	// 	cin>>data;
	// 	s2.insert(data);
	// }
	s1.display();
	revvv(s1.head,&s1.head);
	s1.display();

	s1.deleteAll();
	return 0;

}