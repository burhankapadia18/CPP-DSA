/*
 recursive
*/
node *reverse_in_pair(node *head){
    node *temp;
    if(head == NULL || head->next == NULL)
        return head;
        else {
            temp = head->next;
            head->next = temp->next;
            temp->next = head;
            head = temp;
            head->next->next = reverse_in_pair(head->next->next);
            return head;
        }
}

/*
 iterative
*/
