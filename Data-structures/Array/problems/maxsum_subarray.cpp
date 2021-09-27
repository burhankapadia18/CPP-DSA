#include<bits/stdc++.h>
using namespace std;

//  Kadane's algorithm
int maxsum_subarray(int a[], int n){
    int currsum=0, maxsum = INT_MIN;
    for(int i=0; i<n; i++){
        currsum += a[i];
        maxsum = max(currsum, maxsum);
        if(currsum <0){
            currsum = 0;
        }
    }
    return maxsum;
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<maxsum_subarray(a,n);
}