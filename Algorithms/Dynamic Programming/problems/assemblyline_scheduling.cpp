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

// https://www.geeksforgeeks.org/assembly-line-scheduling-dp-34/

int carAssembly(vector<vector<int> > &a, vector<vector<int> > &t, int e[], int x[]) {
    int n = a[0].size()-1;
    a[0][0] += e[0];
    a[1][0] += e[1];
    for(int i=1; i<=n; i++) {
        a[0][i] = min(a[0][i]+a[0][i-1],a[0][i]+a[1][i-1]+t[1][i]);
        a[1][i] = min(a[1][i]+a[1][i-1],a[1][i]+a[0][i-1]+t[0][i]);
    }
    return min(a[0][n]+x[0],a[1][n]+x[1]);
    // space optimized
    // int first, second, i;
    // first = e[0]+a[0][0];
    // second = e[1]+a[1][0];
    // for(i=1; i<=n; i++) {
    //     int one = min(first+a[0][i],second+a[0][i]+t[1][i]);
    //     int two = min(second+a[1][i],first+a[1][i]+t[0][i]);
    //     first = one;
    //     second = two;
    // }
    // return min(first+x[0],second+x[1]);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<vector<int> > a(2,vector<int>(n)), t(2,vector<int>(n));
    int e[2], x[2];
    loop(i,0,1)
        loop(j,0,n-1)
            cin>>a[i][j];
    loop(i,0,1)
        loop(j,0,n-1)
            cin>>t[i][j];
    cin>>e[0]>>e[1]>>x[0]>>x[1];


    cout<<carAssembly(a,t,e,x);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}