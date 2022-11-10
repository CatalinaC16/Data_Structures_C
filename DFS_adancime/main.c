#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;

} Node;

typedef struct _IntStack {
    Node *top;
}IntStack;

IntStack *intStack_new() {

    IntStack *stack = (IntStack *) calloc(1, sizeof(IntStack));
    stack->top = NULL;
    return stack;
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
void dfs(int i,int *visited, int n,int **a){
    IntStack  *stack=intStack_new();
    intStack_push(stack,i);
    visited[i]=1;
    while(stack->top!=NULL)
    {
        int varf= *intStack_peek(stack);
        intStack_pop(stack);
         printf("%d ",varf);

            for (int j = 0; j < n; j++) {
                if (!visited[j] && a[varf][j] == 1) {
                    intStack_push(stack, j);
                    visited[j]=1;
                }
            }


    }

}
int main() {
int n;
   FILE *f= fopen("graf_dfs.txt","r");
   if(f==NULL)
   {
       printf("nu s-a deschis");
       return 4;
   }
   fscanf(f,"%d",&n);

int **a= calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
    {
        a[i]=calloc(n,sizeof(int));
    }
    int *visited=calloc(n,sizeof(int));
    int x, y;
    while(!feof(f))
    {
        fscanf(f,"%d %d",&x,&y);
        a[x][y]=1;
        a[y][x]=1;

    }

    dfs(1,visited,n, a);
    return 0;
}
