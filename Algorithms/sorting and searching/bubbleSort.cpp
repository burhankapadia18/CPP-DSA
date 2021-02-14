#include<iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int a[], int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-1-i; j++) {
			if(a[j]>a[j+1]) {
				swap(a[j], a[j+1]);
			}
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	bubbleSort(a,n);
	for(int i=0; i<n; i++) {
		cout<<a[i]<<" ";
	}

	return 0;

}