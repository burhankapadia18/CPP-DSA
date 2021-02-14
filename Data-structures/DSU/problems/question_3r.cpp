#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
// template<typename T>
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define ESPILON         1e-9
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)


void file_i_o()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

/*
Question :-
You have given an undirected graph and some operations
    cut a-b : remove edge a-b
    ask a,b : whether a and b are in same connected component or not
(each edge will be cut once)

no. of vertices <= 5 x 10^3
no. of edges <= 10^5
no. of queries <= 10^5
*/

ll Get(vi &parent, ll a)
{
    return parent[a] = (parent[a]==a?a:Get(parent,parent[a]));
}
void Union(vi &parent, vi &rank, ll a, ll b)
{
    a = Get(parent,a);
    b = Get(parent,b);
    if(rank[a] == rank[b]) rank[a]++;
    if(rank[a] > rank[b]) parent[b] = a;
    else parent[a] = b;
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    file_i_o();

    // write your code here
    ll n, m, Q;
    cin>>n>>m>>Q;
    vi parent(n+1), rank(n+1,0);
    loop(i,0,n)
        parent[i] = i;

    loop(i,0,m-1)
    {   // just taking edges
        int u, v;
        cin>>u>>v;
    }
    vector<pii> qval;
    vi qtype;
    loop(i,0,Q-1)
    {
        string str;
        cin>>str;
        int a, b;
        cin>>a>>b;
        qval.push_back(make_pair(a,b));
        if(str == "cut") qtype.push_back(1);
        else qtype.push_back(2);
    }
    reverse(qval.begin(),qval.end());
    reverse(qtype.begin(),qtype.end());
    vector<string> result;
    loop(i,0,Q-1)
    {
        ll a = qval[i].ff;
        ll b = qval[i].ss;
        if(qtype[i] == 1)
            Union(parent,rank,a,b);
        else 
        {
            if(Get(parent,a) == Get(parent,b))
                result.push_back("yes");
            else 
                result.push_back("no");
        }
    }
    reverse(result.begin(),result.end());
    for(auto i:result)
        cout<<i<<endl;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}