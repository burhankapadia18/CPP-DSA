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

// https://www.geeksforgeeks.org/program-for-shortest-job-first-or-sjf-cpu-scheduling-set-1-non-preemptive/

bool cmp(vector<int> &a, vector<int> &b) {
    if(a[1] == b[1]) {
        if(a[2] == b[2]) {
            return a[0] < b[0];
        }
        else {
            return a[2] < b[2];
        }
    }
    return a[1] < b[1];
}
int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<vector<int> > arr(n,vector<int>(3));
    loop(i,0,n-1) {
        int id, tym, burst;
        cin>>id>>tym>>burst;
        arr[i][0] = id; arr[i][1] = tym; arr[i][2] = burst;
    }

    sort(arr.begin(), arr.end(),cmp);
    priority_queue<vector<int>, vector<vector<int> >,greater<vector<int> > > pq;
    vector<int> temp(3);
    // temp[0] = arr[0][2]; temp[1] = arr[0][1]; temp[2] = arr[0][0];
    // pq.push(temp);
    pq.push({arr[0][2],arr[0][1],arr[0][0]});
    int i=1;
    int curr_time=0;
    vector<int> ans;
    while(!pq.empty()) {
        int burst = pq.top()[0];
        int id = pq.top()[2];
        pq.pop();
        ans.push_back(id);
        curr_time += burst;
        while(i<n and arr[i][1]<=curr_time) {
            // temp[0] = arr[i][2]; temp[1] = arr[i][1]; temp[2] = arr[i][0];
            // pq.push(temp);
            pq.push({arr[i][2],arr[i][1],arr[i][0]});
            i++;
        }
    }
    for(int i:ans)
        cout<<i<<" ";

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}