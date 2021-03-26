#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif
}

int Get(vector<int> &parent, int a)
{   // path compression technique is also used
    return parent[a] = (parent[a]==a?a:Get(parent,parent[a]));
}
void Union(vector<int> &parent, vector<int> &rank, int a, int b)
{
    a = Get(parent,a);
    b = Get(parent,b);
    if(rank[a] == rank[b])
        rank[a]++;
    if(rank[a] > rank[b])
        parent[b] = a;
    else 
        parent[a] = b;
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1), rank(n+1,0);
    for(int i=0; i<=n; i++)
        parent[i] = i;
    while(m--)
    {
        string str;
        cin>>str;
        if(str == "union")
        {
            int x, y;
            cin>>x>>y;
            Union(parent,rank,x,y);
        } 
        else 
        {
            int x;
            cin>>x;
            cout<<Get(parent,x)<<endl;
        }
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}