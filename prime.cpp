#include <bits/stdc++.h>
#include <iostream> 
#include <cmath>
#include <stdio.h>

using namespace std;

void primenumberchecker(int n){

	if(n%2==0){
		cout << "The number is not prime";
		return;
	}
	for(int i=3;i<sqrt(n);i=i+2){

		if(n%i==0){
			cout << "The number is not prime";
			return;
		}

	}

	cout << "The number is prime";

	return;

}

/*

The princple used is if a numeber is prime then all its multiples are not prime. 

*/

void sieveoferathostheneous(int n){

	bool prime[n+1];
	memset(prime,true,sizeof(prime));

	for(int p=2;p*p<=n;p++){

		if(prime[p]==true){

			for(int j=2*p;j<n;j=j+p){

				prime[j]=false;

		}
			}
	}

	for(int i=2;i<=n;i++){

		if(prime[i]==true){

			cout << i << endl;
		}
	}



}



int main(){

	primenumberchecker(999983);
	//sieveoferathostheneous(1000000);
}