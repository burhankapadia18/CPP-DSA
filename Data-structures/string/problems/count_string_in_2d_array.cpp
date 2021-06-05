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

// https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/

void dfs(vector<vector<char> > &grid, int i, int j, string &str, int c, int &ctr) {
    int sl = str.length();
    int n = grid.size();
    int m = grid[0].size();
    if(!(i>=0 and j>=0 and i<n and j<m and grid[i][j]==str[c])) 
        return;

    if(c==sl-1) {
        ctr++;
        return;
    }
    
    char temp = grid[i][j];
    grid[i][j] = '$';
    int x[] = {-1,1,0,0};
    int y[] = {0,0,-1,1};
    loop(k,0,3) {
        dfs(grid,i+x[k],j+y[k],str,c+1,ctr);
    }
    grid[i][j] = temp;
}
int wordCount(vector<vector<char> > &grid, string &str) {
    int ctr = 0;
    int n = grid.size();
    int m = grid[0].size();
    loop(i,0,n-1) {
        loop(j,0,m-1) {
            if(grid[i][j] == str[0]) {
                dfs(grid,i,j,str,0,ctr);
            }
        }
    }
    return ctr;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n>>m;
    vector<vector<char> > grid(n,vector<char>(m));
    loop(i,0,n-1)
        loop(j,0,m-1)
            cin>>grid[i][j];
    string str;
    cin>>str;

    cout<<wordCount(grid,str);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}