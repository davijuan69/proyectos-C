#include <stdio.h>
#include <string.h>

char *trimAll(char *str){
    int star = 0, end = strlen(str), j = 0;
    char* str2 = str; 

    while (str[star] == ' '){
        star++;
    }
    while(end >= star && str[end] == ' '){
        end --;
    }
    for (int i = star; i <= end; i++) {
        if (str[i] != ' ' || (i > star && str[i - 1] != ' ')) {
            str2[j++] = str[i];
        }
    }
    str2[j] = '\0';

    return str2;
}

int main() {
    char Espacios[] = "   hola   mundo  ";
    printf("Original: '%s'\n", Espacios);
    printf("Trimmed: '%s'\n", trimAll(Espacios));
    return 0;
}