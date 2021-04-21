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

// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

// brute force
int solve(int arr[], int n, int x) {
    int ans = 0;
    loop(i,0,n-1)
        loop(j,i+1,n-1)
            loop(k,j+1,n-1)
                if(arr[i]+arr[j]+arr[k] < x)
                    ans++;
    return ans;
}

// optimized
int solve_(int arr[], int n, int x) {
    int ans = 0;
    sort(arr,arr+n);
    loop(k,0,n-3) {
        int i = k+1, j = n-1;
        while(i<j) {
            int s = arr[i]+arr[j]+arr[k];
            if(s < x) {
                ans += (j-i);
                i++;
            }
            else 
                j--;    
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    int arr[n];
    loop(i,0,n-1) cin>>arr[i];
    int x;
    cin>>x;
    
    cout<<solve(arr,n,x)<<" "<<solve_(arr,n,x);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}