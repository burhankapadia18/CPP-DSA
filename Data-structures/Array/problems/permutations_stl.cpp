#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > permute(vector<int> nums){

    vector<vector<int> > ans;
    sort(nums.begin(),nums.end());
    do {
        ans.push_back(nums);
    } while(next_permutation(nums.begin(),nums.end()));
    
    return ans;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<vector<int> > res = permute(arr);
    for(auto i:res){
        for(auto ii:i)
            cout<<ii<<" ";
        cout<<endl;
    }

    return 0;
}