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
(bipartite with dsu)
Question :-
You have an undirected graph of n vertices, each vertice is colored with
red or blue.
    (x,y) : if x,y are different component, add edge b/w them(2 diff't color edges can only connect)
    (x,y) : if x,y are in same component, check whether they have same 
            color or not

n <= 10^5
Q <= 10^5
*/

pii Get(vi &parent, vi &parity, ll a)
{
    if(parent[a] == a)
        return make_pair(a,0);

    pii val = Get(parent,parity,parent[a]);
    parent[a] = val.ff;
    parity[a] = (parity[a]+val.ss)%2;

    return make_pair(parent[a],parity[a]);
}
void Union(vi &parent, vi &size, vi &parity, ll a, ll b)
{
    pii vala = Get(parent,parity,a);
    pii valb = Get(parent,parity,b);
    if(size[vala.ff] > size[valb.ff])
        swap(vala,valb);
    parent[vala.ff] = valb.ff;
    parity[vala.ff] = (1+vala.ss+valb.ss)%2;
    size[valb.ff] += size[vala.ff];
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}