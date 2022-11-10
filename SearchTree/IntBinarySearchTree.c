#include <stdio.h>
#include "IntBinarySearchTree.h"
#include <stdlib.h>

struct _IntBinarySearchTree {
    int data;
    struct _IntBinarySearchTree *left;
    struct  _IntBinarySearchTree *right;
    unsigned size;
};

IntBinarySearchTree *intBinarySearchTree_new(){
    IntBinarySearchTree *tree = malloc(sizeof(IntBinarySearchTree));
    tree->right = NULL;
    tree->left = NULL;
    tree->size = 0;
    return tree;
}

int intBinarySearchTree_add(IntBinarySearchTree *tree, int value) {

    if (tree == NULL)return 0;
///daca root ul fiecarui arbore este neocupat
    if (tree->size == 0) {
        tree->data = value;
        tree->left = NULL;
        tree->right = NULL;
        tree->size++;
        return 1;
    }

    if (value == tree->data)
        return 0;
///daca merge pe fiu drept
    if (value > tree->data) {
         ///daca e liber il consideram ca un arbore cu 2 fii si punem valoarea in fiu_drept
        if (tree->right == NULL) {

            tree->right = intBinarySearchTree_new();
            tree->right->data = value;
            tree->right->size = 1;
            tree->size++;
            return 1;
           ///trimitem radacina acestui arbore
        } else if (intBinarySearchTree_add(tree->right, value)) {

            tree->size++;
            return 1;
        }
        else return 0;
    }

  if (value < tree->data) {
        if (tree->left == NULL) {

            tree->left = intBinarySearchTree_new();
            tree->left->data = value;
            tree->left->size = 1;
            tree->size++;
            return 1;

        }
        else if (intBinarySearchTree_add(tree->left, value)) {

            tree->size++;
            return 1;
        }
        else return 0;
    }
}


void intBinarySearchTree_preorder(IntBinarySearchTree *tree, void (*func)(int *)) {
    if (tree!= NULL) {
        func(&tree->data);
        intBinarySearchTree_preorder(tree->left, func);
        intBinarySearchTree_preorder(tree->right, func);
    }
}


void intBinarySearchTree_inorder(IntBinarySearchTree *tree, void (*func)(int *)) {
    if (tree!= NULL) {
        intBinarySearchTree_inorder(tree->left, func);
        func(&tree->data);
        intBinarySearchTree_inorder(tree->right, func);
    }
}


void intBinarySearchTree_postorder(IntBinarySearchTree *tree, void (*func)(int *)) {
    if (tree!= NULL) {
        intBinarySearchTree_postorder(tree->left, func);
        intBinarySearchTree_postorder(tree->right, func);
        func(&tree->data);
    }
}
unsigned intBinarySearchTree_size(IntBinarySearchTree *tree){
    return tree->size;
}

unsigned intBinarySearchTree_leafCount(IntBinarySearchTree *tree){
    if (tree == NULL)
        return 0;
    if (tree->left == NULL && tree->right == NULL)
        return 1;
    else
        return intBinarySearchTree_leafCount(tree->left) + intBinarySearchTree_leafCount(tree->right);
}


int intBinarySearchTree_contains(IntBinarySearchTree *tree, int value){
    if(value==tree->data)
        return 1;
    else if(value > tree->data){

        if(tree->right)
            return intBinarySearchTree_contains(tree->right,value);
        else return 0;
    }
    else
    if(value < tree->data) {
        if (tree->left)
            return intBinarySearchTree_contains(tree->left, value);
        else return 0;
    }
}

unsigned intBinarySearchTree_height(IntBinarySearchTree* tree) {

  if(tree==NULL)
      return -1;
  else if (intBinarySearchTree_height(tree->left)>intBinarySearchTree_height(tree->right))
     return 1 + intBinarySearchTree_height(tree->left);
  else
     return 1 + intBinarySearchTree_height(tree->right);

}


void intBinarySearchTree_free(IntBinarySearchTree *tree){

if(tree == NULL) return;
      if(tree->right){
          intBinarySearchTree_free(tree->right);
          free(tree->right);
      }
      if(tree->left){
          intBinarySearchTree_free(tree->left);
          free(tree->left);
      }
}

void intBinarySearchTree_remove(IntBinarySearchTree *tree, int value) {
    IntBinarySearchTree *parinte;
    parinte = tree;
    while (tree->data != value) {
        if (value < tree->data) {
            parinte = tree;
            tree = tree->left;
        } else {
            parinte = tree;
            tree = tree->right;
        }
    }
    if (tree->left == NULL && tree->right == NULL) {
        if (parinte->right == tree)
            parinte->right = NULL;
        else
            parinte->left = NULL;
    }
    else {
        parinte = tree;
        if (tree->right->left == NULL && tree->right != NULL) {
            parinte->data = parinte->right->data;
            tree = tree->right;
            parinte->right = tree->right;
            parinte->size--;
           free(tree);
        } else {
            tree->size--;
            tree = tree->right;
            while (tree->left->left != NULL) {
                tree->size--;
                tree = tree->left;
            }
            parinte->data = tree->left->data;
            tree->left = NULL;
        }
    }

}