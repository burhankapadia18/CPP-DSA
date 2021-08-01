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

// Problem - Unique Number II
// given a list of numbers where every number occurs twice execpt two numbers, find the unique numbers

void uniqueNumberII(int arr[], int n) {
    // find the xor of all values
    int x = 0;
    loop(i,0,n-1) x = x ^ arr[i];
    // find the position of first set bit in x
    int pos = 0, tmp=x;
    while(tmp>0) {
        if(tmp&1) break;
        tmp = tmp>>1;
        pos++;
    }
    // xor all the values which have setbit at pos
    int a=0;
    loop(i,0,n-1) {
        int mask = 1<<pos;
        if((arr[i]&mask)>0) a = a ^ arr[i];
    }
    // find the other number by doing xor with x because x = a^b
    int b = a ^ x;
    cout<<a<<" "<<b;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    int arr[n];
    loop(i,0,n-1) cin>>arr[i];

    uniqueNumberII(arr,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}