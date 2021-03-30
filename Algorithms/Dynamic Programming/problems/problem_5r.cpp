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
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

// https://www.spoj.com/problems/MCOINS/



int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll k, l ,m;
    cin>>k>>l>>m;
    vi queries(m);
    loop(i,0,m-1)
        cin>>queries[i];

    vi dp(1000005,0);
    dp[1] = 1;
    dp[k] = 1;
    dp[l] = 1;
    loop(i,2,1000000) {
        if(i==k || i==l) continue;
        if(dp[i-1] == 0) dp[i] = 1;
        if(i-k >= 0 and dp[i-k] == 0) dp[i] = 1;
        if(i-l >= 0 and dp[i-l] == 0) dp[i] = 1;
    }
    loop(i,0,queries.size()-1)
        if(dp[queries[i]] == 1) cout<<"A";
        else cout<<"B";

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}