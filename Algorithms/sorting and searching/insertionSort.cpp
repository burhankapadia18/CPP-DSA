#include<iostream>
using namespace std;

void insertionSort(int a[], int n) {
	for(int i=1; i<n; i++) {
		int value = a[i];
		int hole = i;
		while( hole>0 && (a[hole-1]>value) ) {
			a[hole] = a[hole-1];
			hole--;
		}
		a[hole] = value;
	}
}

int main() {

	#ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++) 
		cin>>a[i];
	
	insertionSort(a,n);
	for(int i=0; i<n; i++) 
		cout<<a[i]<<" ";

	return 0;
}