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

/*
Question :-
There are n persons standing in a row at positions [1-n]. you can do 2 
operations.
    -x : the person at position x left
    ?x : find the nearest person to the right of x that is still standing(not left)

n <= 10^6
Q <= 10^6
*/

ll Get(vi &parent, ll a)
{
    return parent[a] = (parent[a]==a?a:Get(parent,parent[a]));
}
void Union(vi &parent, ll left, ll right)
{
    left = Get(parent,left);
    right = Get(parent,right);
    parent[left] = right;
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    file_i_o();

    // write your code here
    ll n, Q;
    cin>>n>>Q;
    vi parent(n+2);
    loop(i,0,n+1)
        parent[i] = i;
    
    while(Q--)
    {
        char ch;
        int x;
        cin>>ch>>x;
        if(ch == '-')
            Union(parent,x,x+1);
        else 
        {
            ll result = Get(parent,x);
            if(result == n+1)
                cout<<-1<<endl;
            else 
                cout<<result<<endl;
        }
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}