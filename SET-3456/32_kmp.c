#include <stdio.h>
#include <string.h>
void lps(char*p,int m,int*a){a[0]=0;for(int i=1,len=0;i<m;){if(p[i]==p[len])a[i++]=++len;else if(len)len=a[len-1];else a[i++]=0;}}
int main(void){char t[10000],p[1000];scanf("%9999s%999s",t,p);int n=strlen(t),m=strlen(p),a[1000];lps(p,m,a);for(int i=0,j=0;i<n;){if(t[i]==p[j]){i++;j++;if(j==m)printf("%d ",i-m),j=a[j-1];}else if(j)j=a[j-1];else i++;}puts("");return 0;}
