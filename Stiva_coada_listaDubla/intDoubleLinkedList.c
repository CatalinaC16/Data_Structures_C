#include "intDoubleLinkedList.h."
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

struct _IntLinkedList {
    Node *first;
    Node *last;
};

IntLinkedList *intLinkedList_new() {
    IntLinkedList *list = (IntLinkedList *) calloc(1, sizeof(IntLinkedList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

void print_list(IntLinkedList *list) {
    Node *current;
    if (list) {
        printf("[");
        current = list->first;

        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("]\n");
    }
    else printf("lista nu exista!");
}

void intLinkedList_free(IntLinkedList *list) {
    Node *current ;
    Node *urm ;
    current = list->first;

    while (current) {
        urm = current->next;
        free(current);
        current = urm;
    }
    free(list);
}

int intLinkedList_size(IntLinkedList *list) {
    if (list == NULL)return 0;
    Node *current ;
    int nr = 0;
    current = list->first;
    while (current) {
        nr++;
        current = current->next;

    }
    return nr;
}

int *intLinkedList_front(IntLinkedList *list) {
    if (list->last == NULL) return NULL;
    else return &list->first->data;
}

int *intLinkedList_back(IntLinkedList *list) {
    if (list->last == NULL)return NULL;
    else return &list->last->data;
}

void intLinkedList_push_front(IntLinkedList *list, int value) {
    Node *n = (Node *) calloc(1, sizeof(n));
    n->data = value;
    n->prev = NULL;
    n->next = NULL;

    if (list->last == NULL) {

        list->first = n;
        list->last = n;
        list->last->next = NULL;
        list->first->prev=NULL;

    } else {
        n->next = list->first;
        list->first->prev = n;
        list->first = n;
        list->first->prev= NULL;
    }
}

void intLinkedList_pop_front(IntLinkedList *list) {
    Node *n ;
    if (list) {
        if (list->last != NULL) {

            n = list->first->next;
            n->prev = NULL;
            free(list->first);
            list->first = n;
        }
    }
}

void intLinkedList_push_back(IntLinkedList *list, int value) {
    Node *n = (Node *) calloc(1, sizeof(n));
    n->data = value;
    n->next = NULL;
    n->prev = NULL;
    if (list->last == NULL) {
        list->first = n;
        list->last = n;
        list->last->next=NULL;
        list->first->prev=NULL;
    } else {
        list->last->next = n;
        n->prev = list->last;
        list->last = n;
        list->last->next=NULL;

    }

}

void intLinkedList_pop_back(IntLinkedList *list) {
    Node *n ;
    if (list) {
        if (list->last != NULL) {

            n = list->last->prev;
            n->next = NULL;
            free(list->last);
            list->last = n;

        }
    }
}

void intLinkedList_clear(IntLinkedList *list) {
    Node *current ;
    Node *urm ;
    current = list->first;
    urm=NULL;

    while (current) {
        urm = current->next;
        free(current);
        current = urm;
    }
    list->first=NULL;
    list->last=NULL;

}

void intLinkedList_remove(IntLinkedList *list, int value) {
    Node *current,*urm,*ante;
    Node *n;
    Node *m ;
    if (list) {
        if(list->first->data == value){
           n=list->first;
           list->first = list->first->next;
           list->first->prev = NULL;
           free(n);
            return;
        }
        if(list->last->data == value) {
            n=list->last;
            list->last =list->last->prev;
            free(n);
            list->last->next=NULL;
            return;
        }
        current = list->first;
        while (current) {
            urm=current->next;
            if (current->data == value) {
                n = current->prev;
                m = current->next;
                n->next = m;
                m->prev = n;
                free(current);
            }
            current = urm;
        }

    }
}

void intLinkedList_push_at(IntLinkedList *list, unsigned position, int value) {
    if (list == NULL)return;
    Node *current ;
    Node *ant ;

    Node *n = (Node *) calloc(1, sizeof(Node));
    n->data = value;
    n->next = NULL;
    n->prev = NULL;

    int nr =-1,ok=0;
    current = list->first;
    if(position==0){intLinkedList_push_front(list,value);return;}
    while (current) {
        nr++;
        if (nr == position) {

            ant = current->prev;
            ant->next = n;
            n->prev = ant;

            n->next = current;
            current->prev = n;
            ok=1;
            break;
        }

        current = current->next;
    }
    if(ok==0)intLinkedList_push_back(list,value);
}

int intLinkedList_contains(IntLinkedList *list, int value) {
    Node *current;
    current = list->first;
    while (current) {
        if (current->data == value)return 1;
        current = current->next;
    }
    return 0;
}

void intLinkedList_forEach(IntLinkedList *list, void (*func)(int *)) {
    Node *current ;
    current = list->first;
    while (current) {
        func(&current->data);
        current = current->next;
    }
}