#include<iostream>
using namespace std;

void subarraySum(int a[], int n){
    int cur;
    for(int i=0; i<n; i++){
        cur = 0;
        for(int j=i; j<n; j++){
            cur += a[j];
            cout<<cur<<'\n';
        }
    }
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

    subarraySum(a,n);

    return 0;
}