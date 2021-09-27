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
Problem Name: Palindromic Queries 
Problem Difficulty: None
Problem Constraints: n <= 1000


m <= 100000
Problem Description:
Given a string s and m queries .
Each query consists of (l,r) where 1 <= l <= r <= n(size of string).

You need to print whether l to r is a palindromic string or not.  

A string can be called palindrome if its reverse is same as itself . Ex - "aba" .

Input Format: First line contains n 
Second lines contains a string of length n.
Next line contains m where m is the number of queries .
Next m lines contains two integers l,r as described in the question.
Sample Input: 5
abbac
2
1 4
2 4
Output Format: for every query from l to r print "YES" if s[l.....r] is palindrome else print "NO" without quotes in a new line.
Sample Output: YES
NO
*/

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string str;
    cin>>str;
    int n = str.length();
    bool dp[n][n];
    loop(i,0,n-1) dp[i][i] = 1;
    loop(i,0,n-2) dp[i][i+1] = 1;
    loop(k,3,n) {
        loop(i,0,n-k) {
            int j = i+k-1;
            if(str[i]==str[j]) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = 0;
        }
    }
    int m;
    cin>>m;
    while(m--) {
        int l, r;
        cin>>l>>r;
        cout<<dp[l-1][r-1]<<endl;
    }


    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}