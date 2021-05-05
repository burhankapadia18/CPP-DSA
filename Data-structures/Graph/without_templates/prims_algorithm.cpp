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

void Prims(vector<pair<int,int> > adj[], int n) {
    vector<int> parent(n);
    vector<int> key(n);
    set<pair<int,int> > s;
    vector<bool> inSet(n);
    key[0] = 0;
    parent[0] = -1;
    inSet[0] = 1;
    s.insert(make_pair(key[0],0));
    loop(i,1,n-1) {
        parent[i] = -1;
        key[i] = INT_MAX;
        s.insert(make_pair(key[i],i));
        inSet[i] = 1;
    }
    while(!s.empty()) {
        auto i = s.begin();
        int u = i->second;
        s.erase(i);
        inSet[u] = 0;
        for(auto j:adj[u]) {
            int v = j.ff;
            int w = j.ss;
            if(inSet[v] and w<key[v]) {
                s.erase(make_pair(key[v],v));
                key[v] = w;
                parent[v] = u;
                s.insert(make_pair(key[v],v));
            }
        }
    }
    loop(i,1,n-1)
        cout<<parent[i]<<"\t-\t"<<i<<endl;
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

    Prims(adj,v);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}