#include <stdio.h>
#define N 100
int g[N][N],n,vis[N],bestMin=N+1,bestMax=0,path[N],plen;
void dfs(int s,int u){
 for(int v=0;v<n;v++)if(g[u][v]){
  if(v==s&&plen>=2){int L=plen;if(L<bestMin)bestMin=L;if(L>bestMax)bestMax=L;}
  else if(!vis[v]&&v>s){vis[v]=1;path[plen++]=v;dfs(s,v);plen--;vis[v]=0;}
 }
}
int main(void){int m,u,v;scanf("%d%d",&n,&m);while(m--){scanf("%d%d",&u,&v);g[u][v]=g[v][u]=1;}
for(int s=0;s<n;s++){vis[s]=1;plen=1;path[0]=s;dfs(s,s);vis[s]=0;}
if(!bestMax)puts("No cycle");else printf("Smallest=%d, Largest=%d\n",bestMin,bestMax);return 0;}
