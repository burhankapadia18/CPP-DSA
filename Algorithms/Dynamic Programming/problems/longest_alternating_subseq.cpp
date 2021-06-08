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

// https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence/0

void longestAlternatingSubseq(int arr[], int n) {
    vector<vector<int> > dp(n,vector<int>(2,1));
    int ans = INT_MIN;
    loop(i,1,n-1) {
        loop(j,0,i-1) {
            if(arr[i]>arr[j] and dp[i][0]<dp[j][1]+1) 
                dp[i][0] = dp[j][1] + 1;
            else if(arr[i]<arr[j] and dp[i][1]<dp[j][0]+1)
                dp[i][1] = dp[j][0] + 1;
        }
        ans = max(ans,max(dp[i][0],dp[i][1]));
    }
    cout<<ans<<endl;

    // 2nd approach tc:O(n)
    int ma=1, mi=1;
    loop(i,1,n-1) {
        if(arr[i]>arr[i-1]) ma = mi+1;
        else if(arr[i]<arr[i-1]) mi = ma+1;
    }
    cout<<max(mi,ma);
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

    longestAlternatingSubseq(arr,n);


    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}