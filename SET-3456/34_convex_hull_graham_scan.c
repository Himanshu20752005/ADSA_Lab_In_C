#include <stdio.h>
#include <stdlib.h>
typedef struct{long long x,y;}Point;
Point p0;
long long cross(Point a,Point b,Point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
int cmp(const void*A,const void*B){Point*a=(Point*)A,*b=(Point*)B;long long c=cross(p0,*a,*b);if(c)return c>0?-1:1;long long da=(a->x-p0.x)*(a->x-p0.x)+(a->y-p0.y)*(a->y-p0.y),db=(b->x-p0.x)*(b->x-p0.x)+(b->y-p0.y)*(b->y-p0.y);return da>db?1:-1;}
int main(void){int n;scanf("%d",&n);Point*p=malloc(n*sizeof(*p));for(int i=0;i<n;i++)scanf("%lld%lld",&p[i].x,&p[i].y);
int k=0;for(int i=1;i<n;i++)if(p[i].y<p[k].y||(p[i].y==p[k].y&&p[i].x<p[k].x))k++;Point t=p[0];p[0]=p[k];p[k]=t;p0=p[0];qsort(p+1,n-1,sizeof(Point),cmp);
Point *st=malloc(n*sizeof(*st));int top=0;for(int i=0;i<n;i++){while(top>=2&&cross(st[top-2],st[top-1],p[i])<=0)top--;st[top++]=p[i];}
for(int i=0;i<top;i++)printf("(%lld,%lld) ",st[i].x,st[i].y);puts("");free(st);free(p);return 0;}
