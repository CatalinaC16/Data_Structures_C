#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int valoare;
    struct Node * left;
    struct Node * right;
}Node;

Node * create_tree(FILE *f){
    Node *p;
    int val;
    fscanf(f,"%d",&val);
    if(val==0)return NULL;
    else {
        p=(Node*)malloc(sizeof(Node));

       p->valoare=val;
       p->left= create_tree(f);
       p->right=create_tree(f);
    }
    return p;
}
void preorder(Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->valoare);
        preorder(p->left);
        preorder(p->right);
    }
    else return;
}
void postorder(Node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->valoare);

    }
    else return;
}
void inorder(Node *p)
{
    if(p!=NULL)
    {
       inorder(p->left);
        printf("%d ",p->valoare);
        inorder(p->right);


    }
    else return;
}
int leaf_node (Node*p)
{
    if(p==NULL)return 0;
    else if (p->left==NULL && p->right==NULL) return 1+leaf_node(p->left)+ leaf_node(p->right);
    else return leaf_node(p->left)+ leaf_node(p->right);
}

int intern_node (Node*p)
{
    if(p==NULL)return 0;
    else if (p->left!=NULL || p->right!=NULL) return 1+intern_node(p->left)+ intern_node(p->right);
    else return intern_node(p->left)+ intern_node(p->right);
}
Node *search(Node *p,int key){
   if(p) {
       if (p->valoare == key)return p;
       else if (search(p->left, key)) return p;
       else if(search(p->right,key)) return p;
   }
   else return NULL;
}
int maxim( int a,int b)
{ if(a>=b) return a;
    else return b;
}
int height( Node *p)
{
    if(p==NULL)return -1;
    else return 1+maxim(height(p->left),height(p->right));
}

int minim( int a,int b)
{ if(a>=b) return b;
    else return a;
}

int main() {
 Node* root;
 FILE *f =fopen("arbore.txt","r");
 if(f==NULL){
     printf("fisierul nu s-a putut deschide");
     return -1;
 }
 root= create_tree(f);
 preorder(root);
 printf("\n");
    postorder(root);
    printf("\n");
   inorder(root);
    printf("\n");
    printf("nmb of leafs %d\n", leaf_node(root));
    printf("nmb of intern %d\n", intern_node(root));

    printf("%d\n", height(root));
    Node* p= search(root,9);


 fclose(f);

    return 0;
}
