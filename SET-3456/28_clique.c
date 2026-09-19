#include <stdio.h>
#define N 100
int n,m,g[N][N],x[N],found;
void choose(int pos,int cnt){
 if(found)return;if(cnt==m){found=1;return;}if(n-pos<m-cnt)return;
 for(int v=pos;v<n;v++){int ok=1;for(int i=0;i<cnt;i++)if(!g[v][x[i]]){ok=0;break;}if(ok){x[cnt]=v;choose(v+1,cnt+1);}}
}
int main(void){int e,u,v;scanf("%d%d%d",&n,&e,&m);while(e--){scanf("%d%d",&u,&v);g[u][v]=g[v][u]=1;}choose(0,0);puts(found?"Clique exists":"No clique");return 0;}
