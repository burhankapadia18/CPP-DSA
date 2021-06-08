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

// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

int dp[1005][1005];
int knapsack(vector<pair<int,int> > &arr, int i, int w) {
    if(i <= -1)
        return 0;

    if(dp[i][w] != -1)
        return dp[i][w];

    if(arr[i].ss > w)
        return dp[i][w] = knapsack(arr,i-1,w);

    int opt1 = arr[i].ff + knapsack(arr,i,w-arr[i].ss);
    int opt2 = knapsack(arr,i-1,w);

    return dp[i][w] = max(opt1,opt2);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<pair<int,int> > arr(n);
    loop(i,0,n-1) {
        int val, wt;
        cin>>val>>wt;
        arr[i] = make_pair(val,wt);
    }
    int W;
    cin>>W;

    memset(dp,-1,sizeof(dp));
    cout<<knapsack(arr,n-1,W);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}