/*
Escriba la función HasZeroDiagonal que, dada una matriz de NxN de
enteros, retorne 1 si todos los elementos de la diagonal son 0 retorne 0 en caso
contrario.
*/
#include <stdio.h>

int HasZeroDiagonal(int matriz[][20], int N){
    for(int i =0; i < N; i++){
        if(matriz[i][i] != 0){
            return 0;
        }
    }
    return 1;
} 

int main(){
    int N = 3;
    int matriz[3][3] = {{0,2,3},{1,0,3},{1,2,0}};
    /*
    int resultado = HasZeroDiagonal(matriz, N);
    printf("tiene diagonal?: %i", resultado);
    */
   if (HasZeroDiagonal(matriz, N)) {
        printf("la diagonal completa es 0\n");
    } else {
        printf("no tiene la diagonal completa con el 0\n");
    }

    return 0;
}