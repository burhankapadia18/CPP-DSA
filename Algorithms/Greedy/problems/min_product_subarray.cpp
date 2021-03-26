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

/*
Given an array, find the minimum product possible with the subset of elements
persent int he array.
eg:  a[] = {-1,-1,-2,4,3}    ans = -24
*/

int minProduct(int *arr, int n)
{
    if(n==1)
        return arr[0];

    int neg_count = 0;
    int zero_count = 0;
    int max_neg = INT_MIN;
    int min_pos = INT_MAX;
    int product = 1;
    loop(i,0,n-1)
    {
        if(arr[i] == 0) {
            zero_count += 1;
            continue;
        }
        if(arr[i] < 0) {
            max_neg = max(max_neg,arr[i]);
            neg_count += 1;
        }
        if(arr[i]>0 and arr[i]<min_pos) 
            min_pos = arr[i];
        product *= arr[i];
    }
    if(zero_count == n or neg_count == 0 and zero_count > 0) 
        return 0;

    if(neg_count == 0)
        return min_pos;

    if(neg_count%2==0 and neg_count!=0)
        return product/max_neg;
    
    return product;
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

    cout<<minProduct(arr,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}