#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;
    node *bottom;
    node(int data){
        this->data = data;
        next = bottom = NULL;
    }
};

node *merge(node *head1, node *head2){
    node *res = NULL, *temp = NULL;
    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            if(res == NULL){
                res = temp = head1;
				head1 = head1->bottom;
			}
            else{
                temp->bottom = head1;
				temp = temp->bottom;
                head1 = head1->bottom;
            }
        }else{
            if(res == NULL){
                res = temp = head2;
				head2 = head2->bottom;
			}
            else{
                temp->bottom = head2;
                head2 = head2->bottom;
				temp = temp->bottom;
            }
        }
    }
    while(head1 != NULL){
        temp->bottom = head1;
        head1 = head1->bottom;
    }
    while(head2 != NULL){
        temp->bottom = head2;
        head2 = head2->bottom;
    }

    res->next = NULL;
    return res;
}

node *flatten(node *root){

    if(root == NULL || root->next == NULL)
        return root;

    node *temp = flatten(root->next);
    root = merge(root,temp);

    return root;
}

int main(){

    

    return 0;
}