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

// https://codeforces.com/problemset/problem/271/D?locale=en

void solve() {
    string str, isGood;
    int k, n;
    cin>>str>>isGood>>k;
    n = str.length();
    set<pair<int,int>> S;
    for(int i=0; i<n; i++) {
        int hash1=0, hash2=0, p1=31, p2=29, pow1=1, pow2=1, badCnt=0;
        for(int j=i; j<n; j++) {
            badCnt += (isGood[str[j]-'a']=='0'?1:0);
            if(badCnt>k) break;
            hash1 = (hash1 + (str[j]-'a'+1)*pow1)%mod;
            hash2 = (hash2 + (str[j]-'a'+1)*pow2)%mod;
            pow1 = (pow1*p1)%mod;
            pow2 = (pow2*p2)%mod;
            S.insert({hash1,hash2});
        }
    }
    cout<<S.size();
}

int main(int argc, char const *argv[])
{
    // clock_t begin = clock();
    // file_i_o();

    // write your code here
    solve();

    // #ifndef ONLINE_JUDGE
    //     clock_t end = clock();
    //     cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    // #endif
    return 0;
}