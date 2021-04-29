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
Given two strings: string X of length m [X(1..m)], and string Y 
of length n [Y(1..n)], find the longest common subsequence: the 
longest sequence of characters that appear left-to-right (but not 
necessarily in a contiguous block) in both strings. For example, 
if X = “ABCBDAB” and Y = “BDCABA”, the LCS(X, Y) = {“BCBA”, “BDAB”,
 “BCAB”}.
*/

// DP solution top-dwon
int LCS(string &s1, string &s2, int i, int j, vector<vector<int> > &dp) {
    if(i == s1.length() or j == s2.length())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s1[i] == s2[j])
        return dp[i][j] = ( 1 + LCS(s1,s2,i+1,j+1,dp));
    return dp[i][j] = max(LCS(s1,s2,i+1,j,dp),LCS(s1,s2,i,j+1,dp));
}

// DP solution bottom-up
int LCS_dp(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int> > dp(n+1, vector<int> (m+1));
    loop(i,0,n) 
        dp[i][m] = 0;
    loop(i,0,m)
        dp[n][i] = 0;
    looprev(i,n-1,0) {
        looprev(j,m-1,0) {
            dp[i][j] = dp[i+1][j+1]; //matching s1[i]to s2[j]
            if(s1[i] == s2[j])
                dp[i][j]++; //we get a matching pair
            //the other two cases - inserting aa gap
            if(dp[i][j+1] > dp[i][j])
                dp[i][j] = dp[i][j+1];
            if(dp[i+1][j] > dp[i][j])
                dp[i][j] = dp[i+1][j];
        }
    }
    // loop(i,0,n) {
    //     loop(j,0,m)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return dp[0][0];
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length(), m = s2.length();
    vector<vector<int> > dp(n, vector<int> (m,-1));
    cout<<LCS(s1,s2,0,0,dp)<<" "<<LCS_dp(s1,s2);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}