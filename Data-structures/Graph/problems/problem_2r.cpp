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
You have given a undirected tree of n nodes. some nodes have color 'A',
some have color 'B' and some have color 'C'. it is sure that nodes of 
color 'A' & 'B' are present. find the no. of edges you can remove such 
that removing an edge divides the tree in 2 components where in one 
component only no node have a color 'A' & in one component no node have
a color 'B'.

n <= 3x10^5
*/

ll n;
ll countRed=0, countBlue=0;
ll ans = 0;
pii dfs(list<int> graph[], char colors[], ll src, ll parent = -1)
{
    ll r = (colors[src]=='A');
    ll b = (colors[src]=='B');
    for(auto neighbour:graph[src])
    {
        if(neighbour != parent)
        {
            pii result = dfs(graph,colors,neighbour,src);
            ans += (result.ff == countRed && result.ss == 0);
            ans += (result.ff == 0 && result.ss == countBlue);
            r += result.ff;
            b += result.ss;
        }
    }
    return make_pair(r,b);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    cin>>n;
    list<ll> graph[n+1];
    char colors[n+1];
    loop(i,1,n)
    {
        char color;
        cin>>color;
        colors[i] = color;
        if(color == 'A')
            countRed += 1;
        else if(color == 'B')
            countBlue += 1;
    }
    loop(i,1,n-1)
    {   // being an undirected tree, it will have n-1 edges
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}