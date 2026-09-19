#include <stdio.h>
#define N 100
#define INF 1000000000
int main(void){
 int n,g[N][N],key[N],p[N],in[N]={0},total=0;scanf("%d",&n);
 for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&g[i][j]);
 for(int i=0;i<n;i++)key[i]=INF,p[i]=-1;key[0]=0;
 for(int c=0;c<n;c++){int u=-1;for(int i=0;i<n;i++)if(!in[i]&&(u<0||key[i]<key[u]))u=i;in[u]=1;
  if(p[u]>=0){printf("%d-%d %d\n",p[u],u,g[p[u]][u]);total+=g[p[u]][u];}
  for(int v=0;v<n;v++)if(g[u][v]>0&&!in[v]&&g[u][v]<key[v])key[v]=g[u][v],p[v]=u;
 }printf("MST=%d\n",total);return 0;
}
