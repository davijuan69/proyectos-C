/*
Invertir un string, por ejemplo, convierte a “abc” en “cba”,
trabaja sobre el mismo espacio apuntado por s.
*/

#include <stdio.h>
#include <stdio.h>

void my_strrev(char *s){
    int inicio = 0;
    int fin = strlen(s) - 1;
    char temp;

    while (inicio < fin) {
        temp = s[inicio];
        s[inicio] = s[fin];
        s[fin] = temp;
        inicio++;
        fin--;
    }
}
    


int main(){
    char str[] = "abc";
    printf("Original: %s\n", str);
    my_strrev(str);
    printf("Invertido: %s\n", str);
    return 0;
}