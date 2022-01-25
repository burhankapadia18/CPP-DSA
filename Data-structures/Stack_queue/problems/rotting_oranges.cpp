#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define uset 			unordered_set
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;


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

// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

int orangesRotting(vector<vector<int>>& grid) {
    int n=grid.size(), m=grid[0].size();
    queue<pair<int,int>> Q;
    int fresh=0;
    loop(i,0,n-1) {
        loop(j,0,m-1) {
            if(grid[i][j]==2) Q.push({i,j});
            else if(grid[i][j]==1) fresh++;
        }
    }
    int ans = -1;
    pair<int,int> p;
    while(!Q.empty()) {
        int len=Q.size();
        while(len--) {
            p = Q.front(); Q.pop();
            int x[] = {0,0,1,-1};
            int y[] = {1,-1,0,0};
            for(int i=0; i<4; i++) {
                int r=p.first+x[i], c=p.second+y[i];
                if(r>=n or c>=m or r<0 or c<0 or grid[r][c]==0 or grid[r][c]==2) 
                    continue;
                grid[r][c] = 2;
                fresh--;
                Q.push({r,c});
            }
        }
        ans++;
    }
    if(fresh) return -1;
    return ans==-1?0:ans;
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