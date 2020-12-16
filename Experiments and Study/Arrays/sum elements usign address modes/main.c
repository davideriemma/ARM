#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int sum_array(const int * array, size_t size);
extern void print_array(const int * array, size_t size);

int main()
{

    int array[10];

    srand(getpid());

    for(int i = 0; i < sizeof(array) / sizeof(int); ++i)
    {
        array[i] = 1 + rand() % 20;
    }

    print_array(array, sizeof(array) / sizeof(int));

    printf("Sum of the elements of the array is: %d\n", sum_array(array, sizeof(array) / sizeof(int)));

    return 0;
}