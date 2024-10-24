/*
¿Cómo se implementa en C un paso de parámetros a una función por
referencia?
*/
#include <stdio.h>

void Valor(int i){
    i = i+1;
}

void Referencia(int* i){
    *i = *i+1;

}
