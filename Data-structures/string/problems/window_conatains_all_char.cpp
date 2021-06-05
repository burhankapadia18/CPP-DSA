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

// https://practice.geeksforgeeks.org/problems/smallest-distant-window/0

void solve(string &str) {
    unordered_map<char,int> mp;
    int l = str.length();
    loop(i,0,l-1) mp[str[i]] = 0;
    int n = mp.size();
    int i=0, j=1;
    mp[str[i]]++;
    int ctr=1;
    int ans = INT_MAX;
    while(i<=j and j<str.length()) {
        if(ctr < n) {
            if(mp[str[j]]==0)
                ctr++;
            mp[str[j]]++;
            j++;
        } 
        else if(ctr == n) {
            ans = min(ans,j-i);
            if(mp[str[i]]==1)
                ctr--;
            mp[str[i]]--;
            i++;
        }
    }
    while(ctr == n) {
        ans = min(ans,j-i);
        if(mp[str[i]]==1)
            ctr--;
        mp[str[i]]--;
        i++;
    }
    cout<<ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string s;
    cin>>s;

    solve(s);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}