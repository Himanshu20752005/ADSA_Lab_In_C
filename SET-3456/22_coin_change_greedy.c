#include <stdio.h>
int main(void){int n,amt,c[100];scanf("%d%d",&n,&amt);for(int i=0;i<n;i++)scanf("%d",&c[i]);
for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(c[j]>c[i]){int t=c[i];c[i]=c[j];c[j]=t;}
int cnt=0;for(int i=0;i<n;i++)while(amt>=c[i])amt-=c[i],printf("%d ",c[i]),cnt++;
printf("\nCoins=%d Remaining=%d\n",cnt,amt);return 0;}
