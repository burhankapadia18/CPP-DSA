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

// https://www.geeksforgeeks.org/bridge-in-a-graph/

void dfs(int u, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int timer, vector<int> adj[]) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    for(int v:adj[u]) {
        if(v == parent) 
            continue;
        if(!vis[v]) {
            dfs(v,u,vis,tin,low,timer,adj);
            low[u] = min(low[u],low[v]);
            if(low[v] > tin[u]) {
                cout<<u<<" "<<v<<endl;
            }
        }
        else {
            low[u] = min(low[u],tin[v]);
        }
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    loop(i,1,m) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> tin(n+1,-1), low(n+1,-1), vis(n+1,0);
    int timer=1;
    loop(i,1,n) {
        if(!vis[i]) {
            dfs(i,-1,vis,tin,low,timer,adj);
        }
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}