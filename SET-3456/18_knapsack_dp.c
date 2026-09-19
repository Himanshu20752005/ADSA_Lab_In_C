#include <stdio.h>
#define M 1000
int main(void){int n,W,w[100],v[100],dp[M+1];scanf("%d%d",&n,&W);for(int i=0;i<n;i++)scanf("%d%d",&w[i],&v[i]);
for(int c=0;c<=W;c++)dp[c]=0;for(int i=0;i<n;i++)for(int c=W;c>=w[i];c--)if(dp[c-w[i]]+v[i]>dp[c])dp[c]=dp[c-w[i]]+v[i];
printf("Maximum value=%d\n",dp[W]);return 0;}
