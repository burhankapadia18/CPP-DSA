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

// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/

void kthSmallestAgain(vector<pair<int,int> > &range, vector<int> &queries) {
    sort(range.begin(),range.end());
    int idx = 0, n = range.size();
    loop(i,1,n-1) {
        if(range[idx].ss >= range[i].ff) {
            int s = range[idx].ff;
            int e = max(range[i].ss,range[idx].ss);
            range[idx] = make_pair(s,e);
        } else {
            idx++;
            range[idx] = range[i];
        }
    }
    for(int k:queries) {
        int ans = -1;
        loop(i,0,idx) {
            if(range[i].ss-range[i].ff+1 >= k) {
                ans = range[i].ff+k-1;
                break;
            }
            else {
                k = k - (range[i].ss-range[i].ff+1);
            }
        }
        cout<<ans<<endl;
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, q;
    cin>>n>>q;
    vector<pair<int,int> > range;
    loop(i,0,n-1) {
        int x, y;
        cin>>x>>y;
        range.push_back(make_pair(x,y));
    }
    vector<int> queries;
    loop(i,1,q) {
        int k;
        cin>>k;
        queries.push_back(k);
    }

    kthSmallestAgain(range,queries);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}