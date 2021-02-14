#include<bits/stdc++.h>
using namespace std;

// For Array
void swap(int &a, int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}
int Partition(int ar[], int start, int end)
{
    int pivot = ar[end];
    int pIndex = start;
    for(int i=start; i<end; i++){
        if(ar[i] <= pivot){
            swap(ar[i],ar[pIndex]);
            pIndex++;
        }
    }
    swap(ar[pIndex],ar[end]);

    return pIndex;
}
void QuickSort(int ar[], int start, int end)
{
    if(start < end){
        int pIndex = Partition(ar,start,end);
        QuickSort(ar,start,pIndex-1);
        QuickSort(ar,pIndex+1,end);
    }
}
// ***********************************************

// For LinkedList
class node 
{
    public:
	int data;
	node *next;
	node(int info){
		data = info;
		next = NULL;
	}
};
pair<node*,node*> partition(node *head, int pivot)
{
    node *fhead=NULL, ftail=NULL;
    node *lhead=NULL, ltail=NULL;

    while(head != NULL)
    {
        
    }
}


int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int ar[n];
    for(int i=0; i<n; i++)
        cin>>ar[i];

    QuickSort(ar,0,n-1);

    for(int i=0; i<n; i++)
        cout<<ar[i]<<" ";

    return 0;
}