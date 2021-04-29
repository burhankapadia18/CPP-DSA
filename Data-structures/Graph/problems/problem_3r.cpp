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
You are given a grid of characters -> {'U','R','L','D'}
these characters denote the direction you can go from the current 
cell.
find minimum no. of modifications required in order to reach from
(0,0) to (n-1,m-1) cell.
eg:     R R D
        L L L       ans = 1
        U U R

n,m <= 10^4
*/

struct triplet
{
    ll x;
    ll y;
    ll cost;
};
triplet retobj(ll x, ll y, ll cost) {return {x,y,cost};}
ll minReplacement(vector<vector<char> > &grid)
{
    ll n = grid.size();
    ll m = grid[0].size();
    deque<triplet> Q;
    set<pii> vis;
    int xdir[] = {-1,1,0,0};
    int ydir[] = {0,0,-1,1};
    Q.push_back(retobj(0,0,0));
    while(!Q.empty())
    {
        triplet curr = Q.front(); Q.pop_front();
        vis.insert(make_pair(curr.x,curr.y));
        if(curr.x==n-1 && curr.y==m-1) return curr.cost;
        loop(d,0,3)
        {
            ll x = curr.x + xdir[d];
            ll y = curr.y + ydir[d];
            if(x<0 || y<0 || x>=n || y>=m) continue;
            if(vis.count(make_pair(x,y))) continue;
            ll cost;
            if(grid[curr.x][curr.y]=='U' && xdir[d]==-1 && ydir[d]==0) cost = 0;
            else if(grid[curr.x][curr.y]=='D' && xdir[d]==1 && ydir[d]==0) cost = 0;
            else if(grid[curr.x][curr.y]=='L' && xdir[d]==0 && ydir[d]==-1) cost = 0;
            else if(grid[curr.x][curr.y]=='R' && xdir[d]==0 && ydir[d]==1) cost = 0;
            else cost = 1;
            if(cost == 1) Q.push_back(retobj(x,y,curr.cost+cost));
            else Q.push_front(retobj(x,y,curr.cost+cost));
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll n, m;
    cin>>n>>m;
    vector<vector<char> > grid(n,vector<char> (m));
    loop(i,0,n-1)
        loop(j,0,m-1)
            cin>>grid[i][j];

    cout<<minReplacement(grid);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}