#include"IntBinaryTree.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    unsigned size;
    struct Node *left;
    struct Node *right;
}Node;

struct _IntBinaryTree {
    Node *root;
    unsigned size;
};

IntBinaryTree* intBinaryTree_new() {
    IntBinaryTree *tree = malloc(sizeof(IntBinaryTree));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

static Node* node_init(int value) {
    Node* node = malloc(sizeof(value));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->size = 1;
    return node;
}

static void intBinary_add_helper(Node *current, int value) {
    if (current->left == NULL) {
        current->left = node_init(value);

    } else if (current->right == NULL) {
        current->right = node_init(value);

    } else if (current->right->size < current->left->size)
        intBinary_add_helper(current->right, value);
    else
        intBinary_add_helper(current->left, value);

    current->size++;
}

void intBinaryTree_add(IntBinaryTree *tree, int value) {
    if (tree->root == NULL)
        tree->root = node_init(value);
    else
        intBinary_add_helper(tree->root, value);

    tree->size++;
}

static void intBinaryTree_preorder_helper(Node *current, void (*func)(int *)) {
    if (current != NULL) {
        func(&current->data);
        intBinaryTree_preorder_helper(current->left, func);
        intBinaryTree_preorder_helper(current->right, func);
    }
}

void intBinaryTree_preorder(IntBinaryTree *tree, void (*func)(int *)) {
    intBinaryTree_preorder_helper(tree->root, func);
}

static void intBinaryTree_postorder_helper(Node *current, void (*func)(int *)) {
    if (current != NULL) {
        intBinaryTree_postorder_helper(current->left, func);
        intBinaryTree_postorder_helper(current->right, func);
        func(&current->data);
    }

}

void intBinaryTree_postorder(IntBinaryTree *tree, void (*func)(int *)) {
    intBinaryTree_postorder_helper(tree->root, func);

}

static void intBinaryTree_inorder_helper(Node *current, void (*func)(int *)) {
    if (current != NULL) {
        intBinaryTree_inorder_helper(current->left, func);
        func(&current->data);
        intBinaryTree_inorder_helper(current->right, func);
    }
}

void intBinaryTree_inorder(IntBinaryTree *tree, void (*func)(int *)) {
    intBinaryTree_inorder_helper(tree->root, func);
}

unsigned intBinaryTree_size(IntBinaryTree *tree) {
    return tree->size;
}

static unsigned count_leaf(Node *current) {
    if (current == NULL)
        return 0;
    if (current->left == NULL && current->right == NULL)
        return 1;
    else
        return count_leaf(current->left) + count_leaf(current->right);
}

unsigned intBinaryTree_leafCount(IntBinaryTree *tree) {
    return count_leaf(tree->root);

}
/*
static unsigned height_helper_left(Node *node) {
    if (node == NULL)
        return 0;
    if (node->left)
        return 1 + height_helper_left(node->left);
    else if (node->right)
        return 1 + height_helper_left(node->right);
}

static unsigned height_helper_right(Node *node) {
    if (node == NULL)
        return 0;
    if (node->right)
        return 1 + height_helper_right(node->right);
    else if (node->left)
        return 1 + height_helper_right(node->left);
}

unsigned intBinaryTree_height(IntBinaryTree *tree) {

    int nrl = height_helper_left(tree->root);
    int nrr = height_helper_right(tree->root);
    if (nrl > nrr)
        return nrl;
    else
        return nrr;

}*/
static height_helper(Node* node)
{
    if(node ==NULL)
        return -1;
    else if(height_helper(node->left)>height_helper(node->right))
        return 1+height_helper(node->left);
    else
        return 1+ height_helper(node->right);
}
unsigned intBinaryTree_height(IntBinaryTree *tree) {

 return height_helper(tree->root);

}
int contains_helper(Node* node, int value) {
   if(node)
   {
       if(node->data == value)
           return 1;
       else
           if(contains_helper(node->left,value))
               return 1;
           else if (contains_helper(node->right,value))
               return 1;

   }
   else return 0;
}

int intBinaryTree_contains(IntBinaryTree *tree, int value) {

    return contains_helper(tree->root,value);
}

void free_helper(Node *node) {
    if (node == NULL)
        return;
    free_helper(node->right);
    free_helper(node->left);
    free(node);

}

void intBinaryTree_free(IntBinaryTree *tree) {
    free_helper(tree->root);
    free(tree);
}
