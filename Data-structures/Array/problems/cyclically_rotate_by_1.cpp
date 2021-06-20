#include<bits/stdc++.h>
using namespace std;

// Given an array, cyclically rotate an array by one.

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    int temp = a[n-1];
    int prev = a[0];
    for(int i=1; i<n; i++) {
        int t = a[i];
        a[i] = prev;
        prev = t;
    }
    a[0] = temp;

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
