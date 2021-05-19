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

// https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

// DP solution top-dwon
int LCS_td(string &s1, string &s2, int i, int j, vector<vector<int> > &dp) {
    if(i == s1.length() or j == s2.length())
        return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = ( 1 + LCS_td(s1,s2,i+1,j+1,dp));
    return dp[i][j] = max(LCS_td(s1,s2,i+1,j,dp),LCS_td(s1,s2,i,j+1,dp));
}

// DP solution bottom-up
int LCS_bu(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int> > dp(n+1, vector<int> (m+1));
    loop(i,0,n) dp[i][m] = 0;
    loop(i,0,m) dp[n][i] = 0;
    looprev(i,n-1,0) {
        looprev(j,m-1,0) {
            if(s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1] + 1; //we get a matching pair
            else dp[i][j] = max(dp[i+1][j],dp[i][j+1]); //the other two cases - inserting aa gap
        }
    }
    return dp[0][0];
}

// space optimized solution
int LCS_so(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int> > dp(2,vector<int>(m+1,0));
    loop(i,0,n) {
        loop(j,0,m) {
            if(i==0 or j==0)
                dp[i%2][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i%2][j] = dp[(i+1)%2][j-1] + 1;
            else 
                dp[i%2][j] = max(dp[i%2][j-1],dp[(i+1)%2][j]);
        }
    }
    return dp[n%2][m];
}

// LCS on 3 strings
int LCSof3(string &s1, string &s2, string &s3) {
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();
    vector<vector<vector<int> > > dp(l1+1,vector<vector<int> > (l2+1,vector<int> (l3+1,0)));
    looprev(i,l1-1,0) {
        looprev(j,l2-1,0) {
            looprev(k,l3-1,0) {
                if(s1[i] == s2[j] and s2[j] == s3[k]) {
                    dp[i][j][k] = 1 + dp[i+1][j+1][k+1];
                }
                else {
                    int m1 = max(dp[i+1][j][k],max(dp[i][j+1][k],dp[i][j][k+1]));
                    int m2 = max(dp[i+1][j+1][k],max(dp[i][j+1][k+1],dp[i+1][j][k+1]));
                    dp[i][j][k] = max(m1,m2);
                }
            }
        }
    }
    // for(auto i:dp) {
    //     for(auto j:i) {
    //         for(auto k:j) {
    //             cout<<k<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    return dp[0][0][0];
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    // int n = s1.length(), m = s2.length();
    // vector<vector<int> > dp(n, vector<int> (m,-1));
    // cout<<LCS_td(s1,s2,0,0,dp)<<" "<<LCS_bu(s1,s2)<<" "<<LCS_so(s1,s2);
    cout<<LCSof3(s1,s2,s3);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}