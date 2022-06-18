// Vinicius Freitas     20210026803
// Natanael Neto        20190038391
#include <stdio.h>
#include <stdlib.h>
#include "matrix.c"

int main(){

    int data[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Matrix matriz1 = create_matrix(data, 4, 3);
    print_matrix(matriz1);

    printf("\n");

    print_matrix(zeros_matrix(3, 4));

    printf("\n");

    Matrix matriz3 = full_matrix(4, 3, 7);
    print_matrix(matriz3);

    printf("\n");

    print_matrix(i_matrix(5));

    printf("\n");

    print_matrix(tile_matrix(matriz1, 4));

    printf("\n");

    printf("Min value: %d\n", min(matriz1));

    printf("Max value: %d\n", max(matriz1));

    printf("Index of min value: %d\n", argmin(matriz1));

    printf("Index of max value: %d\n", argmax(matriz1));
   
    printf("\n");

    print_matrix(add(matriz1, matriz3));

    printf("\n");

    print_matrix(sub(matriz1, matriz3));

    printf("\n");

    print_matrix(division(matriz1, matriz3));
    
    printf("\n");

    print_matrix(mul(matriz1, matriz3));
    
    printf("\n");

    printf("%d",get_element(matriz1, 3, 1));

    printf("\n");

    put_element(matriz1, 3, 1, 69);

    printf("\n");

    print_matrix(matriz1);

    printf("\n");

    print_matrix(reshape(matriz1, 2, 6));

    printf("\n");

    print_matrix(transpose(matriz1));

    printf("\n");

    print_matrix(matriz1);

    printf("\n");

    print_matrix(slice(matriz1, 0, 2, 0, 2));

    printf("\n");

    return 0;
}
