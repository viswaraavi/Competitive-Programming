
#include <bits/stdc++.h>
#include <iostream> 
#include <cmath>
#include <stdio.h>

using namespace std;

/*We are trying to construct segment tree from given array. */


int constructutil(int arr[],int ss,int se,int* st,int si){

	if(ss==se){

		st[si]=arr[ss];
		return st[si];
	}

	int mid=ss+(se-ss)/2;

	st[si]=constructutil(arr,ss,mid,st,2*si+1)+constructutil(arr,mid+1,se,st,2*si+2);

	return st[si];

}


	

int *constructsegment(int arr[],int n){

	int height= (int)(ceil(log2(n)));

	int size=2*(int)pow(2,height)-1;

	int *st=new int[size];

	constructutil(arr,0,n-1,st,0);

	return st;

}


int main(){

	 int arr[] = {1, 3, 5, 7, 9, 11};
     int n = sizeof(arr)/sizeof(arr[0]);
     int *st = constructsegment(arr, n);
     int height= (int)(ceil(log2(n)));
	 int size=2*(int)pow(2,height)-1;
     for(int i=0;i<=size-1;i++){

     	cout << st[i] << endl;
     }

}