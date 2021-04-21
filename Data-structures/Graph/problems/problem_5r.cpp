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

// https://leetcode.com/problems/clone-graph/

class node {
    public:
    int val;
    vector<node*> neighbour;
    node(int val_) {
        val = val_;
        neighbour = vector<node*>();
    }
};

void dfs(node *original, node *copy, vector<node*> &vis) {
    vis[copy->val] = copy;
    for(auto i:original->neighbour) {
        if(vis[i->val] == NULL) {
            node *newnode = new node(i->val);
            copy->neighbour.push_back(newnode);
        }
        else {
            copy->neighbour.push_back(vis[i->val]);
        }
    }
}
node* cloneGraph(node *node_) {
    if(node_ == NULL)
        return NULL;
    vector<node*> vis(1001,NULL);
    node *copy = new node(node_->val);
    dfs(node_,copy,vis);
    return copy;
}

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