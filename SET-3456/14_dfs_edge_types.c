#include <stdio.h>
#define N 100
int g[N][N],n,tin[N],tout[N],timer;
void dfs(int u){
 tin[u]=++timer;
 for(int v=0;v<n;v++)if(g[u][v]){
  if(!tin[v]){printf("%d-%d tree\n",u,v);dfs(v);}
  else if(!tout[v])printf("%d-%d back\n",u,v);
  else if(tin[u]<tin[v])printf("%d-%d forward\n",u,v);
  else printf("%d-%d cross\n",u,v);
 }
 tout[u]=++timer;
}
int main(void){int m,u,v;scanf("%d%d",&n,&m);while(m--){scanf("%d%d",&u,&v);g[u][v]=1;}for(int i=0;i<n;i++)if(!tin[i])dfs(i);return 0;}
