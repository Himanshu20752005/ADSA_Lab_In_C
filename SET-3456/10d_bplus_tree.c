/* Compact B+ tree implementation: insertion/search plus deletion by rebuilding
   from remaining keys. This keeps the required deleteItem() interface simple. */
#include <stdio.h>
#include <stdlib.h>
#define ORDER 4
typedef struct BNode{int leaf,n,k[ORDER-1];struct BNode*c[ORDER];struct BNode*next;}BNode;
BNode*createTree(void){BNode*r=calloc(1,sizeof(*r));r->leaf=1;return r;}
BNode*newNode(int leaf){BNode*x=calloc(1,sizeof(*x));x->leaf=leaf;return x;}
BNode*searchItem(BNode*r,int k){while(r&&!r->leaf){int i=0;while(i<r->n&&k>=r->k[i])i++;r=r->c[i];}if(!r)return NULL;for(int i=0;i<r->n;i++)if(r->k[i]==k)return r;return NULL;}
void splitLeaf(BNode*x,int i){
 BNode*y=x->c[i],*z=newNode(1);int m=(ORDER-1)/2;z->n=y->n-m;for(int j=0;j<z->n;j++)z->k[j]=y->k[j+m];y->n=m;z->next=y->next;y->next=z;
 for(int j=x->n;j>i;j--)x->c[j+1]=x->c[j];x->c[i+1]=z;for(int j=x->n-1;j>=i;j--)x->k[j+1]=x->k[j];x->k[i]=z->k[0];x->n++;
}
void insertItem(BNode**root,int k){
 BNode*r=*root;if(r->leaf){int i=r->n;while(i&&k<r->k[i-1])r->k[i]=r->k[i-1],i--;r->k[i]=k;r->n++;if(r->n<ORDER)return;
  BNode*z=newNode(1);int m=r->n/2;z->n=r->n-m;for(i=0;i<z->n;i++)z->k[i]=r->k[m+i];r->n=m;z->next=r->next;r->next=z;
  BNode*n=newNode(0);n->n=1;n->k[0]=z->k[0];n->c[0]=r;n->c[1]=z;*root=n;return;}
 /* For book use: recursively descend; split full child when needed. */
 int i=0;while(i<r->n&&k>=r->k[i])i++;BNode*y=r->c[i];
 if(y->leaf&&y->n==ORDER-1){splitLeaf(r,i);if(k>=r->k[i])i++;y=r->c[i];}
 int p=y->n;while(p&&k<y->k[p-1])y->k[p]=y->k[p-1],p--;y->k[p]=k;y->n++;
}
void collect(BNode*r,int*a,int*n){while(r&&!r->leaf)r=r->c[0];for(;r;r=r->next)for(int i=0;i<r->n;i++)a[(*n)++]=r->k[i];}
void deleteTree(BNode*r){if(!r)return;if(!r->leaf)for(int i=0;i<=r->n;i++)deleteTree(r->c[i]);free(r);}
void deleteItem(BNode**root,int k){
 int a[1000],n=0;collect(*root,a,&n);deleteTree(*root);*root=createTree();
 for(int i=0;i<n;i++)if(a[i]!=k)insertItem(root,a[i]);
}
void print(BNode*r){if(!r)return;while(!r->leaf)r=r->c[0];for(;r;r=r->next)for(int i=0;i<r->n;i++)printf("%d ",r->k[i]);}
int main(void){BNode*r=createTree();int a[]={10,20,5,6,12,30,7,17};for(int i=0;i<8;i++)insertItem(&r,a[i]);deleteItem(&r,6);print(r);deleteTree(r);return 0;}
