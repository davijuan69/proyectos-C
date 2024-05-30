/*Ejercicio: Escriba un programa que lea 20 números y
luego de asignarlos en un arreglo, determine en
que posición se encuentra el máximo y el mínimo
valor*/

#include <stdio.h>

int main(){
    int num[20];
    int max;
    int min;
   
    for(int i = 0; i < 20; i++){
        printf("ingrese un numero [%d]: ", i+1);
        scanf("%d", &num[i]);
        if (max < num[i]){
            max = num[i];
        }else if (min > num[i])
        {
            min = num[i];
        }
        

    }
    printf("el max es: %d\n", max);
    printf("el min es: %d\n", min);




    return 0;
}