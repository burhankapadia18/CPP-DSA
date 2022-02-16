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

// https://www.spoj.com/problems/INVCNT/

int invCount(int *arr, int n) {
    // brute-force
    int invCnt = 0;
    loop(i,0,n-1) {
        loop(j,i+1,n-1) {
            if(arr[i]>arr[j]) invCnt++;
        }
    }
    return invCnt;
}

int modified_merge(int *arr, int *tmp, int left, int mi, int right) {
    int invCnt=0, i=left, j=mi, k=left;
    while(i<mi and j<=right) {
        if(arr[i]<=arr[j]) {
            tmp[k++] = arr[i++];
        }
        else {
            // case where arr[i]>arr[j] and i<j so every element ahead of
            // arr[i] till arr[mi] will make a pair with arr[j]
            tmp[k++] = arr[j++];
            invCnt += mi-i;
        }
    }
    while(i<mi) tmp[k++] = arr[i++];
    while(j<=right) tmp[k++] = arr[j++];
    loop(i,left,right) arr[i] = tmp[i];
    return invCnt;
}
int modified_ms(int *arr, int *tmp, int left, int right) {
    int invCnt = 0;
    if(left < right) {
        int mi = mid(left,right);
        invCnt += modified_ms(arr,tmp,left,mi);
        invCnt += modified_ms(arr,tmp,mi+1,right);
        invCnt += modified_merge(arr,tmp,left,mi+1,right);
    }
    return invCnt;
}
void solve() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int *arr = new int[n], *tmp = new int[n];
        loop(i,0,n-1) cin>>arr[i];

        int invCnt = modified_ms(arr,tmp,0,n-1);
        cout<<invCnt<<" ";

        delete[] arr;
        delete[] tmp;
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    solve();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}