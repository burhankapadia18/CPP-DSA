#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void solve(vector<int> &nums, vector<vector<int> > &ans, int idx){

    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }
    unordered_set<int> S;
    for(int i=idx; i<nums.size(); i++){
        if(S.count(nums[i])>0)
            continue;
        S.insert(nums[i]);
        swap(nums[i],nums[idx]);
        solve(nums,ans,idx+1);
        swap(nums[i],nums[idx]);
    }
}
vector<vector<int> > permute(vector<int> nums){
    vector<vector<int> > ans;
    solve(nums,ans,0);
    return ans;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    // can contain duplicates
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

