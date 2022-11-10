#include <stdio.h>
#include "IntBinaryTree.h"
#include <stdlib.h>

void printInt(int *elem) {
    printf(" %d ", *elem);
}

int main() {
    IntBinaryTree *tree = intBinaryTree_new();
  // for (int i = 0; i < 7; ++i) {
    //   intBinaryTree_add(tree, i + 1);
  // }
    intBinaryTree_add(tree, 4);
   intBinaryTree_add(tree, 6);
   intBinaryTree_add(tree, 8);
    intBinaryTree_add(tree, 9);
    intBinaryTree_add(tree, 5);
    intBinaryTree_add(tree, 3);
    intBinaryTree_add(tree, 4);
    intBinaryTree_add(tree, 66);
    intBinaryTree_add(tree, 77);


    printf(("preorder is "));
    intBinaryTree_preorder(tree, printInt);
    printf(("\npostorder is "));
    intBinaryTree_postorder(tree, printInt);
    printf((" \ninorder is"));
    intBinaryTree_inorder(tree, printInt);
    printf(("\n"));

    printf("size is %d \n", intBinaryTree_size(tree));
    printf("nr leafs %d \n", intBinaryTree_leafCount(tree));
    printf("height %d \n", intBinaryTree_height(tree));

    printf("contains %d ", intBinaryTree_contains(tree,5));
    printf("contains %d ", intBinaryTree_contains(tree,2));
    printf("contains %d ", intBinaryTree_contains(tree,44));
    printf("contains %d ", intBinaryTree_contains(tree,7));
    printf("contains %d ", intBinaryTree_contains(tree,8));
    printf(("\n"));
    intBinaryTree_free(tree);
    return 0;
}
