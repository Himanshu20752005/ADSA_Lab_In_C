#include <stdio.h>
#define N 100
int main(void){int n,m,g[N][N]={0},in[N]={0},q[N],f=0,r=0,u,v,c=0;scanf("%d%d",&n,&m);while(m--){scanf("%d%d",&u,&v);if(!g[u][v])g[u][v]=1,in[v]++;}
for(int i=0;i<n;i++)if(!in[i])q[r++]=i;while(f<r){u=q[f++];printf("%d ",u);c++;for(v=0;v<n;v++)if(g[u][v]&&!--in[v])q[r++]=v;}
if(c<n)puts("\nCycle exists");else puts("");return 0;}
