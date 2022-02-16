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

// https://cses.fi/problemset/task/1193

int n, m;
char arr[1000][1000];
bool vis[1000][1000];
int prevStep[1000][1000];
int x[4] = {-1,0,1,0};
int y[4] = {0,1,0,-1};
string dir = "URDL";
void solve() {
    cin>>n>>m;
    pair<int,int> st, en;
    loop(i,0,n-1) {
        loop(j,0,m-1) {
            cin>>arr[i][j];
            if(arr[i][j] == 'A') { st.ff = i; st.ss = j; }
            else if(arr[i][j] == 'B') { en.ff = i; en.ss = j; }
        }
    }
    queue<pair<int,int>> Q;
    Q.push(st);
    vis[st.ff][st.ss] = 1;
    while (!Q.empty()) {
		pair<int,int> u = Q.front(); Q.pop();
		loop(i,0,3) {
			pair<int,int> v = {u.ff+x[i], u.ss+y[i]};
			if (v.ff<0 || v.ff>=n || v.ss<0 || v.ss>=m || arr[v.ff][v.ss] == '#' || vis[v.ff][v.ss]) continue;
			vis[v.ff][v.ss] = true;
			prevStep[v.ff][v.ss] = i;
			Q.push(v);
		}
	}
	if (vis[en.ff][en.ss]) {
		cout<<"YES"<<endl;
		vector<int> steps;
		while (en != st) {
			int p = prevStep[en.ff][en.ss];
			steps.push_back(p);
			en = {en.ff-x[p], en.ss-y[p]};
		}
		reverse(steps.begin(), steps.end());
		cout << steps.size() << endl;
		for (char c : steps) {
			cout<<dir[c];
		}
		cout<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    solve();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}