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

// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

class node {
    public:
    int val;
    node *prev, *next;
    node(int val) {
        this->val = val;
        prev = next = NULL;
    }
};

class stack_ {
    node *top, *mid;
    int cnt;
    public:
    stack_() {
        top = new node(INT_MIN);
        mid = top;
        cnt = 0;
    }
    void push(int val) {
        node *pt = new node(val);
        pt->next = top;
        top->prev = pt;
        top = pt;
        cnt++;
        if(cnt == 1 or !(cnt&1)) {
            mid = mid->prev;
        }
    }
    void pop() {
        if(top->val == INT_MIN)
            return;
        node *pt = top;
        top = top->next;
        delete(pt);
        cnt--;
        if(cnt&1) {
            mid = mid->next;
        }
    }
    int getTop() {
        return top->val;
    }
    int getMid() {
        return mid->val;
    }
};

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    stack_ S;
    S.push(1);
    cout<<S.getTop()<<" "<<S.getMid()<<endl;
    S.push(2);
    cout<<S.getTop()<<" "<<S.getMid()<<endl;
    S.push(3);
    cout<<S.getTop()<<" "<<S.getMid()<<endl;
    S.push(4);
    cout<<S.getTop()<<" "<<S.getMid()<<endl;
    S.pop();
    cout<<S.getTop()<<" "<<S.getMid()<<endl;
    S.push(5);
    cout<<S.getTop()<<" "<<S.getMid()<<endl;
    S.push(6);
    cout<<S.getTop()<<" "<<S.getMid()<<endl;
    S.push(7);
    cout<<S.getTop()<<" "<<S.getMid()<<endl;
    S.pop();
    cout<<S.getTop()<<" "<<S.getMid()<<endl;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}