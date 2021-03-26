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
https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
*/
bool cmp(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b) {
    return (a.ss.ss>b.ss.ss);
}
void jobSequencing(vector<pair<int,pair<int,int> > > &jobs)
{
    // sort in decreasing order of profit
    sort(jobs.begin(),jobs.end(),cmp);
    int slots = jobs.size(), profit = 0;
    // to keep the track of free time slots
    bool result[slots];
    // to store the result
    vector<int> ans;
    // iterate over all the jobs
    for(int i=0; i<jobs.size(); ++i)
    {   // find a free slot for the current job
        // we find the slot form the end
        int j = min(slots-1,jobs[i].ss.ff-1);
        for(; j>=0; j--)
        {
            if(!result[j]) {
                // empty slot found 
                result[j] = 1;
                ans.push_back(jobs[i].ff);
                profit += jobs[i].ss.ss;
                break;
            }
        }
    }
    cout<<profit<<" "<<ans.size();
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    vector<pair<int,pair<int,int> > > jobs;
    int job_id, deadline, profit;
    while(cin>>job_id>>deadline>>profit)
        jobs.push_back(make_pair(job_id,make_pair(deadline,profit)));

    jobSequencing(jobs);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}