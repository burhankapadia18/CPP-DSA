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

// https://lightoj.com/problem/funny-knapsack

ll solve() {
    ll n, w;
    cin>>n>>w;
    vector<ll> a1, a2;
    for (ll i=0; i<n/2; i++) {
        int x; cin>>x;
        a1.push_back(x);
    }
    for (ll i=n/2; i<n; i++) {
        ll x; cin>>x;
        a2.push_back(x);
    }
    ll n1 = n/2;
    ll n2 = n - n/2;
    vector<ll> X;
    for (ll i=0; i<(1<<n1); i++) {
        ll x=0, idx=0, mask=i;
        while(mask>0) {
            if (mask&1) x += a1[idx];
            idx++;
            mask>>=1;
        }
        X.push_back(x);
    }
    sort(X.begin(),X.end());
    ll ans = 0;
    for (ll i=0; i<(1<<n2); i++) {
        ll y=0, idx=0, mask = i;
        while(mask>0) {
            if (mask&1) y += a2[idx];
            idx++; 
            mask>>=1;
        }
        int p = upper_bound(X.begin(),X.end(),w-y) - X.begin();
        if(X[p-1] <= w-y) ans += p;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here

    int t;
    cin>>t;
    loop(i,1,t) cout<<"Case "<<i<<": "<<solve()<<endl;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}