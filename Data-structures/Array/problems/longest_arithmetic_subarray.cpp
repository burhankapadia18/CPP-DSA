#include<iostream>
using namespace std;

void longest_arithmetic_subarray(int a[], int n){
    int d = a[1]-a[0];
    int cur = 2;
    int ans = 2;
    int j = 2;
    while(j<n){
        if(a[j]-a[j-1] == d)
            cur++;
        else {
            d = a[j]-a[j-1];
            cur = 2;
        }
        ans = max(cur,ans);
        j++;
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

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    longest_arithmetic_subarray(a,n);

    return 0;
}