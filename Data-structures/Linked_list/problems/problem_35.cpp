/*
• Store the mid and last pointers of the circular linked list 
  using Floyd cycle finding algorithm.
• Make the second half circular.
• Make the first half circular.
• Set head pointers of the two linked lists.
*/

void split_list(Cnode *head, Cnode **head1, Cnode **head2){
    Cnode *fptr = head, *sptr = head;
    while(fptr->next != head && fptr->next->next != head){
        fptr = fptr->next->next;
        sptr = sptr->next;
    }
    /*
     if odd no .of Cnodes => fptr->next is head
     if even no. of Cnodes => fptr->next->next is head
    */
   if(fptr->next == head){          // in case of odd
		*head2 = sptr->next;
		*head1 = head;
		sptr->next = *head1;
		fptr->next = *head2;
   }
   else {	                      // in case of even
	   *head2 = sptr->next;
	   *head1 = head;
	   sptr->next = *head1;
	   fptr->next->next = *head2;
   }
}