
#include <bits/stdc++.h>
using namespace std;
typedef long long ln;

int mat[2001][2001];

int main(){

	int n;
	cin >> n;

	vector<int> orginal;

	int preprocess[7]={1,1,0,1,0,0,1};

	for(int i=1;i<=n;i++){

		for(int j=1;j<=n;j++){

			long long dig=(1LL*i*i*j*j);

			dig=dig%7;

			int digit=preprocess[dig];

			if(digit==0)
				mat[i][j]=0;
			else
				mat[i][j]=1;
			orginal.push_back(mat[i][j]);

		}

	}

	int and[4]={0};

	ans[0]=0

	

}