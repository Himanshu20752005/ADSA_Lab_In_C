#include <stdio.h>
#define N 100
#define INF 1000000000
int main(void){
 int n,g[N][N],d[N],vis[N]={0},s;
 scanf("%d",&n);for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&g[i][j]);
 scanf("%d",&s);for(int i=0;i<n;i++)d[i]=INF;d[s]=0;
 for(int c=0;c<n;c++){int u=-1;for(int i=0;i<n;i++)if(!vis[i]&&(u<0||d[i]<d[u]))u=i;if(u<0||d[u]==INF)break;vis[u]=1;
  for(int v=0;v<n;v++)if(g[u][v]>=0&&d[u]+g[u][v]<d[v])d[v]=d[u]+g[u][v];
 }
 for(int i=0;i<n;i++)printf("%d -> %d\n",i,d[i]);return 0;
}
