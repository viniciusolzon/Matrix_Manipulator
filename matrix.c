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

    matriz.n_rows = matrix.n_rows * reps;
    matriz.n_cols = matrix.n_cols;
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

int get_element(Matrix matrix, int ri, int ci){
    if(ri >= matrix.n_rows){
        printf("Index out of range.");
        return 0;
    }
    if(ci >= matrix.n_cols){
        printf("Index out of range.");
        return 0;
    }else{
        int element = matrix.data[((ri * matrix.n_cols) + ci)];

        return element;
    }
}

void put_element(Matrix matrix, int ri, int ci, int elem){
    if(ri >= matrix.n_rows){
        printf("Index out of range.");
        return 0;
    }
    if(ci >= matrix.n_cols){
        printf("Index out of range.");
        return 0;
    }else{
        matrix.data[((ri * matrix.n_cols) + ci)] = elem;
    }
}

void print_matrix(Matrix matrix){
    int size = matrix.n_rows * matrix.n_cols;
    int column = 0;
    for(int i = 0; i < size; i++){
        column++;
        if(matrix.data[i] >= 10 || matrix.data[i] < 0){
            printf("%d ", matrix.data[i]);
        }
        else{
            printf("%d  ", matrix.data[i]);
        }
        if(column == matrix.stride_rows){
            column = 0;
            printf("\n");
        }
    }
}

Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols){
    int size = matrix.n_rows * matrix.n_cols;
    if((new_n_rows * new_n_cols) > size){
        printf("Reshape failed, you are trying to reshape the original matrix into a larger one.\n");
    }
    else{
        matrix.n_rows = new_n_rows;
        matrix.n_cols = new_n_cols;
        matrix.stride_rows = matrix.n_cols;
        matrix.stride_cols = 1;
    }

    return matrix;
}

int min(Matrix matrix){
    int size = matrix.n_rows * matrix.n_cols;
    int min_value = 99999;
    for(int i = 0; i < size; i++){
        if (matrix.data[i] < min_value){
            min_value = matrix.data[i];
        }
    }

    return min_value;
}

int max(Matrix matrix){
    int size = matrix.n_rows * matrix.n_cols;
    int max_value = -99999;
    for(int i = 0; i < size; i++){
        if (matrix.data[i] > max_value){
            max_value = matrix.data[i];
        }
    }

    return max_value;
}

int argmin(Matrix matrix){
    int size = matrix.n_rows * matrix.n_cols;
    int min_value = 99999;
    for(int i = 0; i < size; i++){
        if (matrix.data[i] < min_value){
            min_value = i;
        }
    }

    return min_value;
}

int argmax(Matrix matrix){
    int size = matrix.n_rows * matrix.n_cols;
    int max_value = -99999;
    for(int i = 0; i < size; i++){
        if (matrix.data[i] > max_value){
            max_value = i;
        }
    }

    return max_value;
}

Matrix add(Matrix matrix_1, Matrix matrix_2){
    Matrix matriz;

    int *p = malloc(sizeof(int) * matrix_1.n_rows * matrix_1.n_cols);
    matriz.data = p;

    matriz.n_rows = matrix_1.n_rows;
    matriz.n_cols = matrix_1.n_cols;
    matriz.stride_rows = matrix_1.n_cols;
    matriz.stride_cols = 1;
    matriz.offset = 0;
    
    int size = matrix_1.n_rows * matrix_1.n_cols;
    for(int i = 0; i < size; i++){
        matriz.data[i] = matrix_1.data[i] + matrix_2.data[i];
    }

    return matriz;
}

Matrix sub(Matrix matrix_1, Matrix matrix_2){
    Matrix matriz;

    int *p = malloc(sizeof(int) * matrix_1.n_rows * matrix_1.n_cols);
    matriz.data = p;

    matriz.n_rows = matrix_1.n_rows;
    matriz.n_cols = matrix_1.n_cols;
    matriz.stride_rows = matrix_1.n_cols;
    matriz.stride_cols = 1;
    matriz.offset = 0;
    
    int size = matrix_1.n_rows * matrix_1.n_cols;
    for(int i = 0; i < size; i++){
        matriz.data[i] = matrix_1.data[i] - matrix_2.data[i];
    }

    return matriz;
}

Matrix division(Matrix matrix_1, Matrix matrix_2){
    Matrix matriz;

    int *p = malloc(sizeof(int) * matrix_1.n_rows * matrix_1.n_cols);
    matriz.data = p;

    matriz.n_rows = matrix_1.n_rows;
    matriz.n_cols = matrix_1.n_cols;
    matriz.stride_rows = matrix_1.n_cols;
    matriz.stride_cols = 1;
    matriz.offset = 0;
    
    int size = matrix_1.n_rows * matrix_1.n_cols;
    for(int i = 0; i < size; i++){
        matriz.data[i] = matrix_1.data[i] / matrix_2.data[i];
    }

    return matriz;
}

Matrix mul(Matrix matrix_1, Matrix matrix_2){
    Matrix matriz;

    int *p = malloc(sizeof(int) * matrix_1.n_rows * matrix_1.n_cols);
    matriz.data = p;

    matriz.n_rows = matrix_1.n_rows;
    matriz.n_cols = matrix_1.n_cols;
    matriz.stride_rows = matrix_1.n_cols;
    matriz.stride_cols = 1;
    matriz.offset = 0;
    
    int size = matrix_1.n_rows * matrix_1.n_cols;
    for(int i = 0; i < size; i++){
        matriz.data[i] = matrix_1.data[i] * matrix_2.data[i];
    }

    return matriz;
}

Matrix transpose(Matrix matrix){
    Matrix matrix_t;
    int tamanho = matrix.n_cols * matrix.n_rows;
    int *p = malloc(sizeof(int) * tamanho);
    matrix_t.data = p;
    matrix_t.n_rows = matrix.n_cols;
    matrix_t.n_cols = matrix.n_rows;
    matrix_t.offset = matrix.offset;
    matrix_t.stride_cols = 1;
    matrix_t.stride_rows = matrix_t.n_cols;
    int aux = 0;
    int proximo = 0;
    for(int i = 0; i < tamanho; i++){
        matrix_t.data[aux] = matrix.data[i];  
        if(aux >= (tamanho - matrix_t.n_cols)){
            proximo++;  
            aux = proximo;
        }else{
            aux += matrix_t.n_cols;
        }
         
    }
   
    

    return matrix_t;
}
