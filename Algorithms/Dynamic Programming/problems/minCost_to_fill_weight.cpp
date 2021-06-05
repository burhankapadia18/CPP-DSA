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

// https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

int minCost(vector<int> &arr, int n, int w, vector<vector<int> > &dp) {
    // code is correct but still not working on local machine
    if(n==-1 and w==0) return 0;
    if(n == -1) return INT_MAX;
    if(w == 0) return 0;

    if(dp[n][w] != -1) return dp[n][w];
    
    if((n+1)>w or arr[n]==-1) return dp[n][w] = minCost(arr,n-1,w,dp);
    int x = minCost(arr,n-1,w,dp);
    int y = arr[n] + minCost(arr,n-1,w-n+1,dp);
    cout<<x<<" "<<y<<endl;
    return dp[n][w] = min(x,y);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, w;
    cin>>n>>w;
    vector<int> arr(n);
    vector<vector<int> > dp(n,vector<int>(w,-1));
    loop(i,0,n-1) cin>>arr[i];

    cout<<minCost(arr,n-1,w,dp);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}