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

// https://www.spoj.com/problems/DIEHARD/

int dp[1005][1005];
int maxtime(int health, int armor, int state) {
    // air=1, water=2, fire=3;
    if(health<=0 or armor<=0) {
        return 0;
    }
    if(dp[health][armor] != -1) {
        return dp[health][armor];
    }
    int ans1=0, ans2=0, ans3=0;
    if(state != 1) ans1 = 1 + maxtime(health+3,armor+2,1);
    if(state != 2) ans2 = 1 + maxtime(health-5,armor-10,2);
    if(state != 3) ans3 = 1 + maxtime(health-20,armor+5,3);
    
    return dp[health][armor] = max(ans1,max(ans2,ans3));
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int t;
    cin>>t;
    while(t--) {
        int health, armor;
        cin>>health>>armor;
        memset(dp,-1,sizeof(dp));
        int c1 = maxtime(health+3,armor+2,1);
        int c2 = maxtime(health-5,armor-10,2);
        int c3 = maxtime(health-20,armor+5,3);

        cout<<max(c1,max(c2,c3))<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}