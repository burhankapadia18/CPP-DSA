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

// 0-1 knapsack
int knapsack(vector<pair<int,int> > &arr, int n, int w, vector<vector<int> > &dp) {
    if(n==0 or w==0)
        return 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    if(arr[n-1].ss > w)
        return dp[n][w] = knapsack(arr,n-1,w,dp);

    return dp[n][w] = max(knapsack(arr,n-1,w-arr[n-1].ss,dp)+arr[n-1].ff,
                knapsack(arr,n-1,w,dp));
}

// fractional knapsack
bool cmp(pair<int,int> a, pair<int,int> b) {
    double r1 = (double)a.ff / (double)a.ss;
    double r2 = (double)b.ff / (double)b.ss;
    return r1 > r2;
}
double fractionalKnapsack(int W, vector<pair<int,int> > &arr, int n) {
    sort(arr.begin(), arr.end(), cmp);
    int curW = 0; 
    double finalval = 0.0;
    for (int i = 0; i < n; i++) {
        if (curW + arr[i].ss <= W) {
            curW += arr[i].ss;
            finalval += arr[i].ff;
        }
        else {
            int remain = W - curW;
            finalval += arr[i].ff * ((double)remain/(double)arr[i].ss);
            break;
        }
    }
    return finalval;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, w;
    cin>>n>>w;
    vector<pair<int,int> > arr(n);
    loop(i,0,n-1) {
        int val, wt;
        cin>>val>>wt;
        arr[i] = make_pair(val,wt);
    }
    vector<vector<int> > dp(n+1,vector<int> (w+1,-1));
    cout<<knapsack(arr,n,w,dp)<<endl;
    cout<<fractionalKnapsack(w,arr,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}