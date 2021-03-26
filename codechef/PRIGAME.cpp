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
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

const int N = 1e6+5;
int res[N];
void sieve()
{
    vector<int>vect;
    bool prime[N];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p < N; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i < N; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = 2; p < N; p++)
        if (prime[p])
            vect.push_back(p);

    auto it = vect.begin();
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if(*it <= i)
        {
            ++cnt;
            ++it;
        }
        res[i] = cnt;
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int t;
    cin>>t;
    sieve();
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(res[x] <= y)
            cout<<"Chef\n";
        else
            cout<<"Divyam\n";
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}