/*
escriba funciones en lenguaje C, que imprima por pantalla, a mp y ma.
*/

#include <stdio.h>

int f0[] = { 0, 1, 2, 3, 4 };
int f1[] = { 10, 11, 12, 13, 14 };
int f2[] = { 20, 21, 22, 23, 24 };
int f3[] = { 30, 31, 32, 33, 34 };
int f4[] = { 40, 41, 42, 43, 44 };
int* fp[] = { f0, f1, f2, f3, f4 };
int** mp = fp;
int ma[][5] = {
    {0, 1, 2, 3, 4},
    {10, 11, 12, 13, 14},
    {20, 21, 22, 23, 24},
    {30, 31, 32, 33, 34},
    {40, 41, 42, 43, 44}
};

void print_mp(int** mp, const char* names[], int filas, int colunm) {
    for (int i = 0; i < filas; i++) {
        printf("%s: ", names[i]);
        for (int j = 0; j < colunm; j++) {
            printf("%d ", mp[i][j]);
        }
        printf("\n");
    }
}

void print_ma(int ma[][5], int filas, int colunm) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < colunm; j++) {
            printf("%d ", ma[i][j]);
        }
        printf("\n");
    }
}

int main() {
    const char* nombres[] = { "f0", "f1", "f2", "f3", "f4" };

    printf("Valores de mp:\n");
    print_mp(mp, nombres, 5, 5);

    printf("\nValores de ma:\n");
    print_ma(ma, 5, 5);

    return 0;
}