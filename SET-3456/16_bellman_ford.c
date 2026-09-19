#include <stdio.h>
#define N 100
#define INF 1000000000
typedef struct{int u,v,w;}Edge;
int main(void){int n,m,s;scanf("%d%d",&n,&m);Edge e[N*N];for(int i=0;i<m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);scanf("%d",&s);
int d[N];for(int i=0;i<n;i++)d[i]=INF;d[s]=0;
for(int k=1;k<n;k++){int ch=0;for(int i=0;i<m;i++)if(d[e[i].u]!=INF&&d[e[i].u]+e[i].w<d[e[i].v])d[e[i].v]=d[e[i].u]+e[i].w,ch=1;if(!ch)break;}
for(int i=0;i<m;i++)if(d[e[i].u]!=INF&&d[e[i].u]+e[i].w<d[e[i].v]){puts("Negative cycle");return 0;}
for(int i=0;i<n;i++)printf("%d -> %d\n",i,d[i]);return 0;}
