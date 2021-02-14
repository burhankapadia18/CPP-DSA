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

int totalPaths = 0;

bool isSafe(int n,int x, int y, vector<vector<bool> > &vis)
{
    if(x<n && y<n && x>=0 && y>=0 && vis[x][y]==0)
        return 1;
    else 
        return 0;
}

void ratinMaze(vector<vector<int> > &arr, int n, int x, int y, vector<vector<bool> > &vis)
{
    if(x==(n-1) && y==(n-1))
    {
        //solarr[x][y] = 1;
        totalPaths += 1;
        return;
    }

    if(isSafe(n,x,y,vis))
    {
        vis[x][y] = 1;
        if(x+1<n && arr[x+1][y]==0)
            ratinMaze(arr,n,x+1,y,vis);
        if(y+1<n && arr[x][y+1]==0)
            ratinMaze(arr,n,x,y+1,vis);
        if(x-1>=0 && arr[x-1][y]==0)
            ratinMaze(arr,n,x-1,y,vis);
        if(y-1>=0 && arr[x][y-1]==0)
            ratinMaze(arr,n,x,y-1,vis);
        vis[x][y] = 0;
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}