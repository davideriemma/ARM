#include <stdio.h>

extern int det(int * matrix, unsigned int rsize, unsigned int csize);
extern void print_matrix(int * matrix, unsigned int rsize, unsigned int csize);

int main()
{
    int matrix[4][4];
    print_matrix(matrix, 4, 4);
    printf("Determinant is: [%d]\n", det(matrix, 4, 4));

    return 0;
}