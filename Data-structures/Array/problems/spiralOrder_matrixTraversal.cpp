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

void spiral_traversal(vector<vector<int> > &a, int n, int m){
    int row_start = 0;
    int row_end = n-1;
    int column_start = 0;
    int column_end = m-1;

    while(row_start <= row_end && column_start <= column_end){

        // for row start
        for(int col = column_start; col<=column_end; col++)
            cout<<a[row_start][col]<<" ";
        row_start++;

        // for column end 
        for(int row = row_start; row<=row_end; row++)
            cout<<a[row][column_end]<<" ";
        column_end--;

        // for row end
        if(row_start <= row_end)
        for(int col = column_end; col>=column_start; col--)
            cout<<a[row_end][col]<<" ";
        row_end--;

        // for column start
        if(column_start <= column_end)
        for(int row = row_end; row>=row_start; row--)
            cout<<a[row][column_start]<<" ";
        column_start++;
    }
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