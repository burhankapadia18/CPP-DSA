#include<bits/stdc++.h>
using namespace std;

void deleteDups(node *head){
    // to remove duplicate in a unsorted linked list
    set<int> s;
    node *prev = NULL;
    while(head != NULL){
        if(s.count(head->data)){
            prev->next = head->next;
        }
        else {
            s.insert(head->data);
            prev = head;
        }
        head = head->next;
    }
}