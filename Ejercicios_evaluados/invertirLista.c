#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    int valor;
    struct nodo* sig;
} Nodo;

typedef Nodo* Lista;



Nodo* agregar_inicio(Nodo* cabeza, int valor) {
    Nodo* nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->sig = cabeza;
    return nuevoNodo;
}

Nodo* invertir_recursivo(Nodo* nodo) {
    if (nodo == NULL || nodo->sig == NULL) {
        return nodo;
    }
    Nodo* resto = invertir_recursivo(nodo->sig);
    nodo->sig->sig = nodo;
    nodo->sig = NULL;
    return resto;
}

Nodo* invertir_iterativo(Nodo* nodo) {
    Nodo* previo = NULL;
    Nodo* actual = nodo;
    Nodo* siguiente = NULL;
    while (actual != NULL) {
        siguiente = actual->sig;
        actual->sig = previo;
        previo = actual;
        actual = siguiente;
    }
    return previo;
}

void print_list(Nodo* cabeza) {
    Nodo* current = cabeza;
    while (current != NULL) {
        printf("%d ", current->valor);
        current = current->sig;
    }
    printf("\n");
}

int main() {
    Nodo* cabeza = NULL;

    cabeza = agregar_inicio(cabeza, 1);
    cabeza = agregar_inicio(cabeza, 2);
    cabeza = agregar_inicio(cabeza, 3);
    cabeza = agregar_inicio(cabeza, 4);
    cabeza = agregar_inicio(cabeza, 5);

    printf("Lista original:\n");
    print_list(cabeza);

    cabeza = invertir_recursivo(cabeza);

    printf("Lista invertida (recursiva):\n");
    print_list(cabeza);

    cabeza = invertir_iterativo(cabeza);

    printf("Lista invertida (iterativa):\n");
    print_list(cabeza);

    return 0;
}