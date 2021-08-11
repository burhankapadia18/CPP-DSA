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

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can climb 1, 2 or .. k steps. In how many distinct 
ways can you climb to the top?
(solve using matrix exponentiation)
*/
vector<vi> xply(vector<vi> A, vector<vi> B) {
    ll k = A.size();
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
vector<vi> pow_mtx(vector<vi> A, ll n) {
    ll k = A.size();
    if(n == 1) return A;
    if(n&1) return xply(A,pow_mtx(A,n-1));
    vector<vi> X = pow_mtx(A,n/2);
    return xply(X,X);
}
ll compute(ll n, ll k) {
    if(n == 0) return 1;
    if(n<3) return n;

    vi F1(k,0);
    F1[0]=1; F1[1]=2; F1[2]=4;
    loop(i,3,k-1) {
        loop(j,0,i-1) {
            F1[i] += F1[j];
        }
        F1[i] += 1; // adding value of n=0
    }
    // for(int i:F1) cout<<i<<" ";
    vector<vi> T(k,vi(k));
    loop(i,0,k-1) {
        loop(j,0,k-1) {
            if(i==k-1) T[i][j] = 1;
            else {
                if(j==i+1) T[i][j] = 1;
                else T[i][j] = 0;
            }
        }
    }
    T = pow_mtx(T,n-1);
    ll ans = 0;
    loop(i,0,k-1) ans = ans = (ans + (T[0][i]*F1[i])%mod)%mod;
    
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll n, k;
    cin>>n>>k;

    cout<<compute(n,k);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}