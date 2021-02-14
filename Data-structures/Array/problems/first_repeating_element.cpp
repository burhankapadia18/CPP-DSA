#include<iostream>
using namespace std;

int first_repeating_element(int a[], int n){
    int N = 1e6;
    int idx[N];
    int mndix = INT_MAX;
    for(int i=0; i<N; i++)
        idx[i] = -1;
    for(int i=0; i<n; i++){
        if(idx[a[i]] != -1){
            mndix = min(mndix,idx[a[i]]);
        }
        else{
            idx[a[i]] = i;
        }
    }
    return mndix+1;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<first_repeating_element(a,n);

    return 0;
}