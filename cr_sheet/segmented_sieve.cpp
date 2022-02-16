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

// https://www.spoj.com/problems/PRIME1/

vector<int> sieve(int n) {
    vector<int> isPrime(n+1,0), ans;
    for(int i=2; i*i<=n; i++)
        if(isPrime[i] == 0) 
            for(int j=i*i; j<=n; j+=i) isPrime[j] = 1;
    for(int i=2; i<=n; i++) 
        if(isPrime[i]==0) ans.push_back(i);
    return ans;
}
void segmentedSieve() {
    int t;
    cin>>t;
    while(t--) {
        int m, n;
        cin>>m>>n;
        int rootn = (int)sqrt(n);
        vector<bool> isPrime(n-m+1,0);
        vector<int> bprimes = sieve(rootn);
        for(int &prime:bprimes) {
            int multiple = ceil((m*1.0)/prime);
            if(multiple==1) multiple++;
            int idx = multiple*prime - m;
            for(int j=idx; j<=isPrime.size(); j+= prime) isPrime[j] = 1;
        }
        for(int i=0; i<isPrime.size(); i++) 
            if(isPrime[i]==0 and i+m>1) cout<<i+m<<" ";
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    segmentedSieve();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}