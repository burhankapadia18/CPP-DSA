#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

void subsets(vector<int> &arr, int idx, vector<int> &ans)
{
    if(idx == arr.size())
    {
        for(int i:ans)
            cout<<i<<" ";
        cout<<endl;
        return;
    }

    ans.push_back(arr[idx]);
    subsets(arr,idx+1,ans);
    ans.pop_back();
    subsets(arr,idx+1,ans);
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<int> ans;

    subsets(arr,0,ans);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}