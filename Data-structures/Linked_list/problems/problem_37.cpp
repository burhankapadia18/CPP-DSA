/*
 1. Get the middle of the linked list.
 2. Reverse the second half of the linked list.
 3. Compare the first half and second half.
 4. Construct the original linked list by reversing the second half 
    again and attaching it back to the first half.
    
    Time Complexity: O(n). Space Complexity: O(1).
*/

node *reverse(node *head){
		//iterative method
		node *current = head, *prev=NULL, *next;
		while(current != NULL){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		return prev;
}

void check_pallindrome(node *head){
    node *fptr = head, *sptr = head;
    while(fptr->next != NULL && fptr->next->next != NULL){
        fptr = fptr->next->next;
        sptr = sptr->next;
    }
    sptr->next = reverse(sptr->next);
    fptr  = head;
	sptr = sptr->next;
	int c = 1;
    while(sptr != NULL){
        if(fptr->data != sptr->data){
			c = 0;
            break;
        }
        fptr = fptr->next;
		sptr = sptr->next;
    }
    if(c)
		cout<<"pallindrome";
	else
		cout<<"not a pallindrome";
	fptr->next = reverse(fptr->next);
}