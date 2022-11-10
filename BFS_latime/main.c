#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct _IntQueue{
    Node* front;
    Node* rear;
}IntQueue;

IntQueue *intQueue_new(){
    IntQueue *queue = (IntQueue*) calloc(1, sizeof(IntQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
void intQueue_enqueue(IntQueue *queue, int value){
    Node* p=(Node*)calloc(1,sizeof(Node));
    p->data=value;

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

int *intQueue_peek(IntQueue *queue){
    if(queue == NULL &&  queue->front==NULL) return NULL;
    return &queue->front->data;
}
void intQueue_dequeue(IntQueue *queue){
    if(queue->rear==NULL) return;
    if(queue->front->next==NULL) queue->rear=NULL;
    Node* p = queue->front;
    queue->front=queue->front->next;
    free(p);
}

void BFS(int i,int *visited,int n,int** a)
{

    IntQueue *q= intQueue_new();
    intQueue_enqueue(q,i);
    visited[i]=1;

    while(q->front!=NULL) {
        int v= *intQueue_peek(q);
        printf("%d ",v);
        intQueue_dequeue(q);
        for (int j = 0; j < n; j++) {
            if (!visited[j] && a[v][j] == 1) {
                intQueue_enqueue(q,j);
                visited[j]=1;
            }
        }
    }
}

int main() {

 char *nume_fisier="graf_matrice.txt";
 FILE *p= fopen(nume_fisier,"r");
 int n;
 fscanf(p,"%d",&n);
 printf("%d",n);
 int *visited=calloc(n,sizeof(int));
 int **a = calloc(n,sizeof(int*));
    for (int i=0; i<n;i++)
    {
        a[i] = calloc(n,sizeof(int));
    }

 int x, y;
 while(!feof(p))
 {
     fscanf(p,"%d %d",&x,&y);
     a[x][y]=1;
     a[y][x]=1;

 }
 printf("\n");
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        printf("%d ",a[i][j]);
    }
    printf("\n");
}


    BFS(0,visited,n,a);


    return 0;
}
