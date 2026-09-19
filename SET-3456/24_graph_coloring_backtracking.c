#include <stdio.h>
#define N 100
int n,m,g[N][N],x[N];
int safe(int v,int c){for(int u=0;u<n;u++)if(g[v][u]&&x[u]==c)return 0;return 1;}
int color(int v){if(v==n)return 1;for(int c=1;c<=m;c++)if(safe(v,c)){x[v]=c;if(color(v+1))return 1;x[v]=0;}return 0;}
int main(void){int e,u,v;scanf("%d%d%d",&n,&e,&m);while(e--){scanf("%d%d",&u,&v);g[u][v]=g[v][u]=1;}if(color(0)){for(int i=0;i<n;i++)printf("%d:%d ",i,x[i]);puts("");}else puts("No coloring");return 0;}
