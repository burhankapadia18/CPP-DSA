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

/*
Problem Name: Tilling Problem - II
Problem Difficulty: 2
Problem Constraints: 1 <= T<= 1000 <br>
1 <= N,M <= 100000
Problem Description:
Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m. A tile can either be placed horizontally or vertically.

Input Format: First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and M.
Sample Input: 2
2 3
4 4
Output Format: Print answer for every test case in a new line modulo 10^9+7.
Sample Output: 1
2
*/

// recurisve
int solve(int n, int m) {
    if(n<0)
        return 0;
    if(n==0) 
        return 1;
    return solve(n-1,m)+solve(n-m,m);
}

// DP
int solve_(int n, int m) {
    int dp[n+1];
    dp[0] = 1;
    loop(i,1,n) {
        dp[i] = (dp[i-1] + (i-m<0?0:dp[i-m]))%mod;
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        cout<<solve(n,m)<<" "<<solve_(n,m)<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}