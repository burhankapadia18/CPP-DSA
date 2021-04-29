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

// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

void count_island_helper(vector<vector<int> > &mtx, int i, int j)
{   
    if(i<0 || j<0 || i>=mtx.size() || j>=mtx[0].size() || !mtx[i][j])
        return;
    
    mtx[i][j] = 0;
    int xdir[] = {-1,1,0,0,-1,-1,1,1};
    int ydir[] = {0,0,-1,1,-1,1,-1,1};
    for(int k=0; k<8; k++)
        count_island_helper(mtx,i+xdir[k],j+ydir[k]);
}
int count_island(vector<vector<int> > &mtx)
{   
    int ctr = 0;
    for(int i=0; i<mtx.size(); i++)
        for(int j=0; j<mtx[0].size(); j++)
            if(mtx[i][j])
            {
                count_island_helper(mtx,i,j);
                ctr++;
            }
    return ctr;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n,m;
    cin>>n>>m;
    vector<vector<int> > mtx(n,vector<int> (m));
    loop(i,0,n-1)
        loop(j,0,m-1)
            cin>>mtx[i][j];

    cout<<count_island(mtx);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}