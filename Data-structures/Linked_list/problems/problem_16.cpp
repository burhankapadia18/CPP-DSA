void reverse_ll1(node *head){
		//iterative method
		node *current = head, *prev=NULL, *next;
		while(current != NULL){
			next = current->link;
			current->link = prev;
			prev = current;
			current = next;
		}
		head = prev;
}
void reverse_ll2(node *p){
		//recursive method
		if(head->link == NULL){
			head = p;
			return;
		}
		reverse_ll2(head->link);
		head->link->link = head;
		head->link = NULL;
}