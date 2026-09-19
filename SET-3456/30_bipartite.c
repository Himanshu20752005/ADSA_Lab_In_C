#include <stdio.h>
#define N 100
int main(void){int n,e,g[N][N]={0},col[N],q[N],f,r,u,v;scanf("%d%d",&n,&e);while(e--){scanf("%d%d",&u,&v);g[u][v]=g[v][u]=1;}for(int i=0;i<n;i++)col[i]=-1;
for(int s=0;s<n;s++)if(col[s]<0){f=r=0;q[r++]=s;col[s]=0;while(f<r){u=q[f++];for(v=0;v<n;v++)if(g[u][v]){if(col[v]<0)col[v]=col[u]^1,q[r++]=v;else if(col[v]==col[u]){puts("Not bipartite");return 0;}}}}
puts("Bipartite");return 0;}
