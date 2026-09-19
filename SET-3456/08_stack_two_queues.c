#include <stdio.h>
#define N 100
typedef struct{int a[N],f,r,n;} Queue;
void qi(Queue*q){q->f=q->r=q->n=0;} int qe(Queue*q){return q->n==0;}
void en(Queue*q,int x){q->a[q->r++]=x;q->n++;}
int de(Queue*q){int x=q->a[q->f++];q->n--;return x;}
/* Method 1: push costly, pop O(1) */
typedef struct{Queue q1,q2;} S1;
void s1i(S1*s){qi(&s->q1);qi(&s->q2);}
void s1push(S1*s,int x){while(!qe(&s->q1))en(&s->q2,de(&s->q1));en(&s->q1,x);while(!qe(&s->q2))en(&s->q1,de(&s->q2));}
int s1pop(S1*s){return qe(&s->q1)?-1:de(&s->q1);}
/* Method 2: push O(1), pop costly */
typedef struct{Queue q1,q2;} S2;
void s2i(S2*s){qi(&s->q1);qi(&s->q2);}
void s2push(S2*s,int x){en(&s->q1,x);}
int s2pop(S2*s){
    if(qe(&s->q1))return -1;
    while(s->q1.n>1)en(&s->q2,de(&s->q1));
    int x=de(&s->q1); Queue t=s->q1;s->q1=s->q2;s->q2=t;qi(&s->q2); return x;
}
int main(void){S1 a;s1i(&a);s1push(&a,1);s1push(&a,2);printf("%d\n",s1pop(&a));
S2 b;s2i(&b);s2push(&b,1);s2push(&b,2);printf("%d\n",s2pop(&b));return 0;}
