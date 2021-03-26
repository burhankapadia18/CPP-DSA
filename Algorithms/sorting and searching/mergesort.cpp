#include<bits/stdc++.h>
using namespace std;

//*************************************
//for array
void merge(int arr[], int left[], int right[], int l, int r) {
    int i=0, j=0, k=0;
    while(i<l && j<r){
        if(left[i]<=right[j])
            arr[k++] = left[i++];
        else 
            arr[k++] = right[j++];
    }
    while(i<l)
        arr[k++] = left[i++];
    while(j<r)
        arr[k++] = right[j++];
}

void Mergesort(int arr[], int n) {
    if(n<2)
        return;
    int mid = n/2;
    int left[mid], right[n-mid];
    for(int i=0; i<mid; i++)
        left[i]=arr[i];
    for(int i=mid; i<n; i++)
        right[i-mid]=arr[i];
    Mergesort(left,mid);
    Mergesort(right,n-mid);
    merge(arr,left,right,mid,n-mid);
}
//*************************

// for linkedList

// node *find_middle(node *head)
// {
// 	if(head==NULL || head->next==NULL)
//         return head;

//     node *slowptr=head, *fastptr=head;
//     while(fastptr!=NULL && fastptr->next!=NULL)
//     {
//         slowptr = slowptr->next;
//         fastptr = fastptr->next->next;
//     }
    
//     return slowptr;
// }
// node *merge_LL(node *head1, node *head2)
// {
//     if(head1 == NULL)
//         return head2;
//     if(head2 == NULL)
//         return head2;

//     node *result;
//     if(head1->data < head2->data)
//     {
//         result = head1;
//         result->next = merge_LL(head1->next,head2);
//     }
//     else
//     {
//         result = head2;
//         result->next = merge_LL(head2->next,head1);
//     }

//     return result;
// }
// node *mergesort_LL(node *head)
// {
//     if(head==NULL || head->next==NULL)
//         return head;

//     node *head1;
//     node *head2;
//     node *mid;
//     node *prevMid;

//     head1 = head;
//     mid = find_middle(head);
//     prevMid = head;
//     while(prevMid->next != mid)
//         prevMid = prevMid->next;
//     prevMid->next = NULL;
//     head2 = mid;

//     head1 = mergesort_LL(head1);
//     head2 = mergesort_LL(head2);

//     return merge_LL(head1,head2);
// }
//***************************************************

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++) 
		cin>>a[i];
	
	Mergesort(a,n);

	for(int i=0; i<n; i++) 
		cout<<a[i]<<" ";

	return 0;
}