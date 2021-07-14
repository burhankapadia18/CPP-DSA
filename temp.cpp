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

    vector<vector<int> > rotateGrid(vector<vector<int> >& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        while(k--) {
            int rs = 0, re = n-1, cs = 0, ce = m-1;
            while(rs<=re and cs<=ce) {
                int temp = grid[rs+1][ce];
                for(int i=ce; i>=cs; i--) {
                    int temp2 = grid[rs][i];
                    grid[rs][i] = temp;
                    temp = temp2;
                }
                rs++;
                for(int i=rs; i<=re; i++) {
                    int temp2 = grid[i][cs];
                    grid[i][cs] = temp;
                    temp = temp2;
                }
                cs++;
                for(int i=cs; i<=ce; i++) {
                    int temp2 = grid[re][i];
                    grid[re][i] = temp;
                    temp = temp2;
                }
                re--;
                cout<<temp<<endl;
                if(rs<=re)
                for(int i=re; i>=rs; i--) {
                    cout<<temp<<" ";
                    int temp2 = grid[i][ce];
                    grid[i][ce] = temp;
                    temp = temp2;
                }
                ce--;
            }
        }
        return grid;
    }

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>m>>n;
    vector<vector<int> > grid(m, vector<int>(n));
    loop(i,0,m-1) {
        loop(j,0,n-1) cin>>grid[i][j];
    }

    grid = rotateGrid(grid,1);
    loop(i,0,m-1) {
        loop(j,0,n-1) cout<<grid[i][j]<<"\t";
        cout<<endl;
    }


    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}