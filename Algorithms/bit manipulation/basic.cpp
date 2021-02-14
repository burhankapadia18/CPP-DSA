#include<bits/stdc++.h>
using namespace std;

int checking_kth_bit(int n, int k){
    return (((1<<(k-1))&n) != 0);
}
void set_kth_bit(int &n, int k){
    n = ((1<<(k-1)) | n);
}
void clear_kth_bit(int &n, int k){
    n = (~(1<<(k-1)) & n);
}
void toggle_kth_bit(int &n, int k){
    n = ((1<<(k-1)) xor n);
}
void toggle_rightmost_bit(int &n){
    //n = (1 xor n);
    n = n & n-1;
}
int pow_of_two(int n){
    return ((n&(n-1)) == 0);
}
int xply_by_powOfTwo(int n, int k){
    return n<<k;
}
int divide_by_powOfTwo(int n, int k){
    return n>>k;
}

int main() {

    #ifndef ONLINE_JUDGE
      freopen("/Users/burhankapdawala/input.txt","r",stdin);
      freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    cout<<xply_by_powOfTwo(n,3);

    return 0;
}