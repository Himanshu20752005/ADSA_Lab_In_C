/* Branch-and-bound / A* style 15-puzzle solver using Manhattan distance.
   Input: 16 integers, 0 denotes blank. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define SZ 16
typedef struct{unsigned char a[SZ],z;int g,h,f;char path[64];}State;
int md(unsigned char*a){int s=0;for(int i=0;i<16;i++)if(a[i]){int t=a[i]-1,sx=i/4,sy=i%4,gx=t/4,gy=t%4;s+=abs(sx-gx)+abs(sy-gy);}return s;}
int goal(unsigned char*a){for(int i=0;i<15;i++)if(a[i]!=i+1)return 0;return a[15]==0;}
/* For a book implementation, this bounded best-first search demonstrates the method.
   Increase LIMIT for harder instances. */
int main(void){
 State st={0};for(int i=0;i<16;i++){int x;scanf("%d",&x);st.a[i]=x;if(!x)st.z=i;}
 st.g=0;st.h=md(st.a);st.f=st.h;st.path[0]='\0';
 const int LIMIT=200000;State *q=malloc(LIMIT*sizeof(State));int head=0,tail=1;q[0]=st;
 while(head<tail){int bi=head;for(int i=head+1;i<tail;i++)if(q[i].f<q[bi].f)bi=i;State cur=q[bi];q[bi]=q[head++];q[bi]=cur;
  if(goal(cur.a)){printf("Moves: %s\n",cur.path);free(q);return 0;}
  int z=cur.z,r=z/4,c=z%4,dr[]={-1,1,0,0},dc[]={0,0,-1,1};char mv[]={'U','D','L','R'};
  for(int k=0;k<4;k++){int nr=r+dr[k],nc=c+dc[k];if(nr<0||nr>=4||nc<0||nc>=4)continue;int nz=nr*4+nc;
   State nx=cur;unsigned char t=nx.a[z];nx.a[z]=nx.a[nz];nx.a[nz]=t;nx.z=nz;nx.g++;
   nx.h=md(nx.a);nx.f=nx.g+nx.h;int L=strlen(cur.path);if(L<63){memcpy(nx.path,cur.path,L);nx.path[L]=mv[k];nx.path[L+1]='\0';}
   if(tail<LIMIT)q[tail++]=nx;
  }
 }
 puts("No solution found within search limit.");free(q);return 0;
}
