#include<bits/stdc++.h>
using namespace std;

// Given an array, cyclically rotate an array by one.

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    int temp = a[0];
    for(int i=0; i<n-1; i++)
        a[i] = a[i+1];
    a[n-1] = temp;

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
