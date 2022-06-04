// Vinicius Freitas     20210026803
// Natanael Neto        20190038391
#include <stdio.h>
#include <stdlib.h>
#include "matrix.c"

int main(){

    // Dynamically allocated array
    int *p;
    p = malloc(sizeof(int) * 12);
    for(int i = 0; i < 12; i++){
        p[i]= i+1;
    }
    
    Matrix matriz = create_matrix(p, 3, 4);

    print_matrix(matriz);

    return 0;
}




