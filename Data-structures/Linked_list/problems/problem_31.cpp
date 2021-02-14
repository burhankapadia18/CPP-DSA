/*
 recurisve solution
*/
node *mergeSortedLinkedList(node *head1, node *head2){
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    node *result = NULL;
    if(head1->data <= head2->data){
        result = head1;                     
        result->next = mergeSortedLinkedList(head1->next,head2);
    }else {
        result = head2;
        result->next = (head2->next,head1);
    }  
    return result;  
}

/*
 iterative solution
*/
node *mergeSortedLinkedList_1(node *head1, node *head2){
    node *result = NULL; 
	node *p3;
    node *p1 = head1, *p2 = head2;
    while(p1 != NULL && p2 != NULL){
        if(p1->data <= p2->data){
            if(result == NULL){
                result = p3 = p1;
				p1 = p1->next;
			}
            else{
                p3->next = p1;
				p3 = p3->next;
                p1 = p1->next;
            }
        }else{
            if(result == NULL){
                result = p3 = p2;
				p2 = p2->next;
			}
            else{
                p3->next = p2;
                p2 = p2->next;
				p3 = p3->next;
            }
        }
    }
    while(p1 != NULL){
        p3->next = p1;
        p1 = p1->next;
    }
    while(p2 != NULL){
        p3->next = p2;
        p2 = p2->next;
    }
    return result;
}