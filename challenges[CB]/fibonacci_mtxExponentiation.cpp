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

vector<vi> xply(vector<vi> A, vector<vi> B) {
    ll n = A.size();
    vector<vi> ans(n,vi(n,0));
    loop(i,0,n-1) {
        loop(j,0,n-1) {
            loop(k,0,n-1) {
                ans[i][j] = ans[i][j] + A[i][k]*B[k][j];
            }
        }
    }
    return ans;
}
vector<vi> pow_mtx(vector<vi> T, ll p) {
    if(p == 1) return T;

    if(p&1) return xply(T,pow_mtx(T,p-1));
    vector<vi> X = pow_mtx(T,p/2);
    return xply(X,X);
}
ll fibonacci(ll n) {
    if(n==0 or n==1) return n;

    vi F1 = {0,1};
    vector<vi> T = {{0,1},{1,1}};
    T = pow_mtx(T,n-1);
    ll ans = 0;
    ans = T[1][0]*F1[0] + T[1][1]*F1[1];
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    // tc = O(k^3Logn) since k=2 in this 
    // therefore tc = O(8LogN) ~ O(LogN)
    for(ll i=0; i<=22; i++)
    cout<<i<<"\t:"<<fibonacci(i)<<endl;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}