#include <stdio.h>
#include <stdlib.h>
#define T 3
typedef struct BNode{int n,leaf,k[2*T-1];struct BNode*c[2*T];}BNode;
BNode*createTree(void){return calloc(1,sizeof(BNode));}
BNode*newNode(int leaf){BNode*x=calloc(1,sizeof(*x));x->leaf=leaf;return x;}
BNode*searchItem(BNode*x,int k){int i=0;while(i<x->n&&k>x->k[i])i++;if(i<x->n&&k==x->k[i])return x;if(x->leaf)return NULL;return searchItem(x->c[i],k);}
void splitChild(BNode*x,int i){
 BNode*y=x->c[i],*z=newNode(y->leaf);z->n=T-1;for(int j=0;j<T-1;j++)z->k[j]=y->k[j+T];
 if(!y->leaf)for(int j=0;j<T;j++)z->c[j]=y->c[j+T];
 y->n=T-1;for(int j=x->n;j>=i+1;j--)x->c[j+1]=x->c[j];x->c[i+1]=z;
 for(int j=x->n-1;j>=i;j--)x->k[j+1]=x->k[j];x->k[i]=y->k[T-1];x->n++;
}
void insertNonFull(BNode*x,int k){int i=x->n-1;if(x->leaf){while(i>=0&&k<x->k[i])x->k[i+1]=x->k[i--];x->k[i+1]=k;x->n++;}
else{while(i>=0&&k<x->k[i])i--;i++;if(x->c[i]->n==2*T-1){splitChild(x,i);if(k>x->k[i])i++;}insertNonFull(x->c[i],k);}}
void insertItem(BNode**root,int k){BNode*r=*root;if(r->n==2*T-1){BNode*s=newNode(0);s->c[0]=r;*root=s;splitChild(s,0);insertNonFull(s,k);}else insertNonFull(r,k);}
void removeFromLeaf(BNode*x,int i){for(int j=i+1;j<x->n;j++)x->k[j-1]=x->k[j];x->n--;}
int pred(BNode*x){while(!x->leaf)x=x->c[x->n];return x->k[x->n-1];}
int succ(BNode*x){while(!x->leaf)x=x->c[0];return x->k[0];}
void merge(BNode*x,int i){BNode*a=x->c[i],*b=x->c[i+1];a->k[T-1]=x->k[i];for(int j=0;j<b->n;j++)a->k[j+T]=b->k[j];if(!a->leaf)for(int j=0;j<=b->n;j++)a->c[j+T]=b->c[j];a->n+=b->n+1;for(int j=i+1;j<x->n;j++)x->k[j-1]=x->k[j];for(int j=i+2;j<=x->n;j++)x->c[j-1]=x->c[j];x->n--;free(b);}
void fill(BNode*x,int i){if(i&&x->c[i-1]->n>=T){BNode*a=x->c[i-1],*b=x->c[i];for(int j=b->n;j>0;j--)b->k[j]=b->k[j-1];if(!b->leaf)for(int j=b->n+1;j>0;j--)b->c[j]=b->c[j-1];b->k[0]=x->k[i-1];if(!b->leaf)b->c[0]=a->c[a->n];x->k[i-1]=a->k[--a->n];}
else if(i<x->n&&x->c[i+1]->n>=T){BNode*a=x->c[i],*b=x->c[i+1];a->k[a->n++]=x->k[i];if(!a->leaf)a->c[a->n]=b->c[0];x->k[i]=b->k[0];for(int j=1;j<b->n;j++)b->k[j-1]=b->k[j];if(!b->leaf)for(int j=1;j<=b->n;j++)b->c[j-1]=b->c[j];b->n--;}
else if(i<x->n)merge(x,i);else merge(x,i-1);}
void del(BNode*x,int k){
 int i=0;while(i<x->n&&k>x->k[i])i++;
 if(i<x->n&&k==x->k[i]){if(x->leaf)removeFromLeaf(x,i);else if(x->c[i]->n>=T){int p=pred(x->c[i]);x->k[i]=p;del(x->c[i],p);}else if(x->c[i+1]->n>=T){int s=succ(x->c[i+1]);x->k[i]=s;del(x->c[i+1],s);}else{merge(x,i);del(x->c[i],k);}}
 else{if(x->leaf)return;int flag=(i==x->n);if(x->c[i]->n<T)fill(x,i);if(flag&&i>x->n)del(x->c[i-1],k);else del(x->c[i],k);}
}
void deleteItem(BNode**root,int k){if(!*root)return;del(*root,k);if((*root)->n==0){BNode*t=*root;if(t->leaf)*root=NULL;else *root=t->c[0];free(t);}}
void print(BNode*x){if(x){int i;for(i=0;i<x->n;i++){if(!x->leaf)print(x->c[i]);printf("%d ",x->k[i]);}if(!x->leaf)print(x->c[i]);}}
void deleteTree(BNode*x){if(x){if(!x->leaf)for(int i=0;i<=x->n;i++)deleteTree(x->c[i]);free(x);}}
int main(void){BNode*r=createTree();int a[]={10,20,5,6,12,30,7,17};for(int i=0;i<8;i++)insertItem(&r,a[i]);deleteItem(&r,6);print(r);deleteTree(r);return 0;}
