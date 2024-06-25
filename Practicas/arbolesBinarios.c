#include <stdio.h>
#include <stdlib.h>

/*La función void imprimirNivel (nodo_t *A, int nivel) que imprima de
izquierda a derecha los nodos del árbol que se encuentran en el nivel
dado, siendo la raíz el nivel 0.*/

/*
La función int predecesor (nodo_t *A, int *pre) que retorne 1 o 0 en caso
de tener o no sucesor y guarde en pre el valor del nodo sucesor del
árbol dado para imprimirlo posteriormente en main.
*/

/*
Las funciones int menor (nodo_t *arbolbp, int *elemento) e int mayor
(nodo_t *arbolbp, int *elemento), que buscan el menor y el mayor
elemento en un árbol binario y lo retorna en la variable elemento. La
función debe retornar 0 si el apuntador al árbol es NULL y 1 en caso
contrario.
*/

/*
Una función en C que, dado un nodo de un árbol binario, calcule su
altura y su profundidad.
*/

typedef struct nodo{
    int valor;
    struct nodo* izq, *dere;
}Nodo;

Nodo* crearNodo(int elem){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dere = NULL;
    nuevo->izq = NULL;
    nuevo->valor = elem;
    return(nuevo);
}

void insertar(Nodo** arbol, int elem){
    if(*arbol == NULL){
        (*arbol) = crearNodo(elem);
    }
    else{
        if((*arbol)->valor < elem){
            insertar(&(*arbol)->dere, elem);
        }else{
            if((*arbol)->valor > elem){
                insertar(&(*arbol)->izq, elem);
            }
        }
    }
}

void imprimir(Nodo* arbol, int nivel){
    if(arbol == NULL) return;
    imprimir(arbol->dere, nivel+1);
    for(int i = 0; i<nivel; i++){
        printf(" ");
    }
    printf("%d\n", arbol->valor);
    imprimir(arbol->izq, nivel+1);
}

void imprimirNivel(Nodo* arbol, int nivel){
    if(arbol == NULL) return;
    if(nivel == 0){
        printf("%d\n", arbol->valor);
    }else{
        imprimirNivel(arbol->izq, nivel-1);
        imprimirNivel(arbol->dere, nivel-1);
    }
}

int predecesor(Nodo* arbol, int* prede){
    if(arbol == NULL || arbol->izq == NULL) return 0;
    if(arbol->izq != NULL){
    Nodo* temp = arbol->izq;
    while (temp->dere != NULL){
        temp = temp->dere;
    }
    *prede = temp->valor;
    return 1;
    }
    return 0;
}


void freeArbol(Nodo* arbol){
    if(arbol == NULL) return;
    freeArbol(arbol->dere);
    freeArbol(arbol->izq);
    free(arbol);
}


int menor(Nodo* arbol, int* elemento){
    if(arbol == NULL) return 0; 
    Nodo* temp = arbol;
    while (temp->izq != NULL){
        temp = temp->izq;
    }
    *elemento = temp->valor;
    return 1;
}
int mayor(Nodo* arbol, int* elemento){
    if(arbol == NULL) return 0;
    Nodo*  temp = arbol;
    while (temp->dere != NULL){
        temp = temp->dere;
    }
    *elemento = temp->valor;
    return 1;
    
}


int main(){
    Nodo* arbol = NULL;
    int prede = 0;
    int menorElemento = 0;
    int mayorElemento = 0;
    insertar(&arbol, 6);
    insertar(&arbol, 7);
    insertar(&arbol, 8);
    insertar(&arbol, 10);
    insertar(&arbol, 3);
    insertar(&arbol,5);
    insertar(&arbol, 4);
    imprimir(arbol, 1);
    predecesor(arbol, &prede);

    if (menor(arbol, &menorElemento)) {
    printf("El menor elemento del arbol es: %d\n", menorElemento);
    } else {
    printf("El arbol esta vacio.\n");
    }

    if (mayor(arbol, &mayorElemento)) {
    printf("El mayor elemento del arbol es: %d\n", mayorElemento);
    } else {
    printf("El arbol está vacio.\n");
    }
    
    if(predecesor(arbol, &prede)){
        printf("el predecesor del subarbol %d es %d\n",arbol->valor, prede );
    }else{
        printf("No hay un predecesor para el valor %d\n", arbol->valor);
    }
    freeArbol(arbol);
    return 0;
}