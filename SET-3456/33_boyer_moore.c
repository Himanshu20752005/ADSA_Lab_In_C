#include <stdio.h>
#include <string.h>
#define ALPHA 256
void search(char*t,char*p){int n=strlen(t),m=strlen(p),last[ALPHA];for(int i=0;i<ALPHA;i++)last[i]=-1;for(int i=0;i<m;i++)last[(unsigned char)p[i]]=i;
for(int s=0;s<=n-m;){int j=m-1;while(j>=0&&p[j]==t[s+j])j--;if(j<0){printf("%d ",s);s+=(s+m<n)?m-last[(unsigned char)t[s+m]]:1;}else{int sh=j-last[(unsigned char)t[s+j]];s+=sh>1?sh:1;}}}
int main(void){char t[10000],p[1000];scanf("%9999s%999s",t,p);search(t,p);puts("");return 0;}
