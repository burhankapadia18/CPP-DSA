#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define uset 			unordered_set
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;


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

// HOLI spoj (pigeonhole principle)
int dfs(list<pair<int,int>> graph[], int &n, int src, vector<bool> &vis, vector<int> &cnt, int &ans) {
    vis[src] = 1;
    cnt[src] = 1;
    for(auto p:graph[src]) {
        int v = p.ff, wt = p.ss;
        if(!vis[v]) {
            cnt[src] += dfs(graph,n,v,vis,cnt,ans);
            int nx = cnt[v];
            int ny = n - nx;
            ans += 2*min(nx,ny) * wt;
        }
    }
    return cnt[src];
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        list<pair<int,int>> graph[n];
        loop(i,1,n-1) {
            int x, y, z;
            cin>>x>>y>>z;
            graph[x-1].push_back({y-1,z});
            graph[y-1].push_back({x-1,z});
        }
        vector<bool> vis(n,0);
        vector<int> cnt(n,0);
        int ans=0;
        dfs(graph,n,0,vis,cnt,ans);
        cout<<ans<<endl;
    }


    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}