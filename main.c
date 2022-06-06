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

    Matrix matriz2 = zeros_matrix(3, 4);
    print_matrix(matriz2);

    printf("\n");

    Matrix matriz3 = full_matrix(4, 3, 8);
    print_matrix(matriz3);

    printf("\n");

    Matrix matriz4 = i_matrix(5);
    print_matrix(matriz4);

    printf("\n");

    Matrix matriz5 = tile_matrix(matriz1, 3);
    print_matrix(matriz5);

    printf("\n");

    printf("Min value: %d\n", min(matriz1));

    printf("Max value: %d\n", max(matriz1));

    printf("Index of min value: %d\n", argmin(matriz1));

    printf("Index of max value: %d\n", argmax(matriz1));
   
    printf("\n");

    Matrix matriz_add = add(matriz1, matriz3);

    print_matrix(matriz_add);
    
    printf("\n");

    Matrix matriz_sub = sub(matriz1, matriz3);

    print_matrix(matriz_sub);
    
    printf("\n");

    Matrix matriz_divison = division(matriz1, matriz3);

    print_matrix(matriz_divison);
    
    printf("\n");

    Matrix matriz_mul = mul(matriz1, matriz3);

    print_matrix(matriz_mul);
    
    printf("\n");

    printf("%d",get_element(matriz1, 3, 1));

    printf("\n");

    put_element(matriz1, 3, 1, 69);

    printf("\n");

    print_matrix(matriz1);

    printf("\n");

    Matrix matriz1_reshaped = reshape(matriz1, 2, 6);

    print_matrix(matriz1_reshaped);

    printf("\n");

    print_matrix(matriz1);

    printf("\n");
    
    print_matrix(transpose(matriz1));

    printf("\n");

    // print_matrix(slice(matriz_mul, 0, 2, 1, 3));

    printf("\n");

    return 0;
}
