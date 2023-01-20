#include <stdio.h>
#include <stdbool.h>
#define TAM 10

/**
 *              Tabla de errores
 *      Variable    Estado      Significado
 *         error    -1          Elemento Null /Cima Null
 *         error    -2          Pila esta Llena
 *         error    -3          Pila esta vacia
 *         error    0           No hay errores / Todo Ok
 */
typedef struct{
    int valor;
}Nodo;

typedef struct{
    Nodo elementos[TAM];
    int cima;
}Pila;


//Pila* crearPILA(int* error);
void crearPILA(int* error, Pila *p);
int apilar(Pila *p, int* error, Nodo dato);
void desapilar(Pila *p, int* error, Nodo *datoExtraido);
int consultarCima(Pila p, int* error);
void vaciarPila(Pila *p, int* error);
bool isEmpty(Pila p, int* error);
bool isFull(Pila p, int* error);