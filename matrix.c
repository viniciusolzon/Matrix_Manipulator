// Vinicius Freitas     20210026803
// Natanael Neto        20190038391
#include "matrix.h"

    // int *data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // int n_rows = 3;
    // int n_cols = 4;
    // create_matrix(data, 3, 4);
    // result = {{1, 2, 3, 4},
    //           {5, 6, 7, 8},
    //           {9, 10, 11, 12}}

Matrix create_matrix(int *data, int n_rows, int n_cols){
    Matrix matriz;
    matriz.data = data;
    matriz.n_rows = n_rows;
    matriz.n_cols = n_cols;
    matriz.stride_rows = n_cols;
    matriz.stride_cols = 1;
    matriz.offset = 0;

    return matriz;
}

// int *data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
void print_matrix(Matrix matrix){
    int column = 0;
    for(int i = 0; matrix.data[i] != '\0'; i++){
        column++;
        printf("%d ", matrix.data[i]);
        if(column == matrix.stride_rows){
            column = 0;
            printf("\n");
        }
    }
}