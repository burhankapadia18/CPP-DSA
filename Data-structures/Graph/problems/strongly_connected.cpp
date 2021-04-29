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

// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// kosaraju algorithm
bool onrev;
void dfs(vector<int> adj[], int u, vector<bool> &vis, vector<int> &order) {
    vis[u] = 1;
    for(int v:adj[u]) {
        if(!vis[v]) {
            dfs(adj,v,vis,order);
        }
    }
    if(!onrev)
        order.push_back(u);
}
int kosaraju(vector<int> adj[], int V) {
    vector<int> revAdj[V];
    loop(u,0,V-1) {
        for(int v:adj[u]) {
            revAdj[v].push_back(u);
        }
    }
    // loop(u,0,V-1) {
    //     cout<<u<<":";
    //     for(int v:revAdj[u]) {
    //         cout<<v<<",";
    //     }
    //     cout<<endl;
    // }
    vector<int> order;
    vector<bool> vis(V,0), vis1(V,0);
    onrev = 0;
    loop(i,0,V-1) {
        if(!vis[i]) {
            dfs(adj,i,vis,order);
        }
    }
    int ans = 0;
    reverse(order.begin(),order.end());
    onrev = 1;
    for(int i:order) {
        if(!vis1[i]) {
            ans++;
            dfs(revAdj,i,vis1,order);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int V, E;
    cin>>V>>E;
    vector<int> adj[V];
    loop(i,1,E) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    cout<<kosaraju(adj,V);


    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}