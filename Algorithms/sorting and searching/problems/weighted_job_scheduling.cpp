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

// https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/

bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}
int weightedjobScheduling(vector<vector<int> > &jobs) {
    int n = jobs.size();
    sort(jobs.begin(),jobs.end(),cmp);
    vector<int> dp(n);
    dp[0] = jobs[0][2];
    loop(i,1,n-1) {
        int inc = jobs[i][2];
        int last = -1;
        int lo = 0, hi = i-1;
        while(lo <= hi) {
            int mi = mid(lo,hi);
            if(jobs[mi][1] <= jobs[i][0]) {
                last = mi;
                lo = mi + 1;
            }
            else 
                hi = mi - 1;
        }
        if(last != -1)
            inc += dp[last];
        int exc = dp[i-1];
        dp[i] = max(inc,exc);
        cout<<inc<<" "<<exc<<" "<<endl;
    }
    return dp[n-1];
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<vector<int> > jobs(n,vector<int> (3));
    int st, en, wt;
    loop(i,0,n-1) {
        cin>>st>>en>>wt;
        jobs[i][0] = st;
        jobs[i][1] = en;
        jobs[i][2] = wt;
    }

    cout<<weightedjobScheduling(jobs);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}