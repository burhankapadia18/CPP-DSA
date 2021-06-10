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

// https://practice.geeksforgeeks.org/problems/minimum-platforms/0

bool cmp1(pair<int,int> a, pair<int,int> b) {
    return a.ff < b.ff;
}
class cmp2 {
    public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.ff > b.ff;
    }
};
int reqPlatforms(int arr[], int dep[], int n) {
    // normal approach 
    vector<pair<int,int> > train(n);
    loop(i,0,n-1) train[i] = make_pair(arr[i],dep[i]);
    sort(train.begin(),train.end(),cmp1);
    priority_queue<pair<int,int>, vector<pair<int,int> >, cmp2> pq;
    int pf = 1;
    pq.push(make_pair(train[0].ss,pf));
    loop(i,1,n-1) {
        int en = pq.top().ff, p = pq.top().ss;
        if(en < train[i].ff) {
            pq.pop();
            pq.push(make_pair(train[i].ss,p));
        }
        else {
            pq.push(make_pair(train[i].ss,++pf));
        }
    }
    return pf;

    // optimized approach
    // sort(arr,arr+n);
    // sort(dep,dep+n);
    // int i=1, j=0;
    // int pf = 1;
    // while(i<n) {
    //     if(arr[i] <= dep[j])
    //         pf++;
    //     else 
    //         j++;
    //     i++;
    // }
    // return pf;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    int arr[n], dep[n];
    loop(i,0,n-1) {
        int a, d;
        cin>>a>>d;
        arr[i] = a; dep[i] = d;
    }

    cout<<reqPlatforms(arr,dep,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}