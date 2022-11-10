#include <stdio.h>
#include "IntHashTable.h"
int main() {

    IntHashTable *table= intHashTable_new(10);
    intHashTable_put(table, 2,2 );
    intHashTable_put(table, 3,3 );
    intHashTable_put(table, 4,4 );
    intHashTable_put(table, 9,5 );
    intHashTable_put(table, 10,6);
    intHashTable_put(table, 14,26 );
    intHashTable_put(table, 20,27 );
    intHashTable_put(table, 20,107 );
    intHashTable_put(table, 20,109 );
    intHashTable_print(table);
   // intHashTable_delete(table,9);
    printf("\n");
    intHashTable_print(table);
    printf("%d\n",*intHashTable_get(table,3));
    printf("%d",*intHashTable_get(table,20));
    printf("%d",*intHashTable_get(table,40));
   intHashTable_free(table);


    return 0;
}
