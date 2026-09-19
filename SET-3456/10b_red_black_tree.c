#include <stdio.h>
#include <stdlib.h>
typedef enum{RED,BLACK}Color;
typedef struct Node{int key;Color c;struct Node*l,*r,*p;}Node;
typedef struct{Node*root,*nil;}RBTree;
RBTree*createTree(void){
    RBTree*T=malloc(sizeof(*T));T->nil=malloc(sizeof(Node));T->nil->c=BLACK;T->nil->l=T->nil->r=T->nil->p=NULL;T->root=T->nil;return T;
}
void leftRotate(RBTree*T,Node*x){Node*y=x->r;x->r=y->l;if(y->l!=T->nil)y->l->p=x;y->p=x->p;
if(x->p==T->nil)T->root=y;else if(x==x->p->l)x->p->l=y;else x->p->r=y;y->l=x;x->p=y;}
void rightRotate(RBTree*T,Node*y){Node*x=y->l;y->l=x->r;if(x->r!=T->nil)x->r->p=y;x->p=y->p;
if(y->p==T->nil)T->root=x;else if(y==y->p->r)y->p->r=x;else y->p->l=x;x->r=y;y->p=x;}
void insertFix(RBTree*T,Node*z){while(z->p->c==RED){if(z->p==z->p->p->l){Node*y=z->p->p->r;if(y->c==RED){z->p->c=y->c=BLACK;z->p->p->c=RED;z=z->p->p;}else{if(z==z->p->r){z=z->p;leftRotate(T,z);}z->p->c=BLACK;z->p->p->c=RED;rightRotate(T,z->p->p);}}
else{Node*y=z->p->p->l;if(y->c==RED){z->p->c=y->c=BLACK;z->p->p->c=RED;z=z->p->p;}else{if(z==z->p->l){z=z->p;rightRotate(T,z);}z->p->c=BLACK;z->p->p->c=RED;leftRotate(T,z->p->p);}}}T->root->c=BLACK;}
void insertItem(RBTree*T,int k){Node*z=malloc(sizeof(*z));z->key=k;z->c=RED;z->l=z->r=T->nil;Node*y=T->nil,*x=T->root;while(x!=T->nil){y=x;x=k<x->key?x->l:x->r;}z->p=y;if(y==T->nil)T->root=z;else if(k<y->key)y->l=z;else y->r=z;insertFix(T,z);}
Node*searchItem(RBTree*T,int k){Node*x=T->root;while(x!=T->nil&&x->key!=k)x=k<x->key?x->l:x->r;return x;}
Node*minimum(RBTree*T,Node*x){while(x->l!=T->nil)x=x->l;return x;}
void transplant(RBTree*T,Node*u,Node*v){if(u->p==T->nil)T->root=v;else if(u==u->p->l)u->p->l=v;else u->p->r=v;v->p=u->p;}
void deleteFix(RBTree*T,Node*x){while(x!=T->root&&x->c==BLACK){if(x==x->p->l){Node*w=x->p->r;if(w->c==RED){w->c=BLACK;x->p->c=RED;leftRotate(T,x->p);w=x->p->r;}if(w->l->c==BLACK&&w->r->c==BLACK){w->c=RED;x=x->p;}else{if(w->r->c==BLACK){w->l->c=BLACK;w->c=RED;rightRotate(T,w);w=x->p->r;}w->c=x->p->c;x->p->c=BLACK;w->r->c=BLACK;leftRotate(T,x->p);x=T->root;}}
else{Node*w=x->p->l;if(w->c==RED){w->c=BLACK;x->p->c=RED;rightRotate(T,x->p);w=x->p->l;}if(w->r->c==BLACK&&w->l->c==BLACK){w->c=RED;x=x->p;}else{if(w->l->c==BLACK){w->r->c=BLACK;w->c=RED;leftRotate(T,w);w=x->p->l;}w->c=x->p->c;x->p->c=BLACK;w->l->c=BLACK;rightRotate(T,x->p);x=T->root;}}}x->c=BLACK;}
void deleteItem(RBTree*T,int k){Node*z=searchItem(T,k);if(z==T->nil)return;Node*y=z,*x;Color oc=y->c;
if(z->l==T->nil){x=z->r;transplant(T,z,z->r);}else if(z->r==T->nil){x=z->l;transplant(T,z,z->l);}else{y=minimum(T,z->r);oc=y->c;x=y->r;if(y->p==z)x->p=y->p;else{transplant(T,y,y->r);y->r=z->r;y->r->p=y;}transplant(T,z,y);y->l=z->l;y->l->p=y;y->c=z->c;}free(z);if(oc==BLACK)deleteFix(T,x);}
void inorder(RBTree*T,Node*x){if(x!=T->nil){inorder(T,x->l);printf("%d ",x->key);inorder(T,x->r);}}
void deleteTree(RBTree*T,Node*x){if(x!=T->nil){deleteTree(T,x->l);deleteTree(T,x->r);free(x);}}
int main(void){RBTree*T=createTree();int a[]={30,20,40,10,25,50};for(int i=0;i<6;i++)insertItem(T,a[i]);deleteItem(T,20);inorder(T,T->root);deleteTree(T,T->root);free(T->nil);free(T);return 0;}
