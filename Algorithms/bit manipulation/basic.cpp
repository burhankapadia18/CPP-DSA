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

bool isOdd(int n) {
    return (n&1);
}
int getBit(int n, int i) {
    int mask = 1<<i;
    int bit = (n&mask)>0? 1:0;
    return bit;
}
void setBit(int &n, int i) {
    int mask = 1<<i;
    n = n|mask;
}
void clearBit(int &n, int i) {
    int mask = ~(1<<i);
    n = n&mask;
}
void updateBit(int &n, int i, int b) {
    int mask = ~(1<<i);
    n = n&mask;
    mask = b<<i;
    n = n|mask;
}
void clearLastIbits(int &n, int i) {
    // eg : 1111 and i=2 ie clear last 2 bits, 1100 (not upto ith bit)
    int mask = -1<<i; // ~0 = -1 and -1 = 11111111 in binary
    n = n&mask;
}
void clearRangeI2J(int &n, int i, int j) {
    int a = -1<<(j+1);
    int b = (1<<i)-1;   // 0001111 types of bin are of type (2^n)-1, if n=3 then 111
    int mask = a|b;
    n = n&mask;
}
int isPowOf2(int n) {
    return ((n&(n-1)) == 0);
}
int xply_by_powOfTwo(int n, int k) {
    return n<<k;
}
int divide_by_powOfTwo(int n, int k) {
    return n>>k;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;

    clearRangeI2J(n,1,3);
    cout<<n;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}