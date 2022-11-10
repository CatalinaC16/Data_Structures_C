#pragma once

#include "exception.h"
ERROR_INFO errorInfo;
/**
 * Structure for storing an array that can change in size.
 */
typedef struct _VectorU VectorU;

/**
 * Creates an empty vector, with no elements. On success, errorInfo should be set to OK.
 * @return Reference to a vector.
 */
VectorU *vectorU_new();

void print_vector(VectorU *vector);

/**
 * Frees all the memory used by the vector. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @exception If vector is NULL, errorInfo should be set to NULL_POINTER.
 */
void vectorU_free(VectorU *vector);

/**
 * Returns the number of elements in the vector. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @return The number of elements in the vector.
 * @exception If vector is NULL, 0 is returned and errorInfo should be to NULL_POINTER.
 */
unsigned vectorU_size(VectorU *vector);

/**
 * Returns the size of the storage space currently allocated for the vector, expressed in terms of elements. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @return The size of the currently allocated storage capacity in the vector, measured in terms of the number elements it can hold.
 * @exception If vector is NULL, 0 is returned and errorInfo should be set to NULL_POINTER.
 */
unsigned vectorU_capacity(VectorU *vector);

/**
 * Returns a reference to the element at position n in the vector. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @param position Position of an element in the vector.
 * @return A reference to the element at position n in the vector.
 * @exception If vector is NULL, NULL is returned and errorInfo should be set to NULL_POINTER.
 * @exception If position is outside the bounds of the vector, NULL is returned and errorInfo should be set to INDEX_OUT_OF_BOUNDS.
 */
unsigned *vectorU_at(VectorU *vector, unsigned position);

/**
 * Returns a reference to the first element in the vector. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @return A reference to the first element in the vector. If the vector is empty, NULL is returned;
 * @exception If vector is NULL, NULL is returned and errorInfo should be set to NULL_POINTER.
 */
unsigned *vectorU_front(VectorU *vector);

/**
 * Returns a reference to the last element in the vector. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @return A reference to the last element in the vector. If the vector is empty, NULL is returned;
 * @exception If vector is NULL, NULL is returned and errorInfo should be set to NULL_POINTER.
 */
unsigned *vectorU_back(VectorU *vector);

/**
 * Adds a new value at the end of the vector. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @param value The value to be added.
 * @exception If vector is NULL, errorInfo should be set to NULL_POINTER.
 */
void vectorU_push_back(VectorU *vector, unsigned value);

/**
 * Removes the last element in the vector. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @exception If vector is NULL, errorInfo should be set to NULL_POINTER.
 */
void vectorU_pop_back(VectorU *vector);

/**
 * Inserts an element in the vector at the specified position. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @param position Position in the vector where the new value is inserted. The position could be the next position after the last, meaning that this function could act like the vectorU_push_back.
 * @param value Value to be inserted.
 * @exception If vector is NULL, errorInfo should be set to NULL_POINTER.
 * @exception If position is outside the bounds of the vector, errorInfo should be set to INDEX_OUT_OF_BOUNDS.
 */
void vectorU_insert(VectorU *vector, unsigned position, unsigned value);

/**
 * Removes from the vector a range of elements. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @param first Position in the vector of the first element to be removed.
 * @param last Position in the vector of the last element to be removed.
 * @exception If vector is NULL, errorInfo should be set to NULL_POINTER.
 * @exception If first or last is outside the bounds of the vector, errorInfo should be set to INDEX_OUT_OF_BOUNDS.
 * @exception If first > last, errorInfo should be set to INVALID_RANGE.
 */
void vectorU_erase(VectorU *vector, unsigned first, unsigned last);

/**
 * Removes all elements from the vector. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @exception If vector is NULL, errorInfo should be set to NULL_POINTER.
 */
void vectorU_clear(VectorU *vector);

/**
 * Iterates through elements of the vector and calls the func with the element's reference as a parameter. On success, errorInfo should be set to OK.
 * @param vector Reference to a vector.
 * @param func Reference to a function to be called.
 * @exception If vector or func is NULL, errorInfo should be set to NULL_POINTER.
 */
void vectorU_forEach(VectorU *vector, void (*func)(unsigned *));
