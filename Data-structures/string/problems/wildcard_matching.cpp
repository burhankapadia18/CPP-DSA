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

// https://practice.geeksforgeeks.org/problems/wildcard-string-matching/0

int dp[1001][1001];
bool wildcardMatching(string p, string s, int i, int j) {
    if(i == -1 and j == -1) return 1;
    if(j == -1) {
        loop(k,0,i-1) 
            if(p[k] != '*') return 0;
        return 1;   
    }
    if(i == -1) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    if(p[i] == s[j] or p[i] == '?')
        return dp[i][j] = wildcardMatching(p,s,i-1,j-1);
    if(p[i] == '*') {
        int a = wildcardMatching(p,s,i-1,j);
        int b = wildcardMatching(p,s,i,j-1);
        return dp[i][j] = a or b;
    }
    return dp[i][j] = 0;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string p, s;
    cin>>p>>s;
    memset(dp,-1,sizeof(dp));
    if(wildcardMatching(p,s,p.length()-1,s.length()-1))
        cout<<"yes";
    else 
        cout<<"no";

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}