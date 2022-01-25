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

// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

// using 2 queue
class Stack1 {
    queue<int> Q1, Q2;
    public:
    void push(int x) {
        Q1.push(x);
        while(!Q2.empty()) {
            Q1.push(Q2.front());
            Q2.pop();
        }
        swap(Q1,Q2);
    }
    bool pop() {
        if(Q2.empty()) return 0;
        Q2.pop();
        return 1;
    }
    int top() {
        if(Q2.empty()) return -1;
        return Q2.front();
    }
};

// using 1 queue
class Stack2 {
    queue<int> Q;
    public:
    void push(int x) {
        int sz = Q.size();
        Q.push(x);
        while(sz--) {
            Q.push(Q.front());
            Q.pop();
        }
    }
    bool pop() {
        if(Q.empty()) return 0;
        Q.pop();
        return 1;
    }
    int top() {
        if(Q.empty()) return -1;
        return Q.front();
    }
};

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}