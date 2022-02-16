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

// https://cses.fi/problemset/task/1135

void fill_level(int src, int par, int curr_lvl, vector<int> tree[], vector<int> &level) {
    level[src] = curr_lvl;
    for(int child:tree[src]) {
        if(child != par)
        fill_level(child,src,curr_lvl+1,tree,level);
    }
}
int lift_node(int node, int jump, vector<vector<int>> &up) {
    looprev(i,30,0) {
        if(jump==0 or node ==-1) break;
        int mask = (1<<i);
        if(jump >= mask) {
            jump -= mask;
            node = up[node][i];
        }
    }
    return node;
}
void binary_lifting(int src, int par, vector<int> tree[], vector<vector<int>> &up) {
    up[src][0] = par;
    loop(i,1,30) {
        if(up[src][i-1] != -1) up[src][i] = up[up[src][i-1]][i-1];
        else up[src][i-1] = -1;
    }
    for(int child:tree[src]) {
        if(child != par)
            binary_lifting(child,src,tree,up);
    }
}
int lca(int a, int b, vector<vector<int>> &up, vector<int> &level) {
    if(level[b]>level[a]) 
        swap(a,b);
    a = lift_node(a,level[a]-level[b],up);
    if(a == b) return a;
    looprev(i,30,0) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return lift_node(a,1,up);
}
void solve() {
    // tle in large test case n = 2 x 10^5
    int n, q;
    cin>>n>>q;
    vector<int> tree[n+1];
    loop(i,2,n) {
        int a, b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<vector<int>> up(n+1,vector<int>(31,-1));
    binary_lifting(1,-1,tree,up);
    vector<int> level(n+1);
    fill_level(1,0,0,tree,level);
    int a, b, c, ans;
    while(q--) {
        cin>>a>>b;
        c = lca(a,b,up,level);
        ans = level[a]-level[c]+level[b]-level[c];
        cout<<ans<<endl;
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    solve();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}