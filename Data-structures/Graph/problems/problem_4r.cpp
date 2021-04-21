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

// https://practice.geeksforgeeks.org/problems/steps-by-knight/0

bool issafe(int i, int j, int n, vector<vector<int> > &arr) {
    return (i<n and j<n and i>=0 and j>=0 and arr[i][j]==0);
}
int minSteps(pair<int,int> pos, pair<int,int> target, int n) {
    if(pos.ff==target.ff and pos.ss==target.ss)
        return 0;
    vector<vector<int> > arr(n,vector<int> (n,0));
    queue<pair<int,int> > Q;
    Q.push(pos);
    arr[pos.ff-1][pos.ss-1];
    while(!Q.empty()) {
        pair<int,int> p = Q.front(); Q.pop();
        int xdir[] = {-2,-2,-1,-1,2,2,1,1};
        int ydir[] = {1,-1,2,-2,1,-1,2,-2};
        loop(i,0,7) {
            if(issafe(p.ff+xdir[i],p.ss+ydir[i],n,arr)) {
                arr[p.ff+xdir[i]][p.ss+ydir[i]] = 1 + arr[p.ff][p.ss];
                Q.push(make_pair(p.ff+xdir[i],p.ss+ydir[i]));
            }
        }
    }
    return arr[target.ff-1][target.ss-1];
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, i, j, x, y;
    cin>>n>>i>>j>>x>>y;

    cout<<minSteps(make_pair(i,j),make_pair(x,y),n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}