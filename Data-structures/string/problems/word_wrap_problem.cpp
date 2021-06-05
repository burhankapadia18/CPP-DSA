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

// https://practice.geeksforgeeks.org/problems/word-wrap/0

void printP(int p[],int n) {
    if(n==1) {
        cout<<p[n]<<" "<<n<<" ";
    }
    else {
        printP(p,p[n]-1);
        cout<<p[n]<<" "<<n<<" ";
    }
} 
void wordWrap(int arr[], int n, int m) {
    int space[n+1][n+1];
    int cost[n+1][n+1];
    int optCost[n+1];
    int p[n+1];
    for(int i=1; i<=n; i++) {
        space[i][i] = m-arr[i];
        // cost[i][i] = space[i][i]*space[i][i];
        for(int j=i+1; j<=n; j++) {
            space[i][j] = space[i][j-1]-arr[j]-1;
            // if(space[i][j] < 0) {
            //     cost[i][j] = INT_MAX;
            // }
            // else if(j==n and space[i][j]>=0) {
            //     cost[i][j] = 0;
            // }
            // else {
            //     cost[i][j] = space[i][j]*space[i][j];
            // }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            if(space[i][j] < 0) {
                cost[i][j] = INT_MAX;
            }
            else if(j==n and space[i][j]>=0) {
                cost[i][j] = 0;
            }
            else {
                cost[i][j] = space[i][j]*space[i][j];
            }
        }
    }
    optCost[0] = 0;
    for(int i=1; i<=n; i++) {
        optCost[i] = INT_MAX;
        for(int j=1; j<=i; j++) {
            if(optCost[j-1]!=INT_MAX and cost[j][i]!=INT_MAX and optCost[j-1]+cost[j][i]<optCost[i]) {
                optCost[i] = optCost[j-1] + cost[j][i];
                p[i] = j;
            }
        }
    }
    printP(p,n);
    cout<<endl;
} 

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n;
    int arr[n+1];
    loop(i,1,n) cin>>arr[i];
    cin>>m;

    wordWrap(arr,n,m);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}