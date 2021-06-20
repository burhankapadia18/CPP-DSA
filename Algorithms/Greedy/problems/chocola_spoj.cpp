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

// https://www.spoj.com/problems/CHOCOLA/
// https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/


int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n>>m;
    n--; m--;
    int x[n], y[m];
    loop(i,0,n-1) cin>>x[i];
    loop(i,0,m-1) cin>>y[i];

    sort(x,x+n,greater<int>()); sort(y,y+m,greater<int>());
    int hc=1, vc=1;
    int cost=0;
    int i=0, j=0;
    while(i<n and j<m) {
        if(x[i] > y[j]) {
            cost += (x[i]*hc);
            vc++;
            i++;
        }
        else {
            cost += (y[j]*vc);
            hc++;
            j++;
        }
    }
    while(i<n) {
        cost += (x[i]*hc);
        i++;
    }
    while(j<m) {
        cost += (y[j]*vc);
        j--;
    }
    cout<<cost;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}