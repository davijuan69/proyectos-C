#include <stdio.h>
#include <stdlib.h>

struct Estudiantes{
    char nombre[50];
    int nota;
};

int main(){
    struct Estudiantes* A_Estudiantes;
    int NumEstu = 3;
    A_Estudiantes = (struct Estudiantes*)malloc(NumEstu * sizeof(struct Estudiantes));
    for(int i = 0; i<NumEstu; i++){
        printf("Ingrese nombre del estudiante: %d", i + 1);
        scanf("%s", (A_Estudiantes + i)->nombre);
        printf("Ingrese nombre del clasificacion: %d", i + 1);
        scanf("%s", (A_Estudiantes + i)->nota);
    }
    for(int i = 0; i<NumEstu; i++){
        printf("nuemro de estudiantes: %i", 1 + i);
        printf("Nombre: %s\n", (A_Estudiantes + i)->nombre);
        printf("Nombre: %s\n", (A_Estudiantes + i)->nota);
    }


    
    return 0;
}

