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

// https://www.geeksforgeeks.org/bipartite-graph/

bool f;
void dfs(int src, int parent, int color, vector<int> adj[], vector<int> &vis) {
    vis[src] = color;
    for(int x:adj[src]) {
        if(vis[x] == -1) {
            dfs(x,src,3-color,adj,vis);
        }
        else if(x!=parent and color==vis[x]) {
            f = 0;
            break;
        }
    }
}
bool isBipartite(vector<int> adj[], int V) {
    // doesn't worked in leetcode:886
    vector<int> vis(V+1,-1);
    f = 1;
    dfs(1,1,1,adj,vis);
    return f;
}

// using bfs
bool possibleBipartition(vector<int> graph[], int n) {
    vector<int> vis(n+1,-1);
    for(int i=1; i<=n; i++) {
        if(vis[i] != -1) continue;
        queue<int> Q;
        Q.push(i);
        vis[i] = 1;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int &v:graph[u]) {
                if(vis[v] == -1) {
                    Q.push(v); vis[v] = 3-vis[u];
                }
                else if(vis[v] == vis[u]) return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int V, E;
    cin>>V>>E;
    vector<int> adj[V+1];
    loop(i,1,E) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<isBipartite(adj,V);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}