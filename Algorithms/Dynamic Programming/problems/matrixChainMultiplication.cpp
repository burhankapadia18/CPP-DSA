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

// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

int dp[1005][1005];
int mcm(int arr[], int i, int j) {
    // top down approach
    if(i == j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    loop(k,i,j-1) {
        ans = min(ans,mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]));
    }
    return dp[i][j] = ans;
}
int mcm(int arr[], int n) {
    // bottom up
    int dp[n][n];
    loop(i,1,n-1) dp[i][i] = 0;
    for(int l=2; l<n; l++) {
        for(int i=1; i<n-l+1; i++) {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++) {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]));
            }
        }
    }
    return dp[1][n-1];
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

    memset(dp,-1,sizeof(dp));
    cout<<mcm(arr,1,n-1)<<" "<<mcm(arr,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}