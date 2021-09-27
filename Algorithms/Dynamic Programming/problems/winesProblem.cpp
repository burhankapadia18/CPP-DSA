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

// https://www.geeksforgeeks.org/maximum-profit-sale-wines/

// recursive method
int solve(int arr[], int i, int j, int yr) {
    if(i>j)
        return 0;
    if(i==j)
        return arr[i]*yr;
    int x, y;
    x = arr[i]*yr + solve(arr,i+1,j,yr+1);
    y = arr[j]*yr + solve(arr,i,j-1,yr+1);

    return max(x,y);
}

// dp approach
int solve(int arr[], int n) {
    int dp[n][n];
    // filling base case
    loop(i,0,n-1) dp[i][i] = arr[i]*n;
    int yr = n-1;
    for(int k=1; k<n; k++) {
        for(int i=0, j=k; i<n and j<n; i++, j++) {
            dp[i][j] = max(arr[i]*yr+dp[i+1][j],arr[j]*yr+dp[i][j-1]);
        }
        yr--;
    }
    return dp[0][n-1];
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

    cout<<solve(arr,0,n-1, 1)<<" "<<solve(arr,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}