#include<iostream>
using namespace std;

int missing_number(int a[], int n){
    int N = 1e6;
    bool check[N];
    for(int i=0; i<n; i++)
        if(a[i]>=0)
            check[a[i]] = 1;
    for(int i=0; i<N; i++){
        if(check[i] == 0){
            return i;
        }
    }
    return -1;
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

    cout<<missing_number(a,n);

    return 0;
}