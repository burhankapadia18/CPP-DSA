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

// https://www.geeksforgeeks.org/graph-coloring-applications/#:~:text=Graph%20coloring%20problem%20is%20to,are%20colored%20using%20same%20color.

void chromaticNumber(vector<int> adj[], int V) {
    // storing the color of each node
    int color[V];
    // to store the availability of color for neighbours
    bool availableColor[V];
    memset(color,-1,sizeof(color));
    memset(availableColor,1,sizeof(availableColor));
    int cn = 0;
    loop(i,0,V-1) {
        for(int j:adj[i])   // iterating over neighbours to check which colors are used
            if(color[j] != -1)
                // which means the neighbour is already colored and we cannot use this color to color the ith node
                availableColor[color[j]] = 0;
        // initially start checking with color 0
        int cr = 0;
        for(;cr<V;cr++)
            if(availableColor[cr]) // means cr is available for ith node
                break;
        // assign cr color to ith node
        color[i] = cr;
        cn = max(cn,cr+1);  // storing the max color number used for coloring the entire graph (using +1 because we are starting from 0)
        // resetting the array for other node
        memset(availableColor,0,sizeof(availableColor));
    }
    for(int i:color)
        cout<<i<<" ";
    cout<<endl<<cn;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int V, E;
    cin>>V>>E;
    vector<int> adj[V];
    loop(i,1,E) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    chromaticNumber(adj,V);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}