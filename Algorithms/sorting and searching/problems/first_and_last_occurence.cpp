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
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

int first(int arr[], int n, int x) {
    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid_ = mid(lo,hi);
        if((mid_ == 0 or arr[mid_-1] < x) and arr[mid_] == x)
            return mid_;
        else if(arr[mid_] < x)
            lo = mid_ + 1;
        else 
            hi = mid_ - 1;
    }
    return -1;
}
int last(int arr[], int n ,int x)
{   
    int hi = n-1, lo = 0;
    while(lo <= hi) {
        int mid_ = mid(lo,hi);
        if((mid_ == n - 1 or x < arr[mid_+1]) and arr[mid_] == x)
            return mid_;
        else if (x < arr[mid_])
            hi = mid_ - 1;
        else
            lo = mid_ + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    int arr[n];
    loop(i,0,n-1)
        cin>>arr[i];
    int x;
    cin>>x;

    cout<<first(arr,n,x)<<" "<<last(arr,n,x);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}