#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct { int a[N], front, rear, size; } CQueue;

void init(CQueue *q){ q->front=q->rear=0; q->size=0; }
int isEmpty(CQueue *q){ return q->size==0; }
int isFull(CQueue *q){ return q->size==N; }
void enqueue(CQueue *q,int x){
    if(isFull(q)){ printf("Overflow\n"); return; }
    q->a[q->rear]=x; q->rear=(q->rear+1)%N; q->size++;
}
int dequeue(CQueue *q){
    if(isEmpty(q)){ printf("Underflow\n"); return -1; }
    int x=q->a[q->front]; q->front=(q->front+1)%N; q->size--; return x;
}
void display(CQueue *q){
    for(int i=0,p=q->front;i<q->size;i++,p=(p+1)%N) printf("%d ",q->a[p]);
    puts("");
}

/* Linked-list circular queue */
typedef struct Node { int data; struct Node *next; } Node;
typedef struct { Node *rear; } LQueue;
void linit(LQueue *q){ q->rear=NULL; }
void lenqueue(LQueue *q,int x){
    Node *p=malloc(sizeof(Node)); p->data=x;
    if(!q->rear) p->next=p;
    else { p->next=q->rear->next; q->rear->next=p; }
    q->rear=p;
}
int ldequeue(LQueue *q){
    if(!q->rear){ printf("Underflow\n"); return -1; }
    Node *f=q->rear->next; int x=f->data;
    if(f==q->rear) q->rear=NULL; else q->rear->next=f->next;
    free(f); return x;
}
void ldisplay(LQueue *q){
    if(!q->rear){ puts(""); return; }
    Node *p=q->rear->next;
    do{ printf("%d ",p->data); p=p->next; }while(p!=q->rear->next);
    puts("");
}
int main(void){
    CQueue q; init(&q); enqueue(&q,10); enqueue(&q,20); printf("%d\n",dequeue(&q)); display(&q);
    LQueue l; linit(&l); lenqueue(&l,10); lenqueue(&l,20); printf("%d\n",ldequeue(&l)); ldisplay(&l);
    return 0;
}
