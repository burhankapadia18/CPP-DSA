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

// https://www.spoj.com/problems/GNYR09F/

int dp[105][105][2];
ll AdjBc(int n, int k, int f) {
    if(n == 0)
        return 0;
    if(n == 1) {
        if(k == 0)
            return 1;
        else 
            return 0;
    }

    if(dp[n][k][f] != -1)
        return dp[n][k][f];
    ll result = -1;
    if(f == 0)
        result = AdjBc(n-1,k,0) + AdjBc(n-1,k,1);
    else 
        result = AdjBc(n-1,k,0) + AdjBc(n-1,k-1,1); 

    return dp[n][k][f] = result; 
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll t;
    cin>>t;
    while(t--) {
        ll num, n, k;
        cin>>num>>n>>k;
        memset(dp,-1,sizeof(dp));
        ll ans  = 0;
        ans += AdjBc(n,k,0);
        ans += AdjBc(n,k,1);
        cout<<num<<" "<<ans<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}