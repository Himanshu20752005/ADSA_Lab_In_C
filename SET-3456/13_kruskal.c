#include <stdio.h>
#include <stdlib.h>
typedef struct{int u,v,w;}Edge;
int cmp(const void*a,const void*b){return ((Edge*)a)->w-((Edge*)b)->w;}
int find(int*p,int x){return p[x]==x?x:(p[x]=find(p,p[x]));}
int main(void){
 int n,m;scanf("%d%d",&n,&m);Edge*e=malloc(m*sizeof(*e));for(int i=0;i<m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
 qsort(e,m,sizeof(*e),cmp);int*p=malloc(n*sizeof(int));for(int i=0;i<n;i++)p[i]=i;int total=0,c=0;
 for(int i=0;i<m&&c<n-1;i++){int a=find(p,e[i].u),b=find(p,e[i].v);if(a!=b){p[a]=b;printf("%d-%d %d\n",e[i].u,e[i].v,e[i].w);total+=e[i].w;c++;}}
 printf("MST=%d\n",total);free(p);free(e);return 0;
}
