#include<iostream>
using namespace std;

int kadane(int a[], int n){
    int currsum=0, maxsum = INT_MIN;
    for(int i=0; i<n; i++){
        currsum += a[i];
        if(currsum <0){
            currsum = 0;
        }
        maxsum = max(currsum, maxsum);
    }
    return maxsum;
}

int maxsum_circular_subarray(int a[], int n){
    int nonwrapsum = kadane(a,n);
    int wrapsum;
    int totalsum = 0;
    for(int i=0; i<n; i++){
        totalsum += a[i];
        a[i] = -a[i]; 
    }
    wrapsum = totalsum + kadane(a,n);
    return max(wrapsum,nonwrapsum);
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

    cout<<maxsum_circular_subarray(a,n);

    return 0;
}