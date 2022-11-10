#include <stdio.h>
#include "IntBinarySearchTree.h"
void printInt(int *elem) {
    printf(" %d ", *elem);
}
int main() {

    IntBinarySearchTree  * tree= intBinarySearchTree_new();

    printf("%d ",intBinarySearchTree_add(tree,15));
    printf("%d ",intBinarySearchTree_add(tree,6));
    printf("%d ",intBinarySearchTree_add(tree,18));
    printf("%d ",intBinarySearchTree_add(tree,20));
    printf("%d ",intBinarySearchTree_add(tree,17));
    printf("%d ",intBinarySearchTree_add(tree,7));
    printf("%d ",intBinarySearchTree_add(tree,13));
    printf("%d ",intBinarySearchTree_add(tree,3));
    printf("%d ",intBinarySearchTree_add(tree,2));
    printf("%d ",intBinarySearchTree_add(tree,4));
    printf("%d ",intBinarySearchTree_add(tree,9));
    //printf("%f ",intBinarySearchTree_add(tree,17.5));
    printf("\npreorder is: ");
    intBinarySearchTree_preorder(tree,printInt);
    printf("\ninorder is: ");
    intBinarySearchTree_inorder(tree,printInt);
    printf("\npostorder is: ");
    intBinarySearchTree_postorder(tree,printInt);
    printf("\nsize is: %d", intBinarySearchTree_size(tree));
    printf("\nnr of leafs is: %d", intBinarySearchTree_leafCount(tree));
    printf("\n%d", intBinarySearchTree_contains(tree,9));
    printf("\n%d", intBinarySearchTree_contains(tree,3));
    printf("\n%d", intBinarySearchTree_contains(tree,88));
    printf("\n%d", intBinarySearchTree_contains(tree,0));
    printf("\n%d", intBinarySearchTree_contains(tree,2));
    printf("\n%d\n", intBinarySearchTree_height(tree));

    intBinarySearchTree_remove(tree,2);
    intBinarySearchTree_preorder(tree,printInt);
    intBinarySearchTree_free(tree);

    return 0;
}
