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
Given an number x, you can do 3 differnt operations on x.
    1. subtract 1 from x
    2. if x is divisible by 2, then divide it by 2
    3. if x is divisible by 3, then divide it by 3
find no. of operations to reduce x to 1.
*/

// top down approach
int minStepsToOneTD(int x, vector<int> &dp) {
    if(x == 2 or x == 3)
        return 1;
    if(x == 1)
        return 0;
    if(x < 1)
        return INT_MAX;
    if(dp[x] != 0)
        return dp[x];
    int div2, div3, sub1;
    div2 = div3 = sub1 = INT_MAX;
    if(x%2 == 0)
        div2 = 1 + minStepsToOneTD(x/2,dp);
    if(x%3 == 0)
        div3 = 1 + minStepsToOneTD(x/3,dp);
    sub1 = 1 + minStepsToOneTD(x-1,dp);
    return dp[x] = min(sub1,min(div2,div3));
}

// bottom up approach
int minStepsToOneBU(int x) {
    vector<int> dp(x+1);
    dp[0] = INT_MAX;
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    loop(i,4,x) {
        int div2, div3, sub1;
        div2 = div3 = sub1 = INT_MAX;
        if(i%2 == 0)
            div2 = 1 + dp[i/2];
        if(i%3 == 0)
            div3 = 1 + dp[i/3];
        sub1 = 1 + dp[i-1];
        dp[i] = min(sub1,min(div2,div3));
    }
    return dp[x];
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int x;
    cin>>x;
    vector<int> dp(x+1,0);
    cout<<minStepsToOneTD(x,dp)<<" "<<minStepsToOneBU(x);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}