#include <stdio.h>
#include "intDoubleLinkedList.h"
#include "intQueue.h"
#include  "intStack.h"

void func(int *elem) {
    *elem += 3;
}

int main() {

/*
    IntStack *stack = intStack_new();
    print_stack(stack);
     intStack_push(stack, 3);
     intStack_push(stack, 6);
     intStack_push(stack, 2);
    print_stack(stack);
     intStack_forEach(stack, func );
    print_stack(stack);
     printf("%d \n", intStack_size(stack));
     intStack_pop(stack);
     print_stack(stack);
     printf("%d\n", intStack_contains(stack, 3));
     printf("%d\n", intStack_contains(stack, 10));
     printf("%d \n", *intStack_peek(stack));
    intStack_clear(stack);
     print_stack(stack);
     intStack_free(stack);

*/
    IntLinkedList *list = intLinkedList_new();
    print_list(list);
    intLinkedList_push_front(list, 7);
    intLinkedList_push_back(list, 8);
    intLinkedList_push_front(list, 5);
    intLinkedList_push_front(list, 9);
    intLinkedList_push_back(list, 4);

    print_list(list);
    intLinkedList_push_at(list, 2, 34);
    intLinkedList_push_at(list, 0, 33);
    intLinkedList_push_at(list, 8, 35);

    print_list(list);
    intLinkedList_remove(list, 5);
    intLinkedList_remove(list, 33);
    intLinkedList_remove(list, 35);
    print_list(list);
    intLinkedList_pop_back(list);
    intLinkedList_pop_front(list);
    print_list(list);
    printf("\n %d \n ", *intLinkedList_back(list));
    printf("%d \n", *intLinkedList_front(list));
    printf(" %d \n", intLinkedList_size(list));
    printf(" %d \n ", intLinkedList_contains(list, 8));
    intLinkedList_forEach(list, func);
    print_list(list);
 intLinkedList_clear(list);
    print_list(list);
    intLinkedList_free(list);
/*
     IntQueue *queue=intQueue_new();
     intQueue_enqueue(queue,6);
     intQueue_enqueue(queue,3);
     intQueue_enqueue(queue,9);
     intQueue_enqueue(queue,4);
    print_queue(queue);
    printf("\n %d \n ", intQueue_contains(queue,5));
    printf("%d \n ", intQueue_contains(queue,9));
     printf("size %d \n ",intQueue_size(queue));
     printf("first elem %d \n",*intQueue_peek(queue));
     printf("new first elem %d\n ", *intQueue_dequeue(queue));
     print_queue(queue);
    intQueue_forEach(queue,func);
    print_queue(queue);
    intQueue_clear(queue);
     print_queue(queue);
    intQueue_free(queue);*/

    return 0;
}
