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

// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

int kpd[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {-1, 0, -1},
};
bool isSafe(int i, int j) {
    return (i>=0 and j>=0 and i<4 and j<3 and kpd[i][j]!=-1);
}
int dp[10][1005];
int solve(int i, int j, int n) {
    if(n == 1) 
        return 1;
    if(dp[kpd[i][j]][n] != -1)
        return dp[kpd[i][j]][n];

    int ans=0;
    ans += solve(i,j,n-1);
    int x[] = {-1,1,0,0};
    int y[] = {0,0,-1,1};
    loop(k,0,3) {
        if(isSafe(i+x[k],j+y[k])) {
            ans += solve(i+x[k],j+y[k],n-1);
        }
    }
    return dp[kpd[i][j]][n] = ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;

    int ans=0;
    memset(dp,-1,sizeof(dp));
    loop(i,0,3) {
        loop(j,0,2) {
            if(kpd[i][j] != -1) {
                ans += solve(i,j,n);
            }
        }
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}