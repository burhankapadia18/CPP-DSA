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
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif
}

// creating a edgelist
class Edge
{
public:
    ll src;
    ll dest;
    ll wt;
};

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

bool cmp(Edge e1, Edge e2)
{   // custom comparator for sort function
    return e1.wt < e2.wt;
}
void kruskals(Edge *input, ll n, ll e)
{
    sort(input,input+e,cmp);
    vi parent(n+1), rank(n+1,1);
    loop(i,0,n)
        parent[i] = i;

    Edge *output = new Edge[n-1];
    ll EdgeCount = 0;
    ll i = 0;
    while(EdgeCount < n-1)
    {
        Edge curr = input[i];
        ll srcParent = Get(parent,curr.src);
        ll destParent = Get(parent,curr.dest);
        if(srcParent != destParent)
        {
            output[EdgeCount] = curr;
            Union(parent,rank,srcParent,destParent);
            EdgeCount++;
        }
        i++;
    }
    ll tw = 0;
    loop(j,0,EdgeCount-1)
        tw += output[j].wt;
    cout<<tw;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll n, e;
    cin>>n>>e;
    Edge edgelist[e];
    loop(i,0,e-1) {
        int u, v, w;
        cin>>u>>v>>w;
        edgelist[i].src = u;
        edgelist[i].dest = v;
        edgelist[i].wt = w;
    }

    kruskals(edgelist,n,e);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}