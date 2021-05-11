#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a>b;
}

int main() {

    int arr[5] = {1,2,5,8,7};

    sort(arr,arr+5,cmp);
    
    return 0;
}