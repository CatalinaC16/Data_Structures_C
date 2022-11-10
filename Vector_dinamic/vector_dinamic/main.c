#include <stdio.h>
#include <stdlib.h>
#include "unsignedVector.h"

int main()
{
    VectorU *v1=vectorU_new();
    print_vector(v1);

    vectorU_push_back(v1, 4);
    vectorU_push_back(v1, 5);
    vectorU_push_back(v1, 2);
    vectorU_push_back(v1, 9);
   vectorU_pop_back(v1);
    print_vector(v1);

    printf("size vector %d\n",vectorU_size(v1));
    printf("memorie vector %d\n",vectorU_capacity(v1));
    printf("primul elem %d\n",*(vectorU_front(v1)));
    printf("ultimul elem %d\n",*(vectorU_back(v1)));
    printf("elem de pe poz %d \n",*(vectorU_at(v1,3)));

    vectorU_pop_back(v1);
    print_vector(v1);

    vectorU_insert(v1,0,54);
    vectorU_insert(v1,0,55);
    printf("%d",vectorU_size(v1));

    print_vector(v1);

    vectorU_erase(v1, 1,3);
    print_vector(v1);

    vectorU_clear(v1);
    print_vector(v1);

    return 0;
}
