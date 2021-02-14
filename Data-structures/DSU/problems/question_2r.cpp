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

// https://codeforces.com/problemset/problem/1263/D
// can be solved using graph dfs also

ll Get(vi &parent, ll a)
{
    return parent[a] = (parent[a]==a?a:Get(parent,parent[a]));
}
void Union(vi &parent, vi &rank, ll a, ll b)
{
    a = Get(parent,a);
    b = Get(parent,b);
    if(rank[a] == rank[b]) rank[a]++;
    if(rank[a] > rank[b]) parent[b] = a;
    else parent[a] = b;
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    file_i_o();

    // write your code here
    ll n;
    cin>>n;
    vi parent(27), rank(27,0);
    loop(i,0,26)
        parent[i] = i; 

    vector<bool> total(26,0), current(26,0);
    while(n--)
    {
        string str;
        cin>>str;
        loop(i,0,25)
            current[i] = 0;
        for(char c:str)
            current[c-'a'] = 1;
        loop(i,0,25)
            if(current[i])
            {
                total[i] = 1;
                Union(parent,rank,str[0]-'a',i);
            }
    }
    ll count=0;
    loop(i,0,25)
        if(total[i] && Get(parent,i)==i)
            count++;
    cout<<count;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}