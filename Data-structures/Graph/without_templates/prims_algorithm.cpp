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

void Prims(int src, vector<pair<int,int> > adj[], int n) {
    vector<int> parent(n), dist(n,INT_MAX);
    vector<bool> vis(n,0);
    set<pair<int,int> > S;
    dist[src] = 0;
    parent[src] = 0;
    S.insert(make_pair(0,src)); // (wt,vertex)
    int cost = 0;
    while(!S.empty()) {
        auto i = *(S.begin());
        S.erase(i);
        int u = i.ss;
        vis[u] = 1;
        int w = i.ff;
        cout<<u<<" "<<parent[u]<<" "<<w<<endl;
        cost += w;
        for(auto j:adj[u]) {
            int v = j.ff;
            int wt = j.ss;
            if(vis[v]) continue;
            if(dist[v] > wt) {
                S.erase(make_pair(dist[v],v));
                dist[v] = wt;
                S.insert(make_pair(dist[v],v));
                parent[v] = u;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int v, e;
    cin>>v>>e;
    vector<pair<int,int> > adj[v];
    while(e--) {
        int x, y, w;
        cin>>x>>y>>w;
       adj[x].push_back(make_pair(y,w));
       adj[y].push_back(make_pair(x,w));
    }

    Prims(0,adj,v);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}