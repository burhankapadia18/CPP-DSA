int hasKnodes(node *head, int k){
    int i = 0;
    for(i=0; head && i<k; i++, head = head->next);
    if(i == k)
		return 1;
	return 0;
}
node *reverseInKgroups(node *head, int k){
	if(head == NULL)
		return NULL;
	if(k == 1 || k == 0 || !hasKnodes(head,k))
		return head;
	node *current = head, *next = NULL, *prev = NULL;
	int count = 0;
	while(current != NULL && count<k){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if(hasKnodes(current,k))
		head->next = reverseInKgroups(next,k);
	else
		head->next = current;
	return prev;
}