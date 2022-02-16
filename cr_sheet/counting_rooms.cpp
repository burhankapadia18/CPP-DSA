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

// https://cses.fi/problemset/task/1192

void dfs(int i, int j, vector<vector<bool>> &vis, vector<string> &arr) {
    int n=arr.size(), m=arr[0].size();
    vis[i][j] = 1;
    int x[] = {0,0,1,-1};
    int y[] = {1,-1,0,0};
    loop(k,0,3) {
        int r = i+x[k],c = j+y[k];
        if(r>=0 and r<n and c>=0 and c<m and arr[r][c]=='.' and !vis[r][c]) {
            dfs(r,c,vis,arr);
        }
    }
} 
void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> arr(n);
    loop(i,0,n-1) {
        cin>>arr[i];
    }
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    int ans = 0;
    loop(i,0,n-1) {
        loop(j,0,m-1) {
            if(arr[i][j]=='.' and !vis[i][j]) {
                dfs(i,j,vis,arr);
               ans++;
            }
        }
    }
    cout<<ans;
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