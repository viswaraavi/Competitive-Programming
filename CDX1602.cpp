#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main()
{
    int T;
    scanf("%d\n",&T);
    while(T--)
    {
        int N1,N2,K1,K2;
        scanf("%d %d %d %d",&N1, &N2, &K1, &K2);
        int dp[N1 + 1][N2 + 1][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        for(int i = 0 ; i <= N1; i++)
        {
            for(int j = 0 ; j <= N2; j++)
            {
                for(int k = 1 ; k <= min(K1, i); k++)
                {
                    dp[i][j][0] += dp[i-k][j][1];
                    dp[i][j][0] %= MOD;
                }
                
                for(int k = 1 ; k <= min(K2, j); k++)
                {
                    dp[i][j][1] += dp[i][j-k][0];
                    dp[i][j][1] %= MOD;
                }
                
            }
        }
        
        printf("%d\n",(dp[N1][N2][0] + dp[N1][N2][1])%MOD);
    }
    return 0;
}