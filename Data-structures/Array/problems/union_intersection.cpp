#include<bits/stdc++.h>
using namespace std;

void union_intersection(int a[], int n, int b[], int m)
{
    set<int> merged;
    vector<int> intersection;

    for(int i=0; i<n; i++)
        merged.insert(a[i]);
    for(int i=0; i<m; i++)
        merged.insert(b[i]);
    
    int i,j;
    i=0, j=0;
    while(i<n && j<m)
    {
        if(a[i] < b[j])
            i++;
        else if(b[j] < a[i])
            j++;
        else {
            intersection.push_back(a[i]);
            i++; j++;
        }
    }

    cout<<"union : ";
    for(auto i:merged)
        cout<<i<<" ";
    cout<<"\nintersection : ";
    for(auto i:intersection)
        cout<<i<<" ";
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

    union_intersection(a,n,b,m);
    
    return 0;
}
  