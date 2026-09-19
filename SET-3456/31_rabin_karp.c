#include <stdio.h>
#include <string.h>
#define D 256
#define Q 1000000007LL
void search(char*t,char*p){long long h=1,ht=0,hp=0;int n=strlen(t),m=strlen(p);if(m>n)return;for(int i=0;i<m-1;i++)h=h*D%Q;
for(int i=0;i<m;i++)ht=(D*ht+t[i])%Q,hp=(D*hp+p[i])%Q;
for(int i=0;i<=n-m;i++){if(ht==hp&&!memcmp(t+i,p,m))printf("%d ",i);if(i<n-m){ht=(D*(ht-t[i]*h%Q+Q)+t[i+m])%Q;}}
}
int main(void){char t[10000],p[1000];scanf("%9999s%999s",t,p);search(t,p);puts("");return 0;}
