#include <stdio.h>
#include <stdlib.h>
typedef struct Node{int key,h;struct Node*l,*r;}Node;
int H(Node*n){return n?n->h:0;} int mx(int a,int b){return a>b?a:b;}
Node* createTree(void){return NULL;}
Node* newNode(int x){Node*n=malloc(sizeof(Node));n->key=x;n->h=1;n->l=n->r=NULL;return n;}
Node* rotR(Node*y){Node*x=y->l,*t=x->r;x->r=y;y->l=t;y->h=mx(H(y->l),H(y->r))+1;x->h=mx(H(x->l),H(x->r))+1;return x;}
Node* rotL(Node*x){Node*y=x->r,*t=y->l;y->l=x;x->r=t;x->h=mx(H(x->l),H(x->r))+1;y->h=mx(H(y->l),H(y->r))+1;return y;}
int bal(Node*n){return n?H(n->l)-H(n->r):0;}
Node* insertItem(Node*n,int x){
    if(!n)return newNode(x); if(x<n->key)n->l=insertItem(n->l,x);else if(x>n->key)n->r=insertItem(n->r,x);else return n;
    n->h=mx(H(n->l),H(n->r))+1; int b=bal(n);
    if(b>1&&x<n->l->key)return rotR(n); if(b<-1&&x>n->r->key)return rotL(n);
    if(b>1&&x>n->l->key){n->l=rotL(n->l);return rotR(n);}
    if(b<-1&&x<n->r->key){n->r=rotR(n->r);return rotL(n);} return n;
}
Node* minNode(Node*n){while(n->l)n=n->l;return n;}
Node* deleteItem(Node*r,int x){
    if(!r)return r;if(x<r->key)r->l=deleteItem(r->l,x);else if(x>r->key)r->r=deleteItem(r->r,x);
    else{if(!r->l||!r->r){Node*t=r->l?r->l:r->r;if(!t){free(r);return NULL;}*r=*t;free(t);}else{Node*t=minNode(r->r);r->key=t->key;r->r=deleteItem(r->r,t->key);}}
    r->h=mx(H(r->l),H(r->r))+1;int b=bal(r);
    if(b>1&&bal(r->l)>=0)return rotR(r);if(b>1){r->l=rotL(r->l);return rotR(r);}
    if(b<-1&&bal(r->r)<=0)return rotL(r);if(b<-1){r->r=rotR(r->r);return rotL(r);}return r;
}
Node* searchItem(Node*r,int x){while(r&&r->key!=x)r=x<r->key?r->l:r->r;return r;}
void deleteTree(Node*r){if(r){deleteTree(r->l);deleteTree(r->r);free(r);}}
void inorder(Node*r){if(r){inorder(r->l);printf("%d ",r->key);inorder(r->r);}}
int main(void){Node*r=createTree();int a[]={30,20,40,10,25,50};for(int i=0;i<6;i++)r=insertItem(r,a[i]);r=deleteItem(r,20);inorder(r);deleteTree(r);return 0;}
