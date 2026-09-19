#include <stdio.h>
#define N 100
#define INF 1000000000
int main(void){int n,d[N][N];scanf("%d",&n);for(int i=0;i<n;i++)for(int j=0;j<n;j++){scanf("%d",&d[i][j]);if(i!=j&&d[i][j]<0)d[i][j]=INF;}
for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(d[i][k]<INF&&d[k][j]<INF&&d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];
for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf(d[i][j]>=INF?"INF ":"%d ",d[i][j]);puts("");}return 0;}
