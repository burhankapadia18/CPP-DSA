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
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

/*
Question :- 
You got n elements. you have 2 types of queries
    (x,y) : merge them in same group
    (x) : return the max, min, total element of the group

n <= 10^5
Q <= 10^5
*/

ll Get(vi &parent, ll a)
{
    return parent[a] = (parent[a]==a?a:Get(parent,parent[a]));
}
void Union(vi &parent, vi &rank, vi &max_, vi &min_, vi &size_, ll a, ll b)
{
    a = Get(parent,a);
    b = Get(parent,b);
    if(rank[a] == rank[b]) rank[a]++;
    if(rank[a] > rank[b])
    {
        parent[b] = a;
        size_[a] += size_[b];
        max_[a] = max(max_[a],max_[b]);
        min_[a] = min(min_[a],min_[b]);
    } 
    else 
    {
        parent[a] = b;
        size_[b] += size_[a];
        max_[b] = max(max_[a],max_[b]);
        min_[b] = min(min_[a],min_[b]);
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll n, Q;
    cin>>n>>Q;
    vi parent(n+1), rank(n+1,0), min_(n+1), max_(n+1), size_(n+1,1);
    loop(i,1,n)
        parent[i] = min_[i] = max_[i] = i;
    while(Q--)
    {
        
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}