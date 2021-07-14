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

void display(vector<vector<bool> > &grid, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            if(grid[i][j]) cout<<"Q"<<" ";
            else cout<<"."<<" ";
        cout<<'\n';
    }
    cout<<'\n';
}

// Basic approach
int Qcount = 0;
bool isSafe(vector<vector<bool> > &grid, int row, int col, int &n) {
    // takes O(n) time
    // column check
    for(int i=row-1; i>=0; i--)
        if(grid[i][col]) return 0;
    // left upper diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
        if(grid[i][j]) return 0;
    // right upper diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
        if(grid[i][j]) return 0;
    return 1;
}
void countNqueen(vector<vector<bool> > &grid, int curr_row, int &n) {
    // base case
    if(curr_row == n) {
        // we found one way
        Qcount++;
        display(grid,n);
        cout<<endl;
        return;
    }
    for(int i=0; i<n; i++) {
        // goto each spot/column
        if(isSafe(grid,curr_row,i,n)) {
            grid[curr_row][i] = 1;
            countNqueen(grid,curr_row+1,n);
            grid[curr_row][i] = 0;  // reinitialization
        }
    }
}

// Optimized approach using bitmasking
bitset<100> col, l_d, r_d;    
int ans = 0;
void Nqueen_optimized(vector<vector<bool> > &grid, int &n, int cr) {
    if(cr == n) {
        ans++; display(grid,n); return;
    }
    for(int c=0; c<n; c++) {
        if(!col[c] && !l_d[cr-c+n-1] && !r_d[cr+c]) {
            col[c] = l_d[cr-c+n-1] = r_d[cr+c] = grid[cr][c] = 1;
            Nqueen_optimized(grid,n,cr+1);
            col[c] = l_d[cr-c+n-1] = r_d[cr+c] = grid[cr][c] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<vector<bool> > grid(n,vector<bool>(n,0));
    Nqueen_optimized(grid,n,0);
    cout<<ans;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}