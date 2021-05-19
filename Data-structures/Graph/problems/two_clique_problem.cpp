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

// https://www.geeksforgeeks.org/two-clique-problem-check-graph-can-divided-two-cliques/

bool f;
void dfs(int src, int parent, int color, vector<int> adj[], vector<int> &vis) {
    vis[src] = color;
    for(int x:adj[src]) {
        if(vis[x] == -1) {
            dfs(x,src,3-color,adj,vis);
        }
        else if(x!=parent and color==vis[parent]) {
            f = 1;
            break;
        }
    }
}
bool isClique(vector<int> adj[], int n) {
    vector<int> reverse[n+1], temp(n+1,0);
    loop(u,1,n) {
        temp[u] = 1;
        for(int v:adj[u]) {
            temp[v] = 1;
        }
        loop(i,1,n) {
            if(temp[i] == 0) {
                reverse[u].push_back(i);
            }
            temp[i] = 0;
        }
    }
    f = 0;
    vector<int> vis(n+1,-1);
    dfs(1,1,1,reverse,vis);
    return !f;
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
    if(isClique(adj,n))
        cout<<"is clique";
    else 
        cout<<"not a clique";

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}