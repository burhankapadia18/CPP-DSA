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

// SPP spoj
ll k, P;
vi b, c;
vector<vi> xply(vector<vi> A, vector<vi> B) {
    vector<vi> C(k+1,vi(k+1,0));
    loop(i,0,k) {
        loop(j,0,k) {
            loop(x,0,k) {
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%P)%P;
            }
        }
    }
    return C;
}
vector<vi> pow_mtx(vector<vi> A, ll n) {
    if(n == 1) return A;
    if(n&1) return xply(A,pow_mtx(A,n-1));
    vector<vi> X = pow_mtx(A,n/2);
    return xply(X,X);
}
ll compute(ll n) {
    if(n <= k) {
        ll ans=0;
        for(ll i=0; i<n; i++) ans += b[i];
        return ans;
    }
    vi F1(k+1);
    ll sum=0;
    for(ll i=0; i<k; i++) {
        sum += b[i];
        F1[i+1] = b[i];
    }
    F1[0] = sum;
    vector<vi> T(k+1,vi(k+1,0));
    T[0][0] = 1;
    for(int i=0; i<=k; i++) {
        for(int j=1; j<=k; j++) {
            if(i==0 or i==k) {
                // fill first and last row with coef
               T[i][j] = c[k-j];
            }
            else {
                // fill with 0's and 1's
                if(j == i+1) T[i][j] = 1;
                else T[i][j] = 0;
            }
        }
    }
    T = pow_mtx(T,n-k);
    ll ans = 0;
    loop(i,0,k) ans = (ans + (T[0][i]*F1[i])%P)%P;
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll t;
    cin>>t;
    while(t--) {
        cin>>k;
        ll num;
        loop(i,0,k-1) {
            cin>>num; b.push_back(num);
        }
        loop(i,0,k-1) {
            cin>>num; c.push_back(num);
        }
        ll m, n;
        cin>>m>>n>>P;
        // compute(3);
        ll r = compute(n), l = compute(m-1);
        ll ans = ((r-l)+P)%P;
        cout<<ans<<endl;
        b.clear(); c.clear();
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}