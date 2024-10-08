/*
Que retorne el número de veces que el string s1 está en el string s2.
*/

#include <stdio.h>
#include <string.h>

int my_nsubstr(const char *s1, const char *s2){
    int cont = 0;
    int ca1 = strlen(s1);
    int ca2 = strlen(s2);

    for (int i = 0; i <=ca2; i++) {
    if (strncmp(s1, s2 + i, ca1) == 0) { //se me hace conveniente usar el strncmp porque permite comparar solo los primeros n caracteres
        cont++;
    }
}
     return cont;
}



int main() {
    const char *s1 = "lo";
    const char *s2 = "hola lo lo";
    int result = my_nsubstr(s1, s2);
    printf(" resulktado %d\n", result);
    return 0;
}