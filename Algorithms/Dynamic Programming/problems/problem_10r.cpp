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
		freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
		freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
	#endif
}

/*
Given 2 strings m and n, return the unique and valid unlock pattern
of android grid that consists of atleast m cells and atmost n cells.

A pattern is considered valid if:
- all the dots in the sequence are distinct.
- the line segment connecting 2 consecutive dots in the sequence 
  passes through other dots, and the other dots must have previously
  appeared. 
*/

int skip[10][10];
int helper(vector<bool> &visited, int currDigit, int remainingDigits) {
	if(remainingDigits < 0) return 0;
	if(remainingDigits == 0) return 1;
	visited[currDigit] = true;
	int result = 0;
	loop(i, 1, 9) {
		if(not visited[i] and (skip[currDigit][i] == 0 or visited[skip[currDigit][i]] == true)) {
			result += helper(visited, i, remainingDigits-1);
		}
	}
	visited[currDigit] = false;
	return result;
}
int helper(vector<bool> &visited, int currDigit, int remainingDigits, string output) {
	if(remainingDigits < 0) return 0;
	if(remainingDigits == 0) {
		cout<<output<<endl;
		return 1;
	}
	visited[currDigit] = true;
	int result = 0;
	loop(i, 1, 9) {
		if(not visited[i] and (skip[currDigit][i] == 0 or visited[skip[currDigit][i]] == true)) {
			result += helper(visited, i, remainingDigits-1, output+to_string(i));
		}
	}
	visited[currDigit] = false;
	return result;
}
int countPatterns(int m, int n) {
	loop(i, 0, 9) {
		loop(j, 0, 9) {
			skip[i][j] = 0;
		}
	}
	skip[1][3] = skip[3][1] = 2;
	skip[1][7] = skip[7][1] = 4;
	skip[9][3] = skip[3][9] = 6;
	skip[7][9] = skip[9][7] = 8;
	skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;

	vector<bool> visited(10, false);
	int result = 0;
	loop(i, m, n) {
		result += helper(visited, 1, i-1)*4;
		result += helper(visited, 2, i-1)*4;
		result += helper(visited, 5, i-1);
	}
	return result;
}


int printPatterns(int m, int n, string output) {
	loop(i, 0, 9) {
		loop(j, 0, 9) {
			skip[i][j] = 0;
		}
	}
	skip[1][3] = skip[3][1] = 2;
	skip[1][7] = skip[7][1] = 4;
	skip[9][3] = skip[3][9] = 6;
	skip[7][9] = skip[9][7] = 8;
	skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;

	vector<bool> visited(10, false);
	int result = 0;
	loop(i, m, n) {
		result += helper(visited, 1, i-1, output + "1");
		result += helper(visited, 2, i-1, output + "2");
		result += helper(visited, 3, i-1, output + "3");
		result += helper(visited, 4, i-1, output + "4");
		result += helper(visited, 5, i-1, output + "5");
		result += helper(visited, 6, i-1, output + "6");
		result += helper(visited, 7, i-1, output + "7");
		result += helper(visited, 8, i-1, output + "8");
		result += helper(visited, 9, i-1, output + "9");
	}
	return result;
}

int main(int argc, char const *argv[])
{
	clock_t begin = clock();
	file_i_o();

	// write your code here

	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif
	return 0;
}