#include<bits/stdc++.h>
using namespace std;

void merge_o1space(int a[], int n, int b[], int m)
{
    for(int i=m-1; i>=0; i--)
    {
        int last = a[n-1];
        int j;
        for(j=n-2; j>=0 && a[j]>b[i]; j--)
        {
            a[j+1] = a[j];
        }
        if(j!=n-2 || last>b[i])
        {
            a[j+1] = b[i];
            b[i] = last;
        }
    }
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

    int n,m;

    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    cin>>m;
    int b[m];
    for(int i=0; i<m; i++)
        cin>>b[i];

    merge_o1space(a,n,b,m);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    for(int i=0; i<m; i++)
        cout<<b[i]<<" ";

    return 0;
}
