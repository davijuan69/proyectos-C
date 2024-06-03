#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int elemento;
    struct nodo *sig;
}Nodo;

typedef struct pila
{
    Nodo *cabeza;
}Pila;

typedef struct cola
{
    Nodo *inicio;
    Nodo *fin;
}Cola;

Pila *nuevaPila()
{
    Pila *p;
    if ((p=(Pila *)malloc(sizeof(Pila)))==NULL)
    {
        exit(1);
    }
    p->cabeza = NULL;
    return p;
}

Cola * nuevaCola()
{
    Cola *c;
    if ((c = (Cola*)malloc(sizeof(Cola))) == NULL)
    {
        exit(1);
    }
    c->inicio = c->fin =NULL;
    return c;
}

int cima(Pila *p, int *valor)
{
    if (p && p->cabeza)
    {
        *valor = p->cabeza->elemento;
        return 1;
    }
    return 0;
}

int apilar(Pila *p, int valor)
{
    Nodo *nuevo;
    if (!p)
    {
        return 0;
    }
    if ((nuevo = (Nodo *) malloc (sizeof(Nodo))) == NULL)
    {
        return 0;
    }
    nuevo->sig=p->cabeza;
    nuevo->elemento = valor;
    p->cabeza=nuevo;
    return 1;
}

int encolar(Cola *c, int valor)
{
    Nodo *nuevo;
    if (!c)
    {
        return 0;
    }
    if ((nuevo = (Nodo*)malloc(sizeof(Nodo))) == NULL)
    {
        exit(1);
    }

    nuevo->sig=NULL;
    nuevo->elemento = valor;

    if (!c->inicio)
    {
        c->inicio = c->fin = nuevo;
    }
    else
    {
        c->fin->sig = nuevo;
        c->fin = nuevo;
    }
    return 1;
}

int desapilar(Pila *p, int *valor)
{
    if (p && p->cabeza && valor)
    {
        Nodo *aux = p->cabeza;
        p->cabeza =aux->sig;
        *valor = aux->elemento;
        free(aux);
        return(1);
    }
    return 0;
}

int vacia(Pila *p)
{
    if (!p||!p->cabeza)
    {
        return 1;
    }
    return 0;
}

void imprimirPila(Pila *p)
{
    Nodo *aux = p->cabeza;
    while (aux)
    {
        printf("%d\n", aux->elemento);
        aux = aux->sig;
    }
}

void imprimirInvertido(Pila *p)
{
    Cola *c = nuevaCola();
    int valor;

    while (!vacia(p))
    {
        desapilar(p, &valor);
        encolar(c, valor);
    }

    while (c->inicio)
    {
        desapilar(c, &valor);
        apilar(p, valor);
    }

    imprimirPila(p);
}

int main()
{
    Pila *p = nuevaPila();

    apilar(p,1);
    apilar(p,2);
    apilar(p,3);
    apilar(p,4);
    apilar(p,5);

    printf("Pila\n");
    imprimirPila(p);
    
    printf("Pila invertida\n");

    imprimirInvertido(p);

    return 0;

}