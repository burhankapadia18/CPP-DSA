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
#define uset 			unordered_set
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

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// TC: O(n^2), SC: O(n)
int celeb_find(vector<vector<int>> &arr) {
    int n = arr.size();
    vector<int> inOut(n,0);
    loop(i,0,n-1) {
        loop(j,0,n-1) {
            if(arr[i][j]) {
                inOut[i] -= 1;
                inOut[j] += 1;
            }
        }
    }
    loop(i,0,n-1) {
        if(inOut[i] == n-1) 
            return i;
    }
    return -1;
}

// TC: O(n), SC: O(1)
int find_celeb(vector<vector<int>> &arr) {
    int n=arr.size(), celeb = 0;
    loop(i,0,n-1) {
        if(arr[celeb][i]) {
            celeb = i;
        }
    }
    loop(i,0,n-1) {
        if(i!=celeb and (arr[celeb][i] or !arr[i][celeb])) {
            return -1;
        }
    }
    return celeb;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    loop(i,0,n-1) {
        loop(j,0,n-1) {
            cin>>arr[i][j];
        }
    }

    cout<<celeb_find(arr);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}