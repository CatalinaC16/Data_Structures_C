#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;

} Node;

struct _IntLinkedList {
    Node *first;
    Node *last;
};

IntLinkedList *intLinkedList_new() {
///var de tipul structurii
    IntLinkedList *list = (IntLinkedList *) calloc(1, sizeof(IntLinkedList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

void intLinkedList_insertLast(IntLinkedList *list, int value) {

    if (list == NULL) return;

    Node *p = (Node *) malloc( sizeof(Node));
    p->data = value;
    p->next = NULL;
///lista goala
    if (list->last == NULL ){
        list->first = p;
        list->last = p;
        list->last->next = NULL;
    }
    else
    {
        list->last->next = p;
        list->last=p;
        list->last->next=NULL;

    }

}

void intLinkedList_insertFirst(IntLinkedList *list, int value) {
    Node *p = (Node *) calloc(1, sizeof(Node));
    p->data = value;
    p->next = NULL;

    if (list->last == NULL) {
        list->first = p;
        list->last = p;
        list->last->next = NULL;
    }
    else {
        p->next = list->first;
        list->first = p;

    }
}

void intLinkedList_print(IntLinkedList *list) {

    if (list) {
        Node *current = (Node *) calloc(1, sizeof(Node));
        printf("[");
        current = list->first;

        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("]");
    }
}

void intLinkedList_insertAfter(IntLinkedList *list, int afterValue, int value) {

    Node *p = (Node *) calloc(1, sizeof(Node));
    p->data = value;
    p->next = NULL;

    Node *current ;
    current = list->first;


    if (list->last == NULL) {
        list->first = p;
        list->last = p;
        list->last->next = NULL;
    }
    else {
        while (current) {
            if (current->data == afterValue) {

                p->next = current->next;
                current->next = p;
            }
            current = current->next;
        }

    }
}

int intLinkedList_search(IntLinkedList *list, int value) {
     Node *current ;
    current = list->first;
    while (current) {
        if (current->data == value) return 1;
        current = current->next;
    }
    return 0;
}

void intLinkedList_deleteFirst(IntLinkedList *list) {
    Node *n;
    n = list->first;
    if (list->first == NULL) return;
    else {
        list->first = n->next;
        free(n);
    }
}

void intLinkedList_deleteValue(IntLinkedList *list, int value) {
    Node *current;
    Node *urm ;
    Node *prev ;
    Node *ultim ;
    current = list->first;
    prev = list->first;
    urm = NULL;
    if (list->first->data == value){
       list->first = list->first->next;
        free(current);
        return;
    }

    while (current) {

        urm = current->next;

        if (current->data == value) {
            prev->next = urm;
        }
        ultim=prev;
        prev = current;
        current = urm;

    }

        free(current);
        free(prev);
        free(urm);

    }

void intLinkedList_free(IntLinkedList *list) {
    Node *current ;
    Node *urm ;
    current = list->first;
    urm = NULL;

    while (current) {
        urm = current->next;
        free(current);
        current = urm;
    }
   free(list);
}