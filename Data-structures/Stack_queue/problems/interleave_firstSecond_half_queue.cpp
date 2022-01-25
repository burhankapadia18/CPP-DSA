#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define uset 			unordered_set
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;


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

// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

void interleaveQueue(queue<int> &Q) {
    int n = Q.size();
    stack<int> s1;
    loop(i,1,n/2) {
        s1.push(Q.front());
        Q.pop();
    }
    while(!s1.empty()) {
        Q.push(s1.top());
        s1.pop();
    }
    loop(i,1,n/2) {
        Q.push(Q.front());
        Q.pop();
    }
    loop(i,1,n/2) {
        s1.push(Q.front());
        Q.pop();
    }
    while(!s1.empty()) {
        Q.push(s1.top());
        Q.push(Q.front());
        s1.pop();
        Q.pop();
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    queue<int> Q;
    int x;
    while(cin>>x) Q.push(x);

    interleaveQueue(Q);

    while(!Q.empty()) {
        cout<<Q.front()<<" ";
        Q.pop();
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}