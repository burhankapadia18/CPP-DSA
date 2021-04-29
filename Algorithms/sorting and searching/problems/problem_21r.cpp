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

// https://www.spoj.com/problems/PRATA/

bool helper(int prata, int cook[], int n, int mi) {
    int time = 0;
    int pratha = 0;
    loop(i,0,n-1) {
        time = cook[i];
        int j = 2;
        while(time <= mi) {
            pratha++;
            time = time + (cook[i]*j);
            j++;
        }
        if(pratha >= prata) 
            return 1;
    }
    return 0;
}
int minTime(int prata, int cook[], int n) {
    int lo = 0, hi = 1e8;
    int ans = 0;
    while(lo <= hi) {
        int mi = mid(lo,hi);
        if(helper(prata,cook,n,mi)) {
            ans = mi;
            hi = mi - 1;
        }
        else {
            lo = mi + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int prata, n;
    cin>>prata>>n;
    int cook[n];
    loop(i,0,n-1) cin>>cook[i];

    cout<<minTime(prata,cook,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}