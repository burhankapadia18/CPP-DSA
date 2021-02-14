/*
Efficient Approach: Use two pointers. Move one pointer at twice the speed of the second. 
When the first pointer reaches the end of the list, the second pointer will be pointing
to the middle node.
Note: If the list has an even number of nodes, the middle node will be of ⌊n/2⌋.
*/
void find_middle(){
	node *ptr1=head, *ptr2=head;
	while(ptr2->link && ptr2->link->link){
		ptr2 = ptr2->link->link;
		ptr1 = ptr1->link;
	}
	cout<<"middle is "<<ptr1->data;
}



void find_middle(){
	node *ptr1=head, *ptr2=head;
	while(ptr2 != NULL && ptr2->link != NULL){
		ptr2 = ptr2->link->link;
		ptr1 = ptr1->link;
	}
	cout<<"middle is "<<ptr1->data;
}