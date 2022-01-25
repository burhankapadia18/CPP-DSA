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

// https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/

class stack_ {
    int *arr, *top, *next;
    int n, k, fre;
    public:
    stack_(int n, int k) {
        arr = new int[n];
        next = new int[n];
        top = new int[k];
        fre = 0;
        loop(i,0,n-1) {
            top[i] = -1;
            next[i] = i+1;
        }
        next[k-1] = -1;
    }
    bool push(int sn, int val) {
        if(fre == -1) return 0;
        int i = fre;
        fre = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = val;
        return 1;
    }
    bool pop(int sn) {
        if(top[sn] == -1) return 0;
        int i = top[sn];
        top[sn] = next[i];
        next[i] = fre;
        fre = i;
        return 1;
    }
    int getTop(int sn) {
        return top[sn]==-1?-1:arr[top[sn]];
    }
};

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