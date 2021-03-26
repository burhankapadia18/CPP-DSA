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



int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll t;
    cin>>t;
    while(t--)
    {
        int n,q,m;
        cin>>n>>q>>m;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int b[1000001] = {};
        map<pair<int,int>,int>mp;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            --l;--r;
            if(a[l]>m)
            {
                continue;
            }
            else if(a[l]<=m && a[r]>m)
            {
                b[a[l]]++;
                b[m+1]--;
            }
            else if(a[r]<=m)    
            {
                b[a[l]]++;
                b[m+1]--;
                mp[make_pair(a[l],a[r])]++;
            }
        }
        for(auto x:mp)
        {
            int k = x.first.first;
            int p = x.first.second;
            int l = x.second;
            b[p+k] -= l;
            b[p+2*k] += l;
            int c = p + 2*k;
            while(c+p <= m)
            {
                c += p;
                b[c] -= l;
                b[c+k] += l;
                c += k;
            } 
        }   
        int mx = 0;
        for(int i=1;i<=m;i++)
        {
            b[i] += b[i-1];
            mx = max(mx,b[i]);
        }
        cout<<mx<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}