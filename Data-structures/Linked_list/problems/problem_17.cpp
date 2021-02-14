/*
• Find lengths (L1 and L2) of both lists - O(n) + O(m) = O(max(m, n)).
• Take the difference d of the lengths -- O(1).
• Make d steps in longer list -- O(d).
• Step in both lists in parallel until links to next node match -- O(min(m, n)).
• Total time complexity = O(max(m, n)).
• Space Complexity = O(1).
*/
void find_intersecting_node(linked_list *l1, linked_list *l2) {
	int len1=0, len2=0, diff=0;
	node *head1=get_head(l1), *head2=get_head(l2);
	while(head1!=NULL){
		len1++;
		head1 = head1->next;
	}
	while(head2!=NULL){
		len2++;
		head2 = head2->next;
	}
	if(len1<len2){
		head1 = get_head(l2);
		head2 = get_head(l1);
		diff = len2-len1;
	}
	else {
		head1 = get_head(l1);
		head2 = get_head(l2);
		diff = len1-len2;
	}
	while(diff){
		head1 = head1->next;
		diff--;
	}
	while(head1!=NULL && head2!=NULL){
		if(head1 == head2){
			cout<<"intersecting node is "<<head1->data;
			return;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	cout<<"no intersecting node";
}