#include<iostream>
using namespace std;

int isArraySorted(int a[], int n){
    if(n == 1)
        return 1;
    if( a[n-1] < a[n-2])
        return 0;
    else 
        return isArraySorted(a,n-1);
}

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

    cout<<isArraySorted(a,n);

    return 0;
}