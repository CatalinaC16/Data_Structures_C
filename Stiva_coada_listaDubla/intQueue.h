#pragma once

/**
 * Structure for storing a queue of integers.
 */
typedef struct _IntQueue IntQueue;

/**
 * Creates an empty queue, with no elements.
 * @return Reference to a queue.
 */
IntQueue *intQueue_new();

/**
 * Frees all the memory used by the queue.
 * @param queue Reference to a queue.
 */
void intQueue_free(IntQueue *queue);

/**
 * Returns the number of elements in the queue
 * @param queue Reference to a queue.
 * @return The number of elements in the queue.
 * @exception If queue is NULL, 0 is returned.
 */
int intQueue_size(IntQueue *queue);

/**
 * Adds a value at the end of the queue.
 * @param queue Reference to a queue.
 * @param value The value to be added.
 */
void intQueue_enqueue(IntQueue *queue, int value);

/**
 * Removes an element from the front of the queue.
 * @param queue Reference to a queue.
 * @return A reference to the first element in the queue. If the queue is empty, NULL is returned.
 * @exception If queue is NULL, NULL is returned.
 */
int *intQueue_dequeue(IntQueue *queue);

/**
 * Gets the value from the front of the queue without removing it.
 * @param queue Reference to a queue.
 * @return A reference to the first element in the queue. If the queue is empty, NULL is returned.
 * @exception If queue is NULL, NULL is returned.
 */
int *intQueue_peek(IntQueue *queue);

/**
 * Removes all elements from the queue.
 * @param queue Reference to a queue.
 */
void intQueue_clear(IntQueue *queue);

/**
 * Checks if the queue contains the specified element.
 * @param queue Reference to a queue.
 * @param value The value to be searched.
 * @return 1 if the queue contains the value, 0 otherwise.
 */
int intQueue_contains(IntQueue *queue, int value);


/**
 * Iterates through elements of the queue and calls the func with the element's reference as a parameter.
 * @param queue Reference to a queue.
 * @param func Reference to a function to be called.
 */
void intQueue_forEach(IntQueue *queue, void (*func)(int *));
void print_queue(IntQueue *queue);