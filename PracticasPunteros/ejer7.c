/*
Haga una función que calcule la ocurrencia de un número dado.
*/

#include <stdio.h>

int CalcularOcurrencia(int arr[], int tam, int num) {
    int cont = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == num) {
           cont++;
        }
    }
    return cont;
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 2, 5, 2};
    int tam = sizeof(arr) / sizeof(arr[0]);
    int num = 2;
    int resultado = CalcularOcurrencia(arr, tam, num);
    printf("resultado %d\n", resultado);
    return 0;
}