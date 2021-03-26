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
minimum no. of jumps to reach the end of the array
*/

// recursive approach O(n^n)
int minjumps(vector<int> &arr, int idx=0, int jumps=0)
{
    if(idx >= arr.size()-1)
        return jumps;
    
    int jumps_ = INT_MAX;
    loop(i,1,arr[idx])
    {
        int jumps__ = minjumps(arr,idx+i,jumps+1);
        jumps_ = min(jumps_,jumps__);
    }

    return jumps_;
}

// DP approach O(n^2)
int minjumps_(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;
    loop(i,1,n-1)
    {
        loop(j,0,i-1)
        {
            if(dp[j] == INT_MAX)
                continue;
            if(arr[j]+j >= i)
                if(dp[j]+1 < dp[i])
                    dp[i] = dp[j]+1;
        }
    }
    return (dp[n-1]!=INT_MAX?dp[n-1]:-1);
}

// o(n) approach
int minjumps__(vector<int> &arr)
{
    int n = arr.size();
    int maxR = arr[0];
    int steps = arr[0];
    int jumps = 1;
    if(arr[0] == 0) return -1;
    if(n == 1) return 0;
    loop(i,1,n-1)
    {
        if(i == n-1) return jumps;
        maxR = max(maxR,arr[i]+i);
        steps--;
        if(steps == 0)
        {
            jumps++;
            if(i >= maxR)
                return -1;
            steps = maxR - i;
        }
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<int> arr(n);
    loop(i,0,n-1)
        cin>>arr[i];
    cout<<minjumps__(arr)<<endl;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}