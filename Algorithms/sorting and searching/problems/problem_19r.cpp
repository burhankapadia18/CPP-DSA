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

// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0

bool helper(int arr[], int n, int mi, int m) {
    int sum = 0;
    int stu = 1;
    loop(i,0,n-1) {
        if(arr[i] > mi) return false;
        if(sum+arr[i] > mi) {
            stu++;
            sum = arr[i];
            if(stu > m) return false;
        }
        else {
            sum += arr[i];
        }
    }
    return true;
}
int minPages(int arr[], int n, int m) {
    int lo, hi, sum, ans;
    lo = sum = 0;
    loop(i,0,n-1) sum += arr[i];
    hi = sum;
    while(lo <= hi) {
        int mi = mid(lo,hi);
        if(helper(arr,n,mi,m)) {
            ans = mi;
            hi = mi - 1;
        }
        else {
            lo = mi + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n>>m;
    int arr[n];
    loop(i,0,n-1) cin>>arr[i];

    cout<<minPages(arr,n,m);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}