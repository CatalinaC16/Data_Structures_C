#include "intStack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;

} Node;

struct _IntStack {
    Node *top;
};

IntStack *intStack_new() {

    IntStack *stack = (IntStack *) calloc(1, sizeof(IntStack));
    stack->top = NULL;
    return stack;
}

void intStack_free(IntStack *stack) {
    Node *current;
    Node *urm;
    current = stack->top;
    urm = NULL;

    while (current) {
        urm = current->next;
        free(current);
        current = urm;
    }
  free(stack);

}

int intStack_size(IntStack *stack) {

    Node *current = (Node *) calloc(1, sizeof(Node));
    current = stack->top;
    int nr = 0;
    if (stack == NULL)return 0;
    while (current) {

        nr++;
        current = current->next;
    }
    return nr;
}

void intStack_push(IntStack *stack, int value) {
    Node *p = (Node *) calloc(1, sizeof(Node));
    p->data = value;
    p->next = NULL;
    if (stack->top == NULL) {
        stack->top = p;
        p->next = NULL;
    } else {
        p->next = stack->top;
        stack->top = p;

    }
}

void print_stack(IntStack *stack) {
    if (stack) {
        Node *current ;
        printf("[");
        current = stack->top;

          while (current) {
              printf("%d ", current->data);
              current = current->next;
          }

        printf("]");
        printf("\n");
    }
    else printf("stiva nu exista!");
}

void intStack_pop(IntStack *stack) {
    if (stack == NULL) printf("%d", 0);
    Node *p;
    p = stack->top;
    stack->top = stack->top->next;
    free(p);
}

int *intStack_peek(IntStack *stack) {

    if (stack == NULL && stack->top == NULL) return NULL;
    return &stack->top->data;

}

void intStack_clear(IntStack *stack) {
    Node *current;
    Node *urm;
    current = stack->top;
    urm = NULL;

    while (current) {
        urm = current->next;
        free(current);
        current = urm;
    }
    stack->top=NULL;

}

int intStack_contains(IntStack *stack, int value) {
    Node *current ;
    current = stack->top;
    while (current) {
        if (current->data == value) return 1;
        current = current->next;
    }
    return 0;
}

void intStack_forEach(IntStack *stack, void (*func)(int *)) {
    Node *current;
    current = stack->top;
    while (current) {
        func(&current->data);
        current = current->next;
    }
}