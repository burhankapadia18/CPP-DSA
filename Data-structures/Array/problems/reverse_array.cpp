#include<iostream>
using namespace std;

void reverse(char a[], int n){
	for(int i=0, j=n-1; i<j; i++, j--) {
		char temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

int main() {

	#ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

	int n;
	cin>>n;
	char a[n];
	cin>>a;
	cout<<a;
	cout<<endl;
	reverse(a,n);
	cout<<a;
	return 0;

}