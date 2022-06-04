// Vinicius Freitas     20210026803
// Natanael Neto        20190038391
#include "matrix.h"

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

Matrix zeros_matrix(int n_rows, int n_cols){
    Matrix matriz;
    matriz.n_rows = n_rows;
    matriz.n_cols = n_cols;
    matriz.stride_rows = n_cols;
    matriz.stride_cols = 1;
    matriz.offset = 0;

    int *p = malloc(n_rows * n_cols * sizeof(int));
    matriz.data = p;

    int size = matriz.n_rows * matriz.n_cols;
    for(int i = 0; i < size; i++){
        matriz.data[i] = 0;
    }

    return matriz;
}

Matrix full_matrix(int n_rows, int n_cols, int value){
    Matrix matriz;
    matriz.n_rows = n_rows;
    matriz.n_cols = n_cols;
    matriz.stride_rows = n_cols;
    matriz.stride_cols = 1;
    matriz.offset = 0;

    int *p = malloc(n_rows * n_cols * sizeof(int));
    matriz.data = p;

    int size = matriz.n_rows * matriz.n_cols;
    for(int i = 0; i < size; i++){
        matriz.data[i] = value;
    }

    return matriz;
}

Matrix i_matrix(int n){
    Matrix matriz;
    matriz.n_rows = n;
    matriz.n_cols = n;
    matriz.stride_rows = n;
    matriz.stride_cols = 1;
    matriz.offset = 0;

    int *p = malloc(n * n * sizeof(int));
    matriz.data = p;

    int size = matriz.n_rows * matriz.n_cols;
    for(int i = 0; i < size; i++){
        matriz.data[i] = 0;
    }

    int count = 0;
    matriz.data[0] = 1;
    for(int i = 0; i < size; i++){
        count++;
        if(count == n+1){
            count = 0;
           matriz.data[i+1] = 1;
        }
    }

    return matriz;
}

Matrix tile_matrix(Matrix matrix, int reps){
    Matrix matriz;

    int *p = malloc(sizeof(int) * matrix.n_rows * matrix.n_cols * reps);
    matriz.data = p;

    matriz.n_rows = matrix.n_rows;
    matriz.n_cols = matrix.n_cols * reps;
    matriz.stride_rows = matriz.n_cols;
    matriz.stride_cols = 1;
    matriz.offset = 0;

    int size = matriz.n_rows * matriz.n_cols;
    int count = 0;
    for(int i = 0; i < size; i++){
        if(i == size/2){
            count = 0;
            matriz.data[i] = matrix.data[count];
            count++;
        }
        else{
            matriz.data[i] = matrix.data[count];
            count++;
        }
    }
    
    return matriz;
}


void print_matrix(Matrix matrix){
    int size = matrix.n_rows * matrix.n_cols;
    int column = 0;
    for(int i = 0; i < size; i++){
        column++;
        if(matrix.data[i] < 10){
            printf("%d  ", matrix.data[i]);
        }
        else{
            printf("%d ", matrix.data[i]);
        }
        if(column == matrix.stride_rows){
            column = 0;
            printf("\n");
        }
    }
}
