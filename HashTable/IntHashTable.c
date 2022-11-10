#include <stdio.h>
#include "IntHashTable.h"
#include <stdlib.h>
typedef struct {

    int key;
    int value;
    int occupied;
}Pereche;

struct _IntHashTable{
  Pereche *data;
  unsigned size;
};

IntHashTable *intHashTable_new(unsigned size){
    IntHashTable* hashTable=malloc(sizeof(IntHashTable));
    hashTable->size=size;
    hashTable->data=calloc(size,sizeof(Pereche));
     return hashTable;
}
void intHashTable_put(IntHashTable *hashTable, int key, int value){
   int index=key % hashTable->size;

   for(int i=0;i<hashTable->size;i++){

       int newIndex=(index+i)% hashTable->size;

       if(hashTable->data[newIndex].occupied==0){
           hashTable->data[newIndex].key=key;
           hashTable->data[newIndex].value=value;
           hashTable->data[newIndex].occupied=1;
           return;
       }else{
           if(hashTable->data[newIndex].key==key){
             hashTable->data[newIndex].value=value;
             return;

           }
       }

   }
printf("ERROR FULL");
}
void intHashTable_print(IntHashTable *hashTable){

    for(int i=0;i < hashTable->size;i++){
        printf("%d : ",i);
        if(hashTable->data[i].occupied) {
            printf("key %d  value %d\n ", hashTable->data[i].key, hashTable->data[i].value);
        }
        else {
            printf("empty\n");
        }
    }
}

void intHashTable_free(IntHashTable *hashTable){
    if(hashTable==NULL)return;
    free(hashTable->data);
    free(hashTable);

}

int *intHashTable_get(IntHashTable *hashTable, int key){
    if(hashTable){

        int index=key % hashTable->size;
          for (int i = 0; i < hashTable->size; i++) {

              int newIndex = (index + i) % hashTable->size;
              if(hashTable->data[newIndex].occupied){

                  if (hashTable->data[newIndex].key == key)
                      return &hashTable->data[newIndex].value;
              }
              else return NULL;
          }
      }
}
void intHashTable_delete(IntHashTable *hashTable, int key){
    if (hashTable->size < key)
        return;
    else{
        int index=key % hashTable->size;
        for (int i = 0; i < hashTable->size; ++i) {
            int newIndex = (index + i) % hashTable->size;
            if(hashTable->data[newIndex].key==key) {
                hashTable->data[newIndex].occupied=0;
                hashTable->data[newIndex].value=0;
                hashTable->data[newIndex].key=0;
            }
        }
    }
}