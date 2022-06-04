// Vinicius Freitas     20210026803
// Natanael Neto        20190038391
#include <stdio.h>
#include "matrix.c"

int main(){

    int data[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    Matrix matriz1 = create_matrix(data, 4, 4);
    print_matrix(matriz1);

    Matrix matriz2 = zeros_matrix(3, 4);
    print_matrix(matriz2);

    Matrix matriz3 = full_matrix(3, 3, 1);
    print_matrix(matriz3);

    return 0;
}




