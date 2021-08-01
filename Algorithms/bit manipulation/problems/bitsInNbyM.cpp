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

// Replace bits in N by M
/*
you are given two 32bit numbers, N and M and two bit positions i and j.
write a method to set all bits between i and j in equal to M.
(eg: M becomes a substring of N located at i starting at j)

example:
N = 10000000000(in binary), M = 10101, i=2, j=6
output: N = 10001010100 
*/

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m, i, j;
    cin>>n>>m>>i>>j;

    int a, b, mask;
    // clear bits in n from i to j
    a = -1<<(j+1);
    b = (1<<i)-1;
    mask = a|b;
    n = n&mask;
    // fit m in n
    mask = m<<i;
    n = n|mask;

    cout<<n;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}