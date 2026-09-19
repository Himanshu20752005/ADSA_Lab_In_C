#include <stdio.h>
#define N 100
int n,g[N][N],path[N],used[N];
int solve(int pos){if(pos==n)return g[path[n-1]][path[0]];for(int v=1;v<n;v++)if(!used[v]&&g[path[pos-1]][v]){used[v]=1;path[pos]=v;if(solve(pos+1))return 1;used[v]=0;}return 0;}
int main(void){int e,u,v;scanf("%d%d",&n,&e);while(e--){scanf("%d%d",&u,&v);g[u][v]=g[v][u]=1;}path[0]=0;used[0]=1;if(solve(1)){puts("Hamiltonian cycle:");for(int i=0;i<n;i++)printf("%d ",path[i]);printf("0\n");}else puts("No Hamiltonian cycle");return 0;}
