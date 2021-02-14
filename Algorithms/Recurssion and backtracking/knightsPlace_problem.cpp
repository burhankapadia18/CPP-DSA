#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

void display(vector<vector<bool> > &grid, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(grid[i][j])
                cout<<"K"<<" ";
            else 
                cout<<"."<<" ";
        cout<<'\n';
    }
    cout<<'\n';
}
bool isSafe(vector<vector<bool> > &grid, int n, int r, int c)
{
    if(r-2 >= 0 && c-1 >= 0 && grid[r-2][c-1]) return 0;
    if(r-1 >= 0 && c-2 >= 0 && grid[r-1][c-2]) return 0;
    if(r-2 >= 0 && c+1 < n && grid[r-2][c+1]) return 0;
    if(r-1 >= 0 && c+2 < n && grid[r-1][c+2]) return 0;

    return 1;
}
int ans = 0;
void placeKnights(vector<vector<bool> > &grid, int n, int cr, int cc, int count)
{
    if(count == n)
    {
        ans++;
        display(grid,n);
        return;
    }

    for(int i=cr; i<n; i++)
        for(int j = (i==cr?cc:0); j<n; j++)
            if(isSafe(grid,n,i,j))
            {
                grid[i][j] = 1;
                placeKnights(grid,n,i,j+1,count+1);
                grid[i][j] = 0;
            }
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<vector<bool> > grid(n,vector<bool> (n,0));
    placeKnights(grid,n,0,0,0);
    cout<<ans;


    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}