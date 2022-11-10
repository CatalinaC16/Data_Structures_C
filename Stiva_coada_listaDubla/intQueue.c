#include <stdio.h>
#include <stdlib.h>
#include "intQueue.h"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

struct _IntQueue{
    Node* front;
    Node* rear;
};

IntQueue *intQueue_new(){
    IntQueue *queue = (IntQueue*) calloc(1, sizeof(IntQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void intQueue_free(IntQueue *queue){
    Node *current;
    Node *urm;
    current = queue->front;
    urm = NULL;

    while (current) {
        urm = current->next;
        free(current);
        current = urm;
    }
  free(queue);
}

int intQueue_size(IntQueue *queue){
    Node *current;
    current = queue->front;
    int nr = 0;
    if (queue->rear == NULL)return 0;
    while (current) {
        nr++;
        current = current->next;
    }
    return nr;
}

void intQueue_enqueue(IntQueue *queue, int value){
    Node* p=(Node*)calloc(1,sizeof(Node));
    p->data=value;
    p->next=NULL;
    if(queue==NULL)return;
    if(queue->rear==NULL){
        queue->front=p;
        queue->rear=p;
        queue->rear->next=NULL;
    }
    else {
        queue->rear->next = p;
        queue->rear = p;
        queue->rear->next=NULL;
    }
}
void print_queue(IntQueue *queue){
    if (queue) {
        Node *current = (Node *) calloc(1, sizeof(Node));
        printf("[");
        current = queue->front;
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("]");
        printf("\n");
    }
   else printf("coada nu exista!");
}

int *intQueue_dequeue(IntQueue *queue){
    if(queue->rear==NULL) return NULL;
   Node* p = queue->front;
    queue->front=queue->front->next;
    free(p);
    return &queue->front->data;
}

int *intQueue_peek(IntQueue *queue){
    if(queue == NULL &&  queue->front==NULL) return NULL;
    return &queue->front->data;
}

void intQueue_clear(IntQueue *queue){
    Node *current;
    Node *urm;
    current = queue->front;
    urm = NULL;

    while (current) {
        urm = current->next;
        free(current);
        current = urm;
    }
    queue->rear=NULL;
    queue->front=NULL;
}

int intQueue_contains(IntQueue *queue, int value){

    Node *current;
    current = queue->front;
    while (current) {
        if (current->data == value) return 1;
        current = current->next;
    }
    return 0;
}

void intQueue_forEach(IntQueue *queue, void (*func)(int *)){
    Node *current ;
    current = queue->front;
    while (current) {
        func(&current->data);
        current = current->next;
    }
}