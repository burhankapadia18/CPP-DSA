#include<iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int a[], int n) {
	for(int i=0; i<n-1; i++) {
		int min = i;
		for(int j=i+1; j<n; j++) {
			if(a[j]<a[min]) {
				min = j;
			}
		}
		swap(a[min],a[i]);
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
	
	selectionSort(a,n);

	for(int i=0; i<n; i++) 
		cout<<a[i]<<" ";

	return 0;

}