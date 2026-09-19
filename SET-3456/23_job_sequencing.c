#include <stdio.h>
#include <stdlib.h>
typedef struct{char id;int d,p;}Job;
int cmp(const void*a,const void*b){return ((Job*)b)->p-((Job*)a)->p;}
int main(void){int n;scanf("%d",&n);Job a[100];int md=0;for(int i=0;i<n;i++){scanf(" %c%d%d",&a[i].id,&a[i].d,&a[i].p);if(a[i].d>md)md=a[i].d;}qsort(a,n,sizeof(Job),cmp);
char slot[101]={0};int profit=0;for(int i=0;i<n;i++)for(int t=a[i].d;t>=1;t--)if(!slot[t]){slot[t]=a[i].id;profit+=a[i].p;break;}
for(int i=1;i<=md;i++)if(slot[i])printf("%c ",slot[i]);printf("\nProfit=%d\n",profit);return 0;}
