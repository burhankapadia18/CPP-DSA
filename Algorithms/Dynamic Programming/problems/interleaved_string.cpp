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

// https://practice.geeksforgeeks.org/problems/interleaved-strings/1

int dp[1005][1005];
bool isInterleaved(string a, string b, string c, int l1, int l2, int len) {
    if(len == 0)
        return 1;
        if(dp[l1][l2] != -1)
            return dp[l1][l2];
    
    bool x, y;
    if(l1-1>=0 and a[l1-1]==c[len-1])
        x = isInterleaved(a,b,c,l1-1,l2,len-1);
    if(l2-1>=0 and b[l2-1]==c[len-1])
        y = isInterleaved(a,b,c,l1,l2-1,len-1);
    
    return dp[l1][l2] = x or y;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string a, b, c;
    cin>>a>>b>>c;

    int len=c.length(), l1=a.length(), l2=b.length();
    if(len != l1+l2)
        cout<<0;
    else {
        memset(dp,-1,sizeof(dp));
        cout<<isInterleaved(a,b,c,l1,l2,len);
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}