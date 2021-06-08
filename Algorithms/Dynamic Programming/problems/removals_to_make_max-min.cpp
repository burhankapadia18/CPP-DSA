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

// https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/

int removalsReq(int arr[], int i, int j, int &k, vector<vector<int> > &dp) {
    if(i >= j)
        return 0;
    
    if(arr[j]-arr[i] <= k)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = 1 + min(removalsReq(arr,i+1,j,k,dp),removalsReq(arr,i,j-1,k,dp));
}

int removalsReq(int arr[], int n, int k) {
    if(n==1)
        return 0;

    int ans = n-1;
    loop(i,0,n-1) {
        int j = upper_bound(arr+i,arr+n,arr[i]+k)-arr-1;
        ans = min(ans,n-(j-i+1));
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    int arr[n];
    loop(i,0,n-1) cin>>arr[i];
    int k;
    cin>>k;

    vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
    sort(arr,arr+n);
    cout<<removalsReq(arr,0,n-1,k,dp)<<" "<<removalsReq(arr,n,k);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}