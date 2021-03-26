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

/*
You are given n activities with their start time and their finish time.
select the maximum no. of activities that can be performed by a single
person.(assuming the person can perform single activity at a time)

eg:-    start           end
         1               2 .
         3               4 .
         0               6
         5               7 .        ans = 4 
         8               9 .
         5               9
         1               5
*/
bool cmp(pair<int,int> a, pair<int,int> b)  {return (a.ss<b.ss);}
int maxActivity(vector<pair<int,int> > &activity) 
{
    int ans = 0;
    // sorting on the basis of finish time
    sort(activity.begin(),activity.end(),cmp);
    // we pick the first activity
    int i = 0;
    cout<<"("<<activity[0].ff<<","<<activity[0].ss<<")"<<endl;
    ans += 1;
    for(int j=1; j<activity.size(); ++j)
    {   // if this activity has the start time greater than or equal
        // to the finish time of the previous activity
        // then select it
        if(activity[j].ff >= activity[i].ss) {
            cout<<"("<<activity[j].ff<<","<<activity[j].ss<<")"<<endl;
            i = j;  ans += 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    vector<pair<int,int> > activity;
    int start, finish;
    while(cin>>start>>finish)
        activity.push_back(make_pair(start,finish));

    cout<<maxActivity(activity);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}