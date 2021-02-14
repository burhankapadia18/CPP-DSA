#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void move_neagtive(int a[], int n) {
    int p=0, q=0;
    while(q<n && p<n){
        if(a[q]<0)
            q++;
        else {
            swap(a[p],a[q]);
            p++;
        }
    }
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    move_neagtive(a,n);
    for(int i:a)
        cout<<i<<" ";

    return 0;
}
