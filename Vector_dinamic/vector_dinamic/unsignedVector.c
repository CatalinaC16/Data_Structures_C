#include "unsignedVector.h"
#include <stdlib.h>

struct _VectorU
{
    unsigned *data;
    unsigned size;
    unsigned capacity;
};


VectorU *vectorU_new()
{

    VectorU *vector=malloc(sizeof(VectorU));
    if(!vector)return NULL;
    vector->size=0;
    vector->capacity=20;
    vector->data= malloc(vector->capacity*sizeof(unsigned));
    errorInfo=OK;
    return vector;
}
void vector_print(VectorU *vector)
{
    if (vector)
    {
        printf("[");
        for (int i = 0; i < vector->size; ++i)
        {
            printf("%d ", vector->data[i]);
        }
        printf("]\n");
    }
}

void vectorU_free(VectorU *vector)
{
    if(vector)
    {
        free(vector->data);
        free(vector);
        errorInfo = OK;
    }
    else  errorInfo = NULL_POINTER;
}

unsigned vectorU_size(VectorU *vector)
{

    if(vector)
    {
        errorInfo = OK;
        return vector->size;
    }
    else
    {
        errorInfo = NULL_POINTER;
        return 0 ;
    }
}

unsigned vectorU_capacity(VectorU *vector)
{
    if(vector)
    {
        errorInfo = OK;
        return vector->capacity *sizeof(unsigned);
    }
    else
    {
        errorInfo = NULL_POINTER;
        return 0;
    }
}
void print_vector(VectorU *vector)
{
    if (vector)
    {
        printf("[");
        for (int i = 0; i < vector->size; i++)
        {
            printf("%d ", vector->data[i]);
        }
        printf("]\n");
    }
}
unsigned *vectorU_at(VectorU *vector, unsigned position)
{

    if(vector)
    {
        if(position>vector->capacity){
            errorInfo = INDEX_OUT_OF_BOUNDS;
            return NULL;
        }

        errorInfo = OK;
        return &vector->data[position];
    }
    else
    {
        errorInfo = NULL_POINTER;
        return NULL;
    }
}

unsigned *vectorU_front(VectorU *vector)
{
    if(vector)
    {  errorInfo = OK;
        if(vector->size==0)return NULL;
        else return &vector->data[0];
    }
    else
    {
        errorInfo = NULL_POINTER;
        return NULL;
    }
}

unsigned *vectorU_back(VectorU *vector)
{
    if(vector)
    {

        errorInfo = OK;
        if(vector->size==0)return NULL;
        else  return &vector->data[vector->size-1];

    }
    else
    {
        errorInfo = NULL_POINTER;
        return NULL;
    }
}
void vectorU_push_back(VectorU *vector, unsigned value)
{
    if(vector)
    {
        if (vector->size == vector->capacity)
        {
            vector->capacity *= 2;
            vector->data = realloc(vector->data, vector->capacity * sizeof(unsigned));
        }
        vector->data[vector->size]=value;
        vector->size++;
        errorInfo = OK;
    }
    else errorInfo = NULL_POINTER;
}

void vectorU_pop_back(VectorU *vector)
{
    if(vector)
    {
        vector->data= realloc(vector->data, (vector->size--)*sizeof(unsigned));
        errorInfo=OK;
    }
    else errorInfo = NULL_POINTER;
}

void vectorU_insert(VectorU *vector, unsigned position, unsigned value)
{
    if(vector)
    {
        if (position<=vector->capacity)
        {
            errorInfo = OK;
            for(unsigned i=0; i<vector->size; i++)
            {
                if(i==position)
                {
                    for(unsigned j=vector->size; j>i; j--)
                    {
                        vector->data[j]=vector->data[j-1];
                    }
                    vector->data[i]=value;

                }

            }
            vector->size++;

        }

        else errorInfo=INDEX_OUT_OF_BOUNDS;
    }
    else errorInfo = NULL_POINTER;

}


void vectorU_erase(VectorU *vector, unsigned first, unsigned last) {
    if (vector == NULL) {
        errorInfo = NULL_POINTER;
        return;
    }
    if (first > (vector->size) || last > (vector->size)) {
        errorInfo = INDEX_OUT_OF_BOUNDS;
        return;
    }
    if (first > last) {
        errorInfo = INVALID_RANGE;
        return;
    }

    errorInfo = OK;
if(first!=last){
        for (unsigned i = 0; i < vector->size; ++i) {
            if (last == i) {
                for (unsigned j = i; j < vector->size - 1;++j) {
                    vector->data[j] = vector->data[j + 1];

                }

                vector->size--;
                for (unsigned int z = 0; z <= last; z++) {
                    if (z == first) {
                        for (unsigned j = first; j < vector->size - 1; j++) {
                            vector->data[j] = vector->data[j + 1];
                        }


                    }
                }
                vector->size--;
            }

        }

    }
    if (last == first) {

        for (unsigned i = 0; i < vector->size; i++) {
            if (last == i) {
                for (unsigned j = i; j < vector->size - 1; j++) {
                    vector->data[j] = vector->data[j + 1];

                }

            }
        }
       vector->size--;
    }

}

void vectorU_clear(VectorU *vector)
{ if(vector) {
        for (unsigned i = vector->size; i > 0; i--) {

            for (unsigned j = i; j <= vector->size - 1; j++) {

                vector->data[i] = vector->data[i + 1];
            }
            vector->size--;
        errorInfo=OK;
        }
    }else errorInfo=NULL_POINTER;
}
/*for (int p = n - 1 ; p >= 0 ; p --)
if(X[p] % 2 == 0) {
for(int i = p ; i < n - 1; i ++)
X[i] = X[i+1];
n --;
}*/
void vectorU_forEach(VectorU *vector, void (*func)(unsigned *))
{
    if (vector && vector->size>01){
        for(int i=0;i<vector->size;i++){
            func(&vector->data[i]);
            errorInfo=OK;
        }
    }
    else errorInfo=NULL_POINTER;
}
