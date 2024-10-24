/*
¿Qué problema tiene la siguiente función? Reescriba el código de la
función para arreglarlo, sin cambiar las premisas de uso.
*/

#include <stdio.h>
#include <stdlib.h>

char* WordInput(){
    char* p = (char*) malloc(20 * sizeof(char));
    printf ("Type a word: ");
    scanf ("%s", p);
    return p;
}

int main(){
    char* type = WordInput();
    printf("%s", type);
    free(type);
    return 0;
}