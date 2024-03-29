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

// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

int flight_cost(vector<pair<int,int> > adj[], int V, int src, int dest, int k) {
    set<vector<int> > S;
    vector<int> tmp(3);
    tmp[0] = 0; // cost
    tmp[1] = src; // city
    tmp[2] = 0; // no. of stops
    S.insert(tmp);
    while(!S.empty()) {
        tmp = *S.begin();
        S.erase(tmp);
        int cost = tmp[0];
        int u = tmp[1];
        int stops = tmp[2];
        if(u == dest)
            return cost;
        for(auto i:adj[u]) {
            int v = i.ff;
            int w = i.ss;
            if(stops <= k) {
                tmp[0] = cost + w;
                tmp[1] = v;
                tmp[2] = stops + 1;
                S.insert(tmp);
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int V, E;
    cin>>V>>E;
    vector<pair<int,int> > adj[V];
    loop(i,1,E) {
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y,w));
    }

    cout<<flight_cost(adj,V,0,5,2);
    

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}