#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


int main()
{
    int size_array = get_size_array();
    int size_heap = size_array;
    int array [size_array];

    get_data ( array, size_array );

    heapsort ( array, size_heap );

    print_array ( array, size_array );

    return 0;
}
