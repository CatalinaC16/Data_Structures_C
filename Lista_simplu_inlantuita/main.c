#include <stdio.h>
#include "liste.h"

int main() {
    IntLinkedList *list = intLinkedList_new();

    intLinkedList_insertLast(list, 7);
    intLinkedList_insertLast(list, 5);
    intLinkedList_insertLast(list, 8);
    intLinkedList_insertFirst(list, 3);
    intLinkedList_insertLast(list, 4);

    intLinkedList_print(list);

    intLinkedList_insertAfter(list, 5, 6);

    intLinkedList_print(list);

    printf(" %d ", intLinkedList_search(list, 8));
    printf("%d ", intLinkedList_search(list, 2));

    intLinkedList_deleteFirst(list);
    intLinkedList_print(list);

    intLinkedList_deleteValue(list,7); intLinkedList_print(list);
      intLinkedList_deleteValue(list,4);

    intLinkedList_print(list);

    intLinkedList_free(list);

    return 0;
}
