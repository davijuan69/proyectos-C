#include <stdio.h>
#include <stdlib.h>

/*
Dada una lista de enteros doblemente enlazada, escriba e implemente
una función en C, que elimine los consecutivos duplicados. Por ejemplo:
(1,1,1,2,3,3,1,1,4,5,5,5,5) da como resultado (1,2,3,1,4,5)
*/

typedef struct nodo{
   int valor;
   struct nodo* sig;
   struct nodO* ant;
   
}Nodo;

typedef Nodo* Tp;

typedef struct TP{
    Tp primer;
    Tp ulti;
}TP;

void print_list(TP *L) {
    Tp current = L->primer;
    while (current != NULL) {
        printf("%d ", current->valor);
        current = current->sig;
    }
    printf("\n");
}

void agregar_final(TP *L, int valor) {
    Tp nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->sig = NULL;

    if (L->primer == NULL) {
        nuevoNodo->ant = NULL;
        L->primer = nuevoNodo;
        L->ulti = nuevoNodo;
    } else {
        nuevoNodo->ant = L->ulti;
        L->ulti->sig = nuevoNodo;
        L->ulti = nuevoNodo;
    }
}


void remove_consecutive(TP *L)
{
    Tp current = L->primer;
    Tp sig = current->sig;
    while (sig != NULL)
    {
        if (current->valor == sig->valor)
        {
            Tp temp = sig->sig;
            if (temp != NULL)
            {
                temp->ant = current;
            }
            else
            {
                L->ulti = current;
            }
            free(sig);
            current->sig = temp;
            sig = temp;
        }
        else
        {
            current = sig;
            sig = sig->sig;
        }
    }
}






int main(){
    TP* L = malloc(sizeof(TP));
    L->primer = NULL;
    L->ulti = NULL;

    agregar_final(L, 1);
    agregar_final(L, 1);
    agregar_final(L, 2);
    agregar_final(L, 3);
    agregar_final(L, 3);
    agregar_final(L, 1);
    agregar_final(L, 1);
    agregar_final(L, 4);
    agregar_final(L, 5);
    agregar_final(L, 5);
    agregar_final(L, 5);
    agregar_final(L, 5);

    printf("Antes de eliminar duplicados consecutivos:\n");
    print_list(L);

    remove_consecutive(L);

    printf("Después de eliminar duplicados consecutivos:\n");
    print_list(L);

    return 0; 
}