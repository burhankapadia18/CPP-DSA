#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void dnfSort(int a[], int n) {
    
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[mid],a[low]);
            mid++; low++;
        }
        else if(a[mid]==1)
            mid++;
        else {
            swap(a[mid],a[high]);
            high--;
        }
    }
}

int main(int argc, char const *argv[])
{   
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    dnfSort(a,n);
    for(int i:a)
        cout<<i<<" ";
    return 0;
}
