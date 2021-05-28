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

void lps(string &str)
{
    int n = str.length(), maxlen = 1, start = 0;
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
    loop(i,0,n-1)
        dp[i][i] = 1;
    loop(i,0,n-2)
        if(str[i] == str[i+1])
        {
            dp[i][i+1] = 1;
            maxlen = 2; start = i;
        }
    for (int k = 3; k <= n; ++k) 
    {
        for (int i = 0; i < n - k + 1; ++i) 
        {
            int j = i + k - 1;
            if (dp[i + 1][j - 1] && str[i] == str[j]) 
            {
                dp[i][j] = true;
                if (k > maxlen) {
                    start = i;  maxlen = k;
                }
            }
        }
    }
    string ans = str.substr(start,maxlen);
    cout<<ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        lps(str);
        cout<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}