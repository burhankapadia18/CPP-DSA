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

// https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/

int maxSubSum(vector<int> &arr, int i, vector<int> &dp) {

    if(i == arr.size()) return 0;
    if(i == arr.size()-1) return arr[i];
    if(i == arr.size()-2) return arr[i]+arr[i+1];

    if(dp[i] != -1) return dp[i];
    
    int case1 = maxSubSum(arr,i+1,dp);
    int case2 = arr[i] + maxSubSum(arr,i+2,dp);
    int case3 = arr[i] + arr[i+1] + maxSubSum(arr,i+3,dp);

    return dp[i] = max(case1,max(case2,case3));
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<int> arr(n), dp(n,-1);

    loop(i,0,n-1) cin>>arr[i];

    cout<<maxSubSum(arr,0,dp);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}