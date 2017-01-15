#include <bits/stdc++.h>
#include <iostream> 
#include <cmath>
#include <stdio.h>

using namespace std;

int gcd(int a,int b){

	if(a==0)
		return b;

	return gcd(b%a,a);

}

int main(){

	cout << gcd(35,10);
}