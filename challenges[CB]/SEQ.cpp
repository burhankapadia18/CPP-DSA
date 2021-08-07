#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// template<typename T>
#define ll 				long long int
#define ld				long double
#define mod             1000000000
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

// SEQ spoj     (using mod value 1e9 instead of 1e9+7)
ll k;
vi b,c;
vector<vi> xply(vector<vi> A, vector<vi> B) {
    vector<vi> C(k,vi(k,0));
    loop(i,0,k-1) {
        loop(j,0,k-1) {
            loop(x,0,k-1) {
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%mod)%mod;
            }
        }
    }
    return C;
}
vector<vi> pow_mtx(vector<vi> A, ll p) {
    // base case
    if(p == 1) return A;
    // power is odd
    if(p&1) {
        return xply(A,pow_mtx(A,p-1));
    }
    vector<vi> X = pow_mtx(A,p/2);
    return xply(X,X);
}
ll compute(ll n) {
    // base case
    if(n==0) return 0;
    if(n<=k) return b[n-1];
    // otherwise use matrix exponentiation
    // S1: init F1 vector
    vi F1(k);
    loop(i,0,k-1) F1[i] = b[i];
    // S2: build transformation matrix
    vector<vi> T(k,vi(k));
    loop(i,0,k-1) {
        loop(j,0,k-1) {
            if(i<k-1) {
                // fill o's and 1's
                if(j==i+1) T[i][j] = 1;
                else T[i][j] = 0;
            }
            else {
                // fill last row with coef
                T[i][j] = c[k-1-j];
            }
        }
    }
    // S3: calculate T^n-1
    T = pow_mtx(T,n-1);
    // S4: xply T with F1
    ll ans = 0;
    loop(i,0,k-1) ans = (ans + (T[0][i]*F1[i])%mod)%mod;
    
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll t,n,num;
    cin>>t;
    while(t--) {
        cin>>k;
        loop(i,0,k-1) {
            cin>>num;
            b.push_back(num);
        }
        loop(i,0,k-1) {
            cin>>num;
            c.push_back(num);
        }
        cin>>n;
        cout<<compute(n)<<endl;
        b.clear(); c.clear();
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}