#pragma once

/**
 * Structure for storing a double-linked list.
 */
typedef struct _IntLinkedList IntLinkedList;

/**
 * Creates an empty list, with no elements.
 * @return Reference to a list.
 */
IntLinkedList *intLinkedList_new();

/**
 * Frees all the memory used by the list.
 * @param list Reference to a list.
 */
void intLinkedList_free(IntLinkedList *list);

/**
 * Returns the number of elements in the list
 * @param list Reference to a list.
 * @return The number of elements in the list.
 * @exception If list is NULL, 0 is returned.
 */
int intLinkedList_size(IntLinkedList *list);

/**
 * Returns a reference to the first element in the list.
 * @param list Reference to a list.
 * @return A reference to the first element in the list. If the list is empty, NULL is returned.
 * @exception If list is NULL, NULL is returned.
 */
int *intLinkedList_front(IntLinkedList *list);

/**
 * Returns a reference to the last element in the list.
 * @param list Reference to a list.
 * @return A reference to the last element in the list. If the list is empty, NULL is returned.
 * @exception If list is NULL, NULL is returned.
 */
int *intLinkedList_back(IntLinkedList *list);

/**
 * Adds a new value at the beginning of the list.
 * @param list Reference to a list.
 * @param value The value to be added.
 */
void intLinkedList_push_front(IntLinkedList *list, int value);

/**
 * Removes the first element in the list.
 * @param list Reference to a list.
 */
void intLinkedList_pop_front(IntLinkedList *list);

/**
 * Appends the specified element to the end of the list.
 * @param list Reference to a list.
 * @param value The value to be added.
 */
void intLinkedList_push_back(IntLinkedList *list, int value);

/**
 * Removes the last element in the list.
 * @param list Reference to a list.
 */
void intLinkedList_pop_back(IntLinkedList *list);

/**
 * Removes all elements from the list.
 * @param list Reference to a list.
 */
void intLinkedList_clear(IntLinkedList *list);

/**
 * Removes from the list all occurrences of the specified element.
 * @param list Reference to a list.
 * @param first The value to be removed.
 */
void intLinkedList_remove(IntLinkedList *list, int value);

/**
 * Inserts the specified element at the specified position in the list.
 * @param list Reference to a list.
 * @param value The value to be added.
 */
void intLinkedList_push_at(IntLinkedList *list, unsigned position, int value);

/**
 * Checks if the list contains the specified element.
 * @param list Reference to a list.
 * @param value The value to be searched.
 * @return 1 if the list contains the value, 0 otherwise.
 */
int intLinkedList_contains(IntLinkedList *list, int value);

/**
 * Iterates through elements of the list and calls the func with the element's reference as a parameter.
 * @param list Reference to a list.
 * @param func Reference to a function to be called.
 */
void intLinkedList_forEach(IntLinkedList *list, void (*func)(int *));

void print_list(IntLinkedList *list);