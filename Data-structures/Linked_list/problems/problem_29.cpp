/*
Use a 2x pointer. Take a pointer that moves at 2x [two nodes at a time].
At the end, if the length is even, then the pointer will be NULL; otherwise it 
will point to the last node.
*/
void is_ll_lenght_even(node *head){
	node *ptr = head;
	while(ptr->link!=NULL && ptr!=NULL){
		ptr = ptr->link->link;
	}
	if(ptr)
		cout<<"odd";
	else
		cout<<"even";
}