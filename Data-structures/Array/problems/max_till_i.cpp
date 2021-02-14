#include<iostream>
using namespace std;

void max_till_i(int ar[], int n){
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        mx = max(mx,ar[i]);
        cout<<mx<<" ";
    }
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int ar[n];
    for(int i=0; i<n; i++)
        cin>>ar[i];

    max_till_i(ar,n);

    return 0;
}