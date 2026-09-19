#include <stdio.h>
int n,W,w[100],v[100],best;
void bt(int i,int wt,int val){if(i==n){if(val>best)best=val;return;}bt(i+1,wt,val);if(wt+w[i]<=W)bt(i+1,wt+w[i],val+v[i]);}
int main(void){scanf("%d%d",&n,&W);for(int i=0;i<n;i++)scanf("%d%d",&w[i],&v[i]);bt(0,0,0);printf("Maximum value=%d\n",best);return 0;}
