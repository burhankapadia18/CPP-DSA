#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
// template<typename T>
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define ESPILON         1e-9
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)


void file_i_o()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

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

// inplace mergesort
void merge_ip(int arr[], int start, int mid, int end) {
    int start2 = mid + 1;
    if (arr[mid] <= arr[start2]) {
        return;
    }
    while (start <= mid && start2 <= end) {
        if (arr[start] <= arr[start2]) {
            start++;
        } else {
            int value = arr[start2];
            int index = start2;
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;
            start++;
            mid++;
            start2++;
        }
    }
}
void mergeSort_ip(int arr[], int l, int r) {
    if (l >= r)
        return;
    
    int m = mid(l,r);
    mergeSort_ip(arr, l, m);
    mergeSort_ip(arr, m + 1, r);
    merge_ip(arr, l, m, r);

}
//********************************************************
class node {
public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};
// for linkedList
node *find_middle(node *head) {
	if(head==NULL || head->next==NULL)
        return head;
    node *slowptr=head, *fastptr=head;
    while(fastptr!=NULL && fastptr->next!=NULL) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    return slowptr;
}
node *merge_LL(node *head1, node *head2) {
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head2;
    node *result;
    if(head1->data < head2->data) {
        result = head1;
        result->next = merge_LL(head1->next,head2);
    } else {
        result = head2;
        result->next = merge_LL(head2->next,head1);
    }
    return result;
}
node *mergesort_LL(node *head) {
    if(head==NULL || head->next==NULL)
        return head;
    node *head1;
    node *head2;
    node *mid;
    node *prevMid;
    head1 = head;
    mid = find_middle(head);
    prevMid = head;
    while(prevMid->next != mid)
        prevMid = prevMid->next;
    prevMid->next = NULL;
    head2 = mid;
    head1 = mergesort_LL(head1);
    head2 = mergesort_LL(head2);
    return merge_LL(head1,head2);
}
//***************************************************

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    int arr[n];
    loop(i,0,n-1)
        cin>>arr[i];

    mergeSort_ip(arr,0,n-1);
    loop(i,0,n-1)
        cout<<arr[i]<<" ";
    
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}