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

// spoj problem : AGGRCOW
bool isvalid(vector<int> &arr, int cows, int dist)
{
    int count = 1;
    int lastpos = arr[0];
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i]-lastpos >= dist)
        {
            count++;
            lastpos = arr[i];
        }
        if(count == cows)
            return 1;
    }
    return 0;
}
int distributionOfCows(vector<int> &arr, int cows, int m)
{
    sort(arr.begin(),arr.end());
    int lo = 1, hi = m;
    int result = 0;
    while(lo <= hi)
    {
        int mid_ = mid(lo,hi); // candidate distance
        // we will try to arrnage all the cows mid_ distance apart
        if(isvalid(arr,cows,mid_))
        {
            lo = mid_ + 1;
            result = mid_;
        }
        else 
            hi = mid_ - 1;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n, c;
        cin>>n>>c;
        vector<int> arr(n);
        loop(i,0,n-1)
            cin>>arr[i];
        cout<<distributionOfCows(arr,c,n)<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}