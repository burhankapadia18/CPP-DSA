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

// https://practice.geeksforgeeks.org/problems/cutted-segments/0

int maximizeCut(int n, int x, int y, int z, vector<int> &dp) {
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    if(dp[n] != -1) return dp[n];

    int opt1, opt2, opt3;
    opt1 = maximizeCut(n-x,x,y,z,dp);
    opt2 = maximizeCut(n-y,x,y,z,dp);
    opt3 = maximizeCut(n-z,x,y,z,dp);

    return dp[n] = 1+max(opt1,max(opt2,opt3));
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    int x, y, z;
    cin>>x>>y>>z;

    vector<int> dp(n+1,-1);
    int ans = maximizeCut(n,x,y,z,dp);
    if(ans < 0) cout<<0;
    else cout<<ans;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}