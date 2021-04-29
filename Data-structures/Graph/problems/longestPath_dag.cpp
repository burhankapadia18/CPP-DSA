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

// https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

vector<int> order;
void topo(int u, vector<int> &vis, vector<pair<int,int> > adj[]) {
    vis[u] = 1;
    for(auto x:adj[u]) {
        int v = x.ff;
        if(!vis[v]) {
            topo(v,vis,adj);
        }
    }
    order.push_back(u);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int v, e, src;
    cin>>v>>e>>src;
    vector<pair<int,int> > adj[v];
    loop(i,1,e) {
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y,w));
    }
    vector<int> vis(v,0);
    loop(i,0,v-1) {
        if(!vis[i]) {
            topo(i,vis,adj);
        }
    }
    vector<int> dist(v,INT_MIN);
    dist[src] = 0;
    looprev(i,v-1,0) {
        int u = order[i];
        if(dist[u] != INT_MIN) {
            for(auto i:adj[u]) {
                int v = i.ff;
                int w = i.ss;
                if(dist[u]+w > dist[v]) {
                    dist[v] = dist[u] + w;
                } 
            }
        }
    }
    loop(i,0,v-1) {
        cout<<src<<"->"<<i<<" = "<<dist[i]<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}