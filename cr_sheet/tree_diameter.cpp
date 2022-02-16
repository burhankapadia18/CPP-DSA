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
int mx;
int dfs(int root, int parent, vector<int> tree[]) {
    int mx1=0, mx2=0, tmp;
    for(int &child:tree[root]) {
        if(child == parent) continue;
        tmp = dfs(child,root,tree);
        if(tmp>mx1) {
            mx2 = mx1;
            mx1 = tmp;
        }
        else if(mx2<tmp) {
            mx2 = tmp;
        }
        mx = max(mx,mx1+mx2+1);
    }
    return max(mx1,mx2)+1;
}
void solve() {
    int n;
    cin>>n;
    if(n == 1) {
       cout<<0; return; 
    }
    vector<int> tree[n+1];
    loop(i,1,n-1) {
        int a, b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    mx = 0;
    dfs(1,0,tree);
    cout<<mx-1;
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