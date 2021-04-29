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

// https://leetcode.com/problems/flood-fill/

bool isSafe(vector<vector<int> > &arr, vector<vector<int> > &vis, int i, int j, int oldcolor) {
    int n = arr.size();
    int m = arr[0].size();
    if(i<0 or j<0 or i>=n or j>=m) return 0;
    if(vis[i][j] or arr[i][j]!=oldcolor) return 0;
    return 1;
}
void dfs(vector<vector<int> > &arr, vector<vector<int> > &vis, int i, int j, int newcolor) {
    vis[i][j] = 1;
    int oldcolor = arr[i][j];
    arr[i][j] = newcolor;
    int x[] = {-1,0,1,0};
    int y[] = {0,-1,0,1};
    loop(k,0,3) {
        if(isSafe(arr,vis,i+x[k],j+y[k],oldcolor)) {
            dfs(arr,vis,i+x[k],j+y[k],newcolor);
        }
    } 
}
void floodFill(vector<vector<int> > &arr, int sr, int sc, int newcolor) {
    int n = arr.size(), m = arr[0].size();
    vector<vector<int> > vis(n, vector<int> (m,0));
    dfs(arr,vis,sr,sc,newcolor);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m, sr, sc, newcolor;
    cin>>n>>m>>sr>>sc>>newcolor;
    vector<vector<int> > arr(n,vector<int> (m));
    loop(i,0,n-1)
        loop(j,0,m-1)
            cin>>arr[i][j];

    floodFill(arr,sr,sc,newcolor);
    loop(i,0,n-1) {
        loop(j,0,m-1)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}