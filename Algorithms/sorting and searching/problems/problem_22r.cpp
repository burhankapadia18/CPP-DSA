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

// https://www.spoj.com/problems/ANARC05B/

int solve(int a[], int n, int b[], int m) {
    int sum1, sum2, maxSum;
    sum1 = sum2 = maxSum = 0;
    int i, j;
    i = j = 0;
    while(i<n and j<m) {
        if(a[i] < b[j]) {
            sum1 += a[i++];
        }
        else if(b[j] < a[i]) {
            sum2 += b[j++];
        }
        else {
            maxSum += (max(sum1,sum2) + a[i]);
            sum1 = sum2 = 0;
            i++; j++;
        }
    }
    while(i < n) {
        sum1 += a[i++];
    }
    while(j < m) {
        sum2 += b[j++];
    }
    maxSum += max(sum1,sum2);
    return maxSum;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n>>m;
    int a[n], b[m];
    loop(i,0,n-1) cin>>a[i];
    loop(i,0,m-1) cin>>b[i];

    cout<<solve(a,n,b,m);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}