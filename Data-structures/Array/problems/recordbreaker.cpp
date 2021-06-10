#include<bits/stdc++.h>
using namespace std;

/*
Arrays Challenge-Record Breaker (Google kickstart)
*/

void record_breaker(int a[], int n){
    if(n==1){
        cout<<1;
        return;
    }
    int mx = INT_MIN;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(a[i]>mx && a[i]>a[i+1])
            ans++;
        mx = max(a[i],mx);
    }
    cout<<ans;
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int a[n+1];
    for(int i=0; i<n; i++)
        cin>>a[i];
    a[n] = -1;

    record_breaker(a,n);

    return 0;
}