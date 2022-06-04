// Vinicius Freitas     20210026803
// Natanael Neto        20190038391
#include <stdio.h>
#include <stdlib.h>
#include "matrix.c"

int main(){

    int data[6] = {1, 2, 3, 4, 5, 6};
    Matrix matriz1 = create_matrix(data, 2, 3);
    print_matrix(matriz1);

    printf("\n");

    Matrix matriz2 = zeros_matrix(3, 4);
    print_matrix(matriz2);

    printf("\n");

    Matrix matriz3 = full_matrix(3, 3, 8);
    print_matrix(matriz3);

    printf("\n");

    Matrix matriz4 = i_matrix(5);
    print_matrix(matriz4);

    printf("\n");

    Matrix matriz5 = tile_matrix(matriz1, 2);
    print_matrix(matriz5);

    printf("\n");

    return 0;
}
