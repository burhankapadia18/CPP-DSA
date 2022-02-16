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

// https://www.codechef.com/CENS2020/problems/CENS20A

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m)), prefix(n+2,vector<int>(m+2,0));
    string s;
    for(int i=0; i<n; i++) {
        cin>>s;
        for(int j=0; j<s.length(); j++)
            arr[i][j] = s[j]-'0';
    }
    int q, x1, y1, x2, y2;
    cin>>q;
    while(q--) {
        cin>>x1>>y1>>x2>>y2;
        prefix[x1][y1]++;
        prefix[x1][y2+1]--;
        prefix[x2+1][y1]--;
        prefix[x2+1][y2+1]++;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            prefix[i][j] = prefix[i][j]&1;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(prefix[i][j]) arr[i-1][j-1] ^= 1;
            cout<<arr[i-1][j-1];
        }
        cout<<endl;
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