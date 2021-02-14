#include<bits/stdc++.h>
using namespace std;

node *dnfSort(node *head) {

    if(head==NULL)
        return head;

    node *ls=NULL, *le=NULL;
    node *ms=NULL, *me=NULL;
    node *hs=NULL, *he=NULL;

    while(head != NULL) {
        node *nxt = head->next;
        head->next = NULL;
        if(head->data==0){
            if(ls==NULL){
                ls = le = head;
            } else {
                le->next = head;
                le = head;
            }
        } else if(head->data==1){
            if(ms==NULL){
                ms = me = head;
            } else {
                me->next = head;
                me = head;
            }
        } else {
            if(hs==NULL){
                hs = he = head;
            } else {
                he->next = head;
                he = head;
            }
        }
        head = nxt;
    }

    le->next = ms;  // corner cases are missing
    me->next = hs;

    return ls;
    
}