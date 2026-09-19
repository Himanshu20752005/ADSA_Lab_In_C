#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INF 1000000000
/* Held-Karp DP: O(n^2 2^n). Practical only for roughly <=20 vertices.
   For n=10,20,40,60,100 use a nearest-neighbor benchmark separately,
   because exact TSP becomes infeasible. */
int main(void){
 int n;scanf("%d",&n);if(n>20){puts("Exact Held-Karp is not practical for n>20.");return 0;}
 int N=1<<n;int **w=malloc(n*sizeof(*w));for(int i=0;i<n;i++)w[i]=malloc(n*sizeof(int));for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&w[i][j]);
 int *dp=malloc((size_t)N*n*sizeof(int));for(long long i=0;i<(long long)N*n;i++)dp[i]=INF;dp[1*n+0]=0;
 for(int mask=1;mask<N;mask++)for(int u=0;u<n;u++)if((mask>>u)&1&&dp[mask*n+u]<INF)for(int v=0;v<n;v++)if(!(mask>>v&1)){int nm=mask|1<<v;int z=dp[mask*n+u]+w[u][v];if(z<dp[nm*n+v])dp[nm*n+v]=z;}
 int ans=INF,full=N-1;for(int u=1;u<n;u++)if(dp[full*n+u]+w[u][0]<ans)ans=dp[full*n+u]+w[u][0];printf("TSP=%d\n",ans);
 free(dp);for(int i=0;i<n;i++)free(w[i]);free(w);return 0;
}
