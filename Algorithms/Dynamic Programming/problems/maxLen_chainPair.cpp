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

// https://practice.geeksforgeeks.org/problems/max-length-chain/1

int maxlenchain(vector<pair<int,int> > &arr) {
    // dp solution  O(n^2)
    int n = arr.size();
    vector<int> dp(n,1);
    sort(arr.begin(),arr.end());
    loop(i,1,n-1) {
        loop(j,0,i-1) {
            if(arr[j].ss < arr[i].ff) {
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }
    int ans = 0;
    loop(i,0,n-1) ans = max(dp[i],ans);
    return ans;
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.ss < b.ss;
}
int maxchainlen(vector<pair<int,int> > &arr) {
    // greedy solution  O(nlogn)
    int n = arr.size();
    sort(arr.begin(),arr.end(),cmp);
    int i = 0, j = 1, ctr = 1;
    while(j < n) {
        if(arr[i].ss < arr[j].ff) {
            i = j; j++; ctr++;
        }
        else {
            j++;
        }
    }
    return ctr;
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
        int x, y;
        cin>>x>>y;
        arr[i] = make_pair(x,y);
    }

    cout<<maxlenchain(arr)<<" "<<maxchainlen(arr);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}