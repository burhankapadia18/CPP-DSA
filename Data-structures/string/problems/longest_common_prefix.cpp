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

// https://leetcode.com/problems/longest-common-prefix/

void longest_common_prefix(vector<string> v) {
    if(v.size() == 0)
        return;
    string ans = "";
    for(int i=0; i<v[0].length(); i++) {
        int j;
        for(j=1; j<v.size(); j++) {
            if(i < v[j].length()) {
                if(!(v[j][i] == v[j-1][i])) {
                    break;
                }
            }
        }
        if(j == v.size()) {
            ans += v[0][i];
        } 
        else {
            break;
        }
    }
    cout<<ans;

    // int mi = INT_MAX;
    // if(v.size() == 0) return "";
    // string c = v[0];
    // for(int i=1; i<v.size(); i++) {
    //     int j=0, k=0, a=0;
    //     while(j<c.size() and k<v[i].size()) {
    //         if(c[j] == v[i][k]) a++;
    //         else break;
    //         j++; k++;
    //     }
    //     mi = min(a,mi);
    // }
    // cout<<c.substr(0,mi);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    vector<string> v;
    string s;
    while(cin>>s)
        v.push_back(s);

    longest_common_prefix(v);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}