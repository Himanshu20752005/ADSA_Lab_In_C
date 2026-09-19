#include <stdio.h>
#include <stdlib.h>
typedef struct Node{int key;struct Node*l,*r;}Node;
Node* nn(int x){Node*p=malloc(sizeof(Node));p->key=x;p->l=p->r=NULL;return p;}
void preorder(Node*root){
    if(!root)return;
    Node* st[1000]; int top=0; st[top++]=root;
    while(top){
        Node*p=st[--top]; printf("%d ",p->key);
        if(p->r)st[top++]=p->r;
        if(p->l)st[top++]=p->l;
    }
}
int main(void){Node*r=nn(1);r->l=nn(2);r->r=nn(3);preorder(r);return 0;}
