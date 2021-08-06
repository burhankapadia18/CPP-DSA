#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define uset 				unordered_set
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;


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
Problem Name: Median of Sorted Arrays
Problem Difficulty: None
Problem Constraints: N < 1000
Problem Description:
We are given two sorted arrays of same size n. Find the median of an array formed after merging these two sorted arrays.

Input Format: First line contains the input n. Second and Third line contains n space separated integers.
Sample Input: 5
1 3 5 7 9
2 4 6 8 10
Output Format: Print the median in a single line.
Sample Output: 5
*/

int count(int arr1[], int arr2[], int n, int x) {
    int ans=0;
    loop(i,0,n-1) {
        ans += arr1[i]<=x?1:0;
        ans += arr2[i]<=x?1:0;
    }
    return ans;
}
int median(int arr1[], int arr2[], int n) {
    int lo1 = 0,hi1 = n-1;
    int lo2 = 0,hi2 = n-1;
    if(n == 1){
        return (arr1[0] + arr2[0]) >> 1;
    }
    while(1) {
        int m1,m2,median1,median2;
        m1 = mid(lo1,hi1);
        m2 = mid(lo2,hi2);
        median1 = arr1[m1];
        median2 = arr2[m2];
        if(hi1 - lo1 == 1) {
            return (max(arr1[lo1], arr2[lo1])+min(arr1[hi1], arr2[hi2]))/2;
        }
        if(median1 == median2) return median1;
        if(m1 > m2) {
            hi1 = m1;
            lo2 = m2;
        }
        else {
            hi2 = m2;
            lo1 = m1;

        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    int arr1[n], arr2[n];
    loop(i,0,n-1) cin>>arr1[i];
    loop(i,0,n-1) cin>>arr2[i];

    cout<<median(arr1,arr2,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}