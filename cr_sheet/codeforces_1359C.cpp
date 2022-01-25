#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define uset 			unordered_set
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;


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

// https://codeforces.com/problemset/problem/1359/C

vector<int> odds;

int solve(ll h, ll c, ll t) {
    // getting wrong answer on test2
    if(t==h) return 1;
    long double minT = (h+c)/2.0;
    if(t<=minT) return 2;
    ll lo=0, hi=odds.size()-1, mi, k;
    while(lo<hi) {
        mi = mid(lo,hi);
        k = odds[mi];
        if((odds[mi]/2+1)*h+c*(odds[mi]/2)<t*(odds[mi])) hi = mi-1;
        else lo = mi+1;
    }
    return odds[lo];
}

int solve1(ll h, ll c, ll t) {
    if(h==t) return 1;
    if(2LL *t <= (h+c)) return 2;

    ll x = (t-c)/(2*t-(h+c));
    ll y = x+1;

    long double poss1 = ((x*h)+((x-1)*c))/(1.0*(2*x-1));
    long double poss2 = ((y*h)+((y-1)*c))/(1.0*(2*y-1));

    long double diff1 = abs(poss1-t);
    long double diff2 = abs(poss2-t);

    if(diff1 <= diff2) return 2*x-1;
    return 2*y-1;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int t;
    cin>>t;
    // for(int i=1; i<=7000000; i+=2) odds.push_back(i); 
    while(t--) {
        ll h, c, t;
        cin>>h>>c>>t;
        cout<<solve1(h,c,t)<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}