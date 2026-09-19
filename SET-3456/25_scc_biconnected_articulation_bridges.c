#include <stdio.h>
#define N 100
int n,g[N][N],disc[N],low[N],tim,stU[N*N],stV[N*N],top;
void scc_dfs(int u,int *idx,int *on,int *stack,int *sp){
 disc[u]=low[u]=++tim;stack[(*sp)++]=u;on[u]=1;
 for(int v=0;v<n;v++)if(g[u][v]){if(!disc[v]){scc_dfs(v,idx,on,stack,sp);if(low[v]<low[u])low[u]=low[v];}else if(on[v]&&disc[v]<low[u])low[u]=disc[v];}
 if(low[u]==disc[u]){printf("SCC: ");int v;do{v=stack[--(*sp)];on[v]=0;printf("%d ",v);}while(v!=u);puts("");}
}
void bcc(int u,int p){
 disc[u]=low[u]=++tim;int child=0;
 for(int v=0;v<n;v++)if(g[u][v]&&v!=p){if(!disc[v]){stU[top]=u;stV[top++]=v;child++;bcc(v,u);if(low[v]<low[u])low[u]=low[v];
   if((p!=-1&&low[v]>=disc[u])||(p==-1&&child>1)){printf("BCC: ");int a,b;do{a=stU[--top];b=stV[top];printf("(%d,%d) ",a,b);}while(a!=u||b!=v);puts("");}
   if(low[v]>=disc[u]){printf("Edges: ");int a,b;do{a=stU[--top];b=stV[top];printf("(%d,%d) ",a,b);}while(a!=u||b!=v);puts("");}
   if(low[v]>disc[u])printf("Bridge: %d-%d\n",u,v);
 }else if(disc[v]<disc[u]){stU[top]=u;stV[top++]=v;if(disc[v]<low[u])low[u]=disc[v];}}
}
int main(void){int m,u,v;scanf("%d%d",&n,&m);while(m--){scanf("%d%d",&u,&v);g[u][v]=g[v][u]=1;}
int idx=0,stack[N],sp=0,on[N]={0};for(int i=0;i<n;i++)if(!disc[i])scc_dfs(i,&idx,on,stack,&sp);
for(int i=0;i<n;i++)disc[i]=low[i]=0;tim=top=0;puts("Biconnected components / articulation points / bridges:");for(int i=0;i<n;i++)if(!disc[i])bcc(i,-1);return 0;}
