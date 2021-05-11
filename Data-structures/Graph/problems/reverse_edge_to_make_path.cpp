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

// https://www.geeksforgeeks.org/minimum-edges-reverse-make-path-source-destination/

int minEdgeReverse(int src, int dest, vector<int> adj[], int n) {
    vector<pair<int,int> > newAdj[n];
    loop(u,0,n-1) {
        for(int v:adj[u]) {
            newAdj[u].push_back(make_pair(v,0));
            newAdj[v].push_back(make_pair(u,1));
        }
    }
    vector<int> dist(n,INT_MAX);
    vector<int> vis(n,0);
    set<pair<int,int> > S;
    dist[src] = 0;
    S.insert(make_pair(0,src));
    while(!S.empty()) {
        auto i = S.begin();
        int u = i->second;
        int cost = i->first;
        S.erase(i);
        vis[u] = 1;
        if(u == dest)
            return cost;
        for(auto j:newAdj[u]) {
            int v = j.ff;
            int w = j.ss;
            if(!vis[v] and ((dist[u]+w) < dist[v])) {
                S.erase(make_pair(dist[v],v));
                dist[v] = dist[u] + w;
                S.insert(make_pair(dist[v],v));
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, e;
    cin>>n>>e;
    int src, dest;
    cin>>src>>dest;
    vector<int> adj[n];
    loop(i,0,e-1) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    cout<<minEdgeReverse(src,dest,adj,n);


    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}