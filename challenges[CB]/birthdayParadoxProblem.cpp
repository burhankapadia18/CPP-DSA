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

/*
Problem Name: Birthday Paradox
Problem Difficulty: None
Problem Constraints: 0<p<=1
Problem Description:
Your task is simple, determine  the minimum number of people required in the room so that two have same birthday with probability greater than or equal to 'p'. (Assume there are 365 days in every year)

Input Format: Single line containing the given probability.
Sample Input: 0.5
Output Format: Print an integral value denoting minimum number of people.
Sample Output: 23
*/

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    float p;
    cin>>p;
    if(p==1.0) {
        cout<<366;
        return 0;
    }
    float x = 1;
    int people = 0;
    float num=365, denom=365;
    while(x > 1-p) {
        x = x*(num)/denom;
        people++;
        num--;
        // cout<<"people: "<<people<<"\t| "<<"x: "<<x<<endl;
    }
    cout<<people;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}