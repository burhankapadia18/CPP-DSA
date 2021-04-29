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

// https://practice.geeksforgeeks.org/problems/edit-distance3702/1

int dp[1001][1001];
int func(string &s1, string &s2, int n1, int n2) {
    if(n1 == -1) return n2+1;
    if(n2 == -1) return n1+1;

    if(dp[n1][n2] != -1) return dp[n1][n2];
    if(s1[n1] == s1[n2]) 
        return dp[n1][n2] = func(s1,s2,n1-1,n2-1);

    int a = func(s1,s2,n1-1,n2-1); // replace
    int b = func(s1,s2,n1,n2-1); // insert
    int c = func(s1,s2,n1-1,n2); // remove

    return dp[n1][n2] = 1+min(a,min(b,c));
}
int editDistance(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    memset(dp,-1,sizeof(dp));
    return func(s1,s2,n1-1,n2-1);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string s1, s2;
    cin>>s1>>s2;

    cout<<editDistance(s1,s2);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}