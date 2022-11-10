#pragma once

/**
 * Structure for storing a binary tree.
 */
typedef struct _IntBinaryTree IntBinaryTree;

/**
 * Creates an empty binary tree, with no elements.
 * @return Reference to a tree
 */
IntBinaryTree *intBinaryTree_new();

/**
 * Frees all the memory used by the tree.
 * @param tree Reference to a binary tree.
 */
void intBinaryTree_free(IntBinaryTree *tree);

/**
 * Inserts a value into a balanced binary tree as a leaf.
 * @param tree Reference to a binary tree.
 * @param value Value to be added.
 */
void intBinaryTree_add(IntBinaryTree *tree, int value);

/**
 * Iterates through elements of the tree in preorder. (Root-L-R)
 * @param tree Reference to a binary tree.
 * @param func Reference to a function to be applied on each element.
 */
void intBinaryTree_preorder(IntBinaryTree *tree, void (*func)(int *));

/**
 * Iterates through elements of the tree in inorder. (L-Root-R)
 * @param tree Reference to a binary tree.
 * @param func Reference to a function to be applied on each element.
 */
void intBinaryTree_inorder(IntBinaryTree *tree, void (*func)(int *));

/**
 * Iterates through elements of the tree in postorder. (L-R-Root)
 * @param tree Reference to a binary tree.
 * @param func Reference to a function to be applied on each element.
 */
void intBinaryTree_postorder(IntBinaryTree *tree, void (*func)(int *));

/**
 * Returns the number of elements inside the tree.
 * @param tree Reference to a binary tree.
 * @return The number of elements inside the tree.
 */
unsigned intBinaryTree_size(IntBinaryTree *tree);

/**
 * Returns the number of leaf elements inside the tree.
 * @param tree Reference to a binary tree.
 * @return The number of leaf elements inside the tree.
 */
unsigned intBinaryTree_leafCount(IntBinaryTree *tree);

/**
 * Returns the height of the tree.
 * @param tree Reference to a binary tree.
 * @return The height of the tree.
 */
unsigned intBinaryTree_height(IntBinaryTree *tree);

/**
 * Checks if the tree contains the specified element.
 * @param tree Reference to a binary tree.
 * @param value The value to be searched.
 * @return 1 if the tree contains the value, 0 otherwise.
 */
int intBinaryTree_contains(IntBinaryTree *tree, int value);

