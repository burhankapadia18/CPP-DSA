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

// https://www.geeksforgeeks.org/largest-rectangular-sub-matrix-whose-sum-0/

int subsum(vector<int> &arr, int &st, int &en) {
    int n = arr.size();
    int s = 0;
    int ans = INT_MIN;
    ump<int,int> mp;
    loop(i,0,n-1) {
        s += arr[i];
        if(s == 0) {
            // ans = max(ans,i+1);
            if(i+1 > ans) {
                st = 0; en = i;
                ans = i+1;
            }
        }
        else if(!(mp.find(s) == mp.end())) {
            // ans = max(ans,i-mp[s]+1);
            if((i-mp[s]) > ans) {
                st = mp[s]+1; en = i;
                ans = en-st+1;
            }
        }
        else {
            // mp[s] = 1;
            mp[s] = i;
        }
    }
    return ans;
}
void solve(vector<vector<int> > &mtx) {
    int n = mtx.size();
    int m = mtx[0].size();
    int ans = INT_MIN;
    int tlr, tlc, brr, brc;
    loop(i,0,n-1) {
        vector<int> arr(m,0);
        loop(j,i,n-1) {
            int st, en;
            loop(col,0,m-1) {
                arr[col] += mtx[j][col];
            }
            // ans = max(ans,subsum(arr,st,en)*(j-i+1));
            int temp = subsum(arr,st,en)*(j-i+1);
            if((subsum(arr,st,en)*(j-i+1)) > ans) {
                tlr = i; tlc = st;
                brr = j, brc = en;
                ans = temp;
            }
        }
    }
    cout<<ans<<endl;
    cout<<"("<<tlr<<","<<tlc<<")"<<" <--> "<<"("<<brr<<","<<brc<<")";
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n>>m;
    vector<vector<int> > mtx(n,vector<int>(m));
    loop(i,0,n-1)
        loop(j,0,m-1)
            cin>>mtx[i][j];
    
    solve(mtx);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}