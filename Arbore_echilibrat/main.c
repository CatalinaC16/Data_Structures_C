#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int valoare;
    struct Node * left;
    struct Node *right;
}Node;
Node * createTree(int nr_nodes, FILE * f)
{
  Node *p;
    int nleft,nright;
    if(nr_nodes<=0) return NULL;
    else{
       nleft=nr_nodes/2;
       nright=nr_nodes-nleft-1;
       p= (Node*) malloc(sizeof (Node));
        fscanf( f,"%d", &(p->valoare));
        p->left =createTree( nleft,f );
        p->right =createTree( nright,f );
    }
    return p;
}
void preorder(Node* a)
{
    if(a==NULL)return;
    else{
        printf("%d",a->valoare);
        preorder(a->left);
        preorder(a->right);
    }
}
void inorder(Node* p)
{
    if(p==NULL)return;
    else{

        inorder(p->left);
        printf("%d",p->valoare);
        inorder(p->right);
    }
}
int main() {
    Node*root=NULL;
   FILE * f = fopen( "arbore_echilibrat","r");
   if(!f) printf("nu s-a deschis");
   int n;
   fscanf(f,"%d",&n);
    root= createTree(n,f);
   preorder(root); printf("\n");
   inorder(root);
    return 0;
}
