/*
Dado un string con una secuencia de paréntesis (que abren y cierran en
cualquier orden), escriba en C una función que verifiquen que están
balanceados.
*/

//0 para falso y 1 para verdadero

#include <stdio.h>


int Balanceados(char* Prueba){
    int cont = 0; 
    for(int i = 0; Prueba[i] != '\0'; i++){
        if(Prueba[i] == '('){
            cont++;
        }
        if(Prueba[i] == ')'){
            cont--;
        }
        if(cont < 0){
            return 0;
        }
    }

    return cont == 0;

    
}

int main(){
    char* Prue1 = "((()))";
    printf("es balanceado?: %i\n", Balanceados(Prue1));
}

