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

// codechef : DIVSUBS
// same as divisible subarray with slight modifications

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        loop(i,0,n-1) cin>>arr[i];
        vector<vector<int>> freq(n,vector<int>());
        int presum=0;
        bool f=0;
        loop(i,0,n-1) {
            presum += arr[i];
            presum %= n;
            presum = (presum+n)%n;
            if(presum == 0) {
                // we found a subarray from 0 till i which is divisible by N
                cout<<i+1<<endl;
                loop(j,0,i) cout<<j+1<<" ";
                cout<<endl;
                f = 1;
                break;
            }
            freq[presum].push_back(i);
        }
        if(f) break;
        loop(i,0,n-1) {
            if(freq[i].size() > 1) {
                int st = freq[i][0], en = freq[i][1];
                if(st>en) swap(st,en);
                cout<<en-st<<endl;
                loop(j,st+1,en) cout<<j+1<<" ";
                cout<<endl;
                break;
            }
        }
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}