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

/*
Given an array, find the longest subsequence which is strictly
increasing.
        3 1 2 5 4 6 5 6         ans = 5
*/

// top-dowm
int longestSubseq(vector<int> &arr, int i, int j,vector<int> &dp) {
    if(j == arr.size())
        return 1;

    if(dp[i] != -1)
        return dp[i];

    if(arr[j] > arr[i])
        return dp[i] = 1 + longestSubseq(arr,j,j+1,dp);

    return dp[i] = max(longestSubseq(arr,i+1,j+1,dp), longestSubseq(arr,i,j+1,dp));
}

// bottom-up
int longestSubseq(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n,1);
    loop(i,0,n-1) {
        loop(j,0,i-1) {
            if(arr[i] > arr[j])
                dp[i] = max(dp[i],1+dp[j]);
        }
    }
    int ans = INT_MIN;
    loop(i,0,n-1) ans = max(ans,dp[i]);
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<int> arr(n);
    loop(i,0,n-1)
        cin>>arr[i];

    vector<int> dp(n,-1);
    cout<<longestSubseq(arr,0,0,dp)<<" "<<longestSubseq(arr);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}