#include <stdio.h>
#define N 100
typedef struct{int a[N],top;} Stack;
void init(Stack*s){s->top=-1;} int empty(Stack*s){return s->top<0;}
void push(Stack*s,int x){if(s->top<N-1)s->a[++s->top]=x;}
int pop(Stack*s){return empty(s)?-1:s->a[s->top--];}

/* Method 1: enqueue costly, dequeue O(1) */
typedef struct{Stack s;} Q1;
void q1init(Q1*q){init(&q->s);}
void q1enqueue(Q1*q,int x){Stack t;init(&t);while(!empty(&q->s))push(&t,pop(&q->s));push(&q->s,x);while(!empty(&t))push(&q->s,pop(&t));}
int q1dequeue(Q1*q){return pop(&q->s);}

/* Method 2: enqueue O(1), dequeue costly */
typedef struct{Stack in,out;} Q2;
void q2init(Q2*q){init(&q->in);init(&q->out);}
void q2enqueue(Q2*q,int x){push(&q->in,x);}
int q2dequeue(Q2*q){
    if(empty(&q->out))while(!empty(&q->in))push(&q->out,pop(&q->in));
    return pop(&q->out);
}
int main(void){
    Q1 a;q1init(&a);q1enqueue(&a,1);q1enqueue(&a,2);printf("%d\n",q1dequeue(&a));
    Q2 b;q2init(&b);q2enqueue(&b,1);q2enqueue(&b,2);printf("%d\n",q2dequeue(&b));
    return 0;
}
