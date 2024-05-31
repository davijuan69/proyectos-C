#include <stdio.h>
#include <stdlib.h> 

int main(){
    int *p = (int*)malloc(sizeof(int)); //le estas diciendo al programa que el espacio que estas asignando sea un entero con(int*)
                              //el 4 es la cantidad de espacio/bytes que quieres almacenas
                              //Es mas recomendable usar sezeof en vez del numero de bytes


    *p = 0;

    printf("contenido del puntero: %d", *p); //con *p estas diciendole al programa que imprima el contenido del puntero
                                            //como malloc no inicializa nos va a imprimir un archivo basura, tendemos que inicializar los punteros



    int *arrp = (int*)malloc(3*sizeof(int)); //le dice al programa que guarde espacio para tres enteros

    *(arrp + 1) = 5;

    printf("direccion (arrp + 1): %d", *(arrp + 1));

    free(arrp); 



    return 0;
}