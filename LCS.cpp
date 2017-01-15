/* The problem statement is to find the longest palindromic subequence. */

/* First step in solving the problem is to write recursion 
f(something)=f(something)
In string problems generrally the subproblems are prefixes or sufffixes or substring. In this problem the sub problem is nothing but substring
something is indices i and j which specifies the position for palindromic string.

f(i,j)=2+f(i+1,j-1) if A[i]==A[j]
f(i,j)=max(f(i+1,j),f(i,j-1)) if A[i] != A[j]

Now base case is if i-j==1 then f(i,j)=1

*/

#include <bits/stdc++.h>
#include <iostream> 
#include <cmath>

using namespace std;

string A="forgeeksskeegfor";

int dp[100][100];

int LPS(int i,int j){
	if(abs(j-i)==0) return 1;
	if(abs(j-i)==1 and A[i]==A[j]) return 2;
	int &ret=dp[i][j];
	if(ret=!-1) return ret;
	if(A[i]==A[j]){
		ret=2+LPS(i+1,j-1);
		return ret;
	}
	else{
		ret=max(LPS(i+1,j),LPS(i,j-1));
		return ret;
	}
}

int main(){

	memset(dp,-1,sizeof dp);
	cout << LCS(0,A.length()-1);

}
