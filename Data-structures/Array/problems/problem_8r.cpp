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

// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

int median__(vector<vector<int> > &arr)
{
    int min_ = INT_MAX, max_ = INT_MIN;
    int r = arr.size();
    int c = arr[0].size();
    loop(i,0,r-1)
    {
        min_ = min(min_,arr[i][0]);
        max_ = max(max_,arr[i][c-1]);
    }
    int desired = (r*c+1)/2;
    while(min_ < max_)
    {
        int mid_ = mid(min_,max_);
        int ctr = 0;
        loop(i,0,r-1)
            ctr += upper_bound(arr[i].begin(),arr[i].end(),mid_) - arr[i].begin();
        if(ctr < desired)
            min_ = mid_ + 1;
        else 
            max_ = mid_;
    }
    return min_;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int r, c;
    cin>>r>>c;
    vector<vector<int> > arr(r,vector<int> (c));
    loop(i,0,r-1)
        loop(j,0,c-1)
            cin>>arr[i][j];

    cout<<median__(arr);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}