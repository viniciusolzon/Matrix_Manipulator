// Vinicius Freitas     20210026803
// Natanael Neto        20190038391
#include <stdio.h>
#include "matrix.c"

int main(){

    int data[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    
    Matrix matriz = create_matrix(data, 4, 4);

    print_matrix(matriz);

    return 0;
}




