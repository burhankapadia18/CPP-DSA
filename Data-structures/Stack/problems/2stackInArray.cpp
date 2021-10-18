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

// https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

class stack2 {
    int *arr, n;
    int top1, top2;
    public:
    stack2(int n) {
        this->n = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }
    bool push1(int x) {
        if(top1+1 == top2) return 0;
        arr[++top1] = x;
        return 1;
    }
    bool push2(int x) {
        if(top2-1 == top1) return 0;
        arr[--top2] = x;
        return 1;
    }
    bool pop1() {
        if(top1 == -1) return 0;
        top1--;
        return 1;
    }
    bool pop2() {
        if(top2 == n) return 0;
        top2++;
        return 1;
    }
    int getTop1() {
        return top1==-1?INT_MAX:arr[top1];
    }
    int getTop2() {
        return top2==n?INT_MAX:arr[top2];
    }
};

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    stack2 S(5);
    cout<<S.push1(1)<<endl;
    cout<<S.getTop1()<<" "<<S.getTop2()<<endl;
    cout<<S.push1(2)<<endl;
    cout<<S.getTop1()<<" "<<S.getTop2()<<endl;
    cout<<S.push2(3)<<endl;
    cout<<S.getTop1()<<" "<<S.getTop2()<<endl;
    cout<<S.push2(4)<<endl;
    cout<<S.getTop1()<<" "<<S.getTop2()<<endl;
    cout<<S.push2(5)<<endl;
    cout<<S.getTop1()<<" "<<S.getTop2()<<endl;
    cout<<S.push1(6)<<" "<<S.pop1()<<endl;
    cout<<S.getTop1()<<" "<<S.getTop2()<<endl;
    cout<<S.push2(6)<<endl;
    cout<<S.getTop1()<<" "<<S.getTop2()<<endl;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}