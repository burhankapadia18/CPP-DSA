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

bool isSafe(int n, int i, int j, vector<vector<int> > &grid)
{
    return i>=0 && j>=0 && i<n && j<n && grid[i][j]==-1;
}
void display(vector<vector<int> > &grid, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<grid[i][j]<<'\t';
        cout<<'\n';
    }
    cout<<'\n';
}
void knightsTour(vector<vector<int> > &grid, int n, int i, int j, int ctr)
{
    if(ctr == n*n-1)
    {   
        grid[i][j] = ctr;
        display(grid,n);
        grid[i][j] = -1;
        return;
    }
    if(ctr >= n*n)
        return; 

    int xdir[] = {-2,-2,-1,-1,2,2,1,1};
    int ydir[] = {1,-1,2,-2,1,-1,2,-2};

    grid[i][j] = ctr;

    for(int k=0; k<8; k++)
        if(isSafe(n,i+xdir[k],j+ydir[k],grid))
           knightsTour(grid,n,i+xdir[k],j+ydir[k],ctr+1);
           
    grid[i][j] = -1;
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<vector<int> > grid(n,vector<int> (n,-1));
    knightsTour(grid,n,0,0,0);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}