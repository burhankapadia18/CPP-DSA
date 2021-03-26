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

// codechef problem, problem code : AMCS03

ld f(ld T, vi &S, vi &D)
{
    ld mx = 0.0, mn = inf;
    for(int i=0; i<S.size(); i++)
    {
        ld val = S[i]*T+D[i];
        mn = min(mn,val);
        mx = max(mx,val);
    }
    return mx - mn; 
}
ld ternarySearch(int k, vi &S, vi &D)
{
    ld lo = 0.0, hi = (ld)k;
    while((hi-lo) > 1e-9)
    {
        ld m1 = lo + (hi-lo)/3;
        ld m2 = hi - (hi-lo)/3;
        if(f(m1,S,D) < f(m2,S,D))
            hi = m2;
        else 
            lo = m1;
    }
    return f(lo,S,D);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n,k;
    cin>>n>>k;
    vi S(n), D(n);
    loop(i,0,n-1)
        cin>>S[i]>>D[i];

    cout<<fixed<<setprecision(6)<<ternarySearch(k,S,D);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}