#include <stdio.h>
#define N 20
int n,x[N],col[N],d1[2*N],d2[2*N],count;
void solve(int r){if(r==n){count++;for(int i=0;i<n;i++)printf("%d ",x[i]);puts("");return;}
for(int c=0;c<n;c++)if(!col[c]&&!d1[r-c+n]&&!d2[r+c]){x[r]=c;col[c]=d1[r-c+n]=d2[r+c]=1;solve(r+1);col[c]=d1[r-c+n]=d2[r+c]=0;}}
int main(void){scanf("%d",&n);solve(0);printf("Solutions=%d\n",count);return 0;}
