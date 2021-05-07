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

// https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/

vector<int> intime;
vector<int> outtime;
int timer;
void resize(int n) {
    intime.resize(n+1);
    outtime.resize(n+1);
}
void dfs(int src, int parent, vector<int> adj[]) {
    intime[src] = timer++;
    for(int v:adj[src]) {
        if(v != parent)
            dfs(v,src,adj);
    }
    outtime[src] = timer++;
}
bool check(int a, int b) {
    if(intime[a]>intime[b] and outtime[a]<outtime[b])
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    timer = 1;
    resize(n);
    vector<int> adj[n+1];
    loop(i,1,n-1) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0,adj);
    int q;
    cin>>q;
    while(q--) {
        int type, x, y;
        cin>>type>>x>>y;
        if(!check(x,y) and !check(y,x)) {
            cout<<"No\n";
            continue;
        }
        if(type == 0) {
            if(check(y,x))
                cout<<"Yes\n";
            else 
                cout<<"No\n";
        }
        else if(type == 1) {
            if(check(x,y))
                cout<<"Yes\n";
            else 
                cout<<"No\n";
        }
    }


    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}