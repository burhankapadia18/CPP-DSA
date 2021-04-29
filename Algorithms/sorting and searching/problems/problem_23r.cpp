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

// https://www.spoj.com/problems/SUBSUMS/

void getSubsetSum(int arr[], int i, int n, vector<int> &sums, int sum=0) {
    if( i > n) {
        sums.push_back(sum);
        return;
    }
    getSubsetSum(arr,i+1,n,sums,sum);
    getSubsetSum(arr,i+1,n,sums,sum+arr[i]);
}
int solve(int arr[], int n, int a, int b) {
    vector<int> v1, v2;
    getSubsetSum(arr,0,(n/2)-1,v1);
    getSubsetSum(arr,n/2,n-1,v2);
    sort(v2.begin(),v2.end());
    int ans = 0;
    for(int i=0; i<v1.size(); i++) {
        int lo = lower_bound(v2.begin(),v2.end(),a-v1[i]) - v2.begin();
        int hi = upper_bound(v2.begin(),v2.end(),b-v1[i]) - v2.begin();
        ans += (hi-lo);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, a, b;
    cin>>n>>a>>b;
    int arr[n];
    loop(i,0,n-1) cin>>arr[i];

    cout<<solve(arr,n,a,b);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}