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

// https://cses.fi/problemset/task/1674


void solve1() {
    // failed in 2 test cases
    int n;
    cin>>n;
    vector<int> sbord(n-1);
    loop(i,0,n-2) cin>>sbord[i];

    vector<int> ans(n+1,0);

    loop(i,2,n) {
        int t = sbord[i-2];
        while(1) {
            ans[t]++;
            if(t-2 >= 0) t = sbord[t-2];
            else break;
        }
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
}

void countSubord(int u, vector<int> &ans, vector<int> tree[]) {
    for(int v:tree[u]) {
        countSubord(v,ans,tree);
        ans[u] += 1+ans[v];
    }
}
void solve2() {
    int n;
    cin>>n;
    vector<int> tree[n+2];
    loop(i,2,n) {
        int x; cin>>x;
        tree[x].push_back(i);
    }
    vector<int> ans(n+1,0);
    countSubord(1,ans,tree);
    loop(i,1,n) cout<<ans[i]<<" ";
}


int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    solve2();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}