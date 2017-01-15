

/*
Problem Statement
Hash functions are primarily used to generate fixed-length output data that acts as a shortened reference to the original data. This is useful when the original data is too cumbersome to use in its entirety.One practical use is a data structure called a hash table where the data is stored associatively. Searching linearly for a person's name in a list becomes cumbersome as the length of the list increases, but the hashed value can be used to store a reference to the original data and retrieve constant time (barring collisions).

It involves mapping an element into a numerical value using some mathematical function. In this problem we will consider a simple hash system. It involves assigning numerical value to the alphabets and summing these values of the characters.

For example, the string “acm” is mapped to 1 + 3 + 13 = 17. Unfortunately, this method does not give one-to-one mapping. The string “adl” also maps to 17 (1 + 4 + 12). This is called collision.

In this problem you will have to find the number of strings of length L, which maps to an integer S, using the above hash function. You have to consider strings that have only lowercase letters and uppercase letters in strictly ascending order. 

*NB: all lowercase letters are smaller than all uppercase letters: Example: ‘z’ < ‘A’

Suppose L = 3 and S = 10, there are 4 such strings:(abg , acf , ade , bce )

agb also produces 10 but the letters are not strictly in ascending order.

bh also produces 10 but it has 2 letters.
*/

/*
Solving this problems using dynamic programming.


First lets try to understand the problem. We are given a length and sum. We need to count all the strings that would return the sum. The first step is writing recursion.
Lets try to write a recursion in this way. Let f be a function which gives the count of the string of particular length that would return sum.

f(something)=f(something)

Now what that something is this is the most difficult step in solving the problem ?

So ofcourse sum should be one parameter. But how this sum is made with some sequence of characters so we need some sequence of alphabets. ofcourse we need length also. Deciding this thing needs some practice.

the sequence is A=abcdef.........YZ

Let n represent the position in sequence.

f(n,sum,len)=?

Now how can we write recursion that is valid ?. There is a choice that we can make we can either choose this character to be in sequence or not. if we choose the character to be in sequence 
That is one way. Or we can choose the character not to be in sequence then

f(n,sum,len)=f(n+1,sum-A[n],len+1)+f(n+1,sum,len)

Now what is base case when we have reached the end of sequence and sum=0 and len=0 that should return us 1 because the sequence of recursive calls that are made brought us to the leaf. So the choosing 
of the characters should be valid  .

so f(end,0,0)=1 

And in all other cases when we reach the end of sequence we should return 0

so f(end,anything,anything)=0

Now lets write top down recursive programm for this 

*/

#include <bits/stdc++.h>
using namespace std ;
typedef long long ln;

ln dp[60][60][1500];

int A[60],N,L,S;


ln AUHASH(int n,int sum,int len){
	if(n==N){
		return(sum==0 and len==0);	
	}
	if(sum<0 or len <0){
		return 0;
	}
	ln &ret=dp[n][len][sum];
	if(ret!=-1) return ret;
	ret=0;
	ret=AUHASH(n+1,sum-A[n],len-1)+AUHASH(n+1,sum,len);
	return ret;
}



int main(int argc, char const *argv[])
{
	N=52;
	for(int i=1;i<=N;i++) A[i-1]=i;
	memset(dp,-1,sizeof dp);
	cout << AUHASH(0,19,5);
	return 0;
}












