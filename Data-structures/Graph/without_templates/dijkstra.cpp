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

void dijkstra(vector<pair<int,int> > adj[], int V, int src) {
    set<pair<int,int> > S;
    vector<int> dist(V,INT_MAX), parent(V);
    dist[src] = 0;
    parent[src] = -1;
    S.insert(make_pair(dist[0],src));
    while(!S.empty()) {
        auto it = S.begin();
        int u = it->second;
        S.erase(it);
        for(auto i:adj[u]) {
            int v = i.ff;
            int w = i.ss;
            if(dist[u]+w < dist[v]) {
                parent[v] = u;
                S.erase(make_pair(dist[v],v));
                dist[v] = dist[u]+w;
                S.insert(make_pair(dist[v],v));
            }
        }
    }
    loop(i,0,V-1) {
        cout<<src<<"->"<<i<<":"<<dist[i]<<endl;
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

    dijkstra(adj,v,0);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}