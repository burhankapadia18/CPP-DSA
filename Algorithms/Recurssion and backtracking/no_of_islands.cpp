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

int ctr = 0;
void count_island_helper(vector<vector<int> > &mtx, int i, int j)
{   
    if(i<0 || j<0 || i>=mtx.size() || j>=mtx[0].size() || !mtx[i][j])
        return;
    
    mtx[i][j] = 0;
    int xdir[] = {-1,1,0,0};
    int ydir[] = {0,0,-1,1};
    for(int k=0; k<4; k++)
        count_island_helper(mtx,i+xdir[k],j+ydir[k]);
}
void count_island(vector<vector<int> > &mtx)
{
        for(int i=0; i<mtx.size(); i++)
            for(int j=0; j<mtx[0].size(); j++)
                if(mtx[i][j])
                {
                    count_island_helper(mtx,i,j);
                    ctr++;
                }
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n>>m;
    vector<vector<int> > mtx(n,vector<int> (m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mtx[i][j];

    count_island(mtx);
    cout<<ctr;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}