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
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

/*
you are given a 2D grid of size m*n filled with integers. find
a rectangle/subgrid with maximum sum of elements.
*/

// O(n^4) approach


// O(n^3) approach
ll kadane(vi &temp, int &start, int &end) {
    ll sum = 0;
    ll maxSum = INT_MIN;
    end = -1;
    int tempstart = 0;
    int n = temp.size();
    loop(i,0,n-1) {
        sum += temp[i];
        if(sum < 0) {
            sum = 0;
            tempstart = i+1;
        }
        else if(sum > maxSum) {
            maxSum = sum;
            start = tempstart;
            end = i;
        }
    }
    if(end != -1)
        return maxSum;
    maxSum = temp[0];
    start = end = 0;
    loop(i,0,n-1)
        if(maxSum < temp[i]) {
            maxSum = temp[i];
            start = end = i;
        }
    return maxSum;
}
vi maxSumRectangle(vector<vi> &arr) {
    ll result = INT_MIN;

    int n = arr.size();
    int m = arr[0].size();
    vi temp(n,0);
    int start, end, tlc, tlr, brc, brr;
    loop(leftCol,0,m-1) {
        temp.assign(n,0);
        loop(rightCol,leftCol,m-1) {
            loop(i,0,n-1)
                temp[i] += arr[i][rightCol];
            int sum = kadane(temp,start,end);
            if(sum > result) {
                result = sum;
                tlc = leftCol;
                brc = rightCol;
                tlr = start;
                brr = end;
            }
        }
    }
    vi ans;
    ans.push_back(result);
    ans.push_back(tlr);
    ans.push_back(tlc);
    ans.push_back(brr);
    ans.push_back(brc);
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n>>m;
    vector<vi> arr(n,vi (m));
    loop(i,0,n-1)
        loop(j,0,m-1)
            cin>>arr[i][j];

    vi result = maxSumRectangle(arr);
    loop(i,0,4)
        cout<<result[i]<<" ";

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}