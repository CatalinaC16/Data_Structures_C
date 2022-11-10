#pragma once
typedef struct _IntLinkedList IntLinkedList;///done

IntLinkedList *intLinkedList_new();///done

void intLinkedList_free(IntLinkedList *list);///done

int intLinkedList_search(IntLinkedList *list, int value);///done

void intLinkedList_insertFirst(IntLinkedList *list, int value);///done

void intLinkedList_insertLast(IntLinkedList *list, int value);///done

void intLinkedList_insertAfter(IntLinkedList *list, int afterValue, int value);///done

void intLinkedList_deleteFirst(IntLinkedList *list);///done

void intLinkedList_deleteValue(IntLinkedList *list, int value);///done

void intLinkedList_print(IntLinkedList *list);///done
