#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<stdbool.h>
/*
            TABLA DE ERRORES
    


*/
struct Nodo{
    int val; //Tipo de dato generico
    struct Nodo* nodoAnterior;
};

typedef struct{
    struct Nodo* cima;
    int cursor;
}Pila;

Pila* crearPila(int* error);
int apilar(Pila *p, int* error, struct Nodo dato);
void desapilar(Pila *p, int* error, struct Nodo *datoExtraido);
int consultarCima(Pila p, int error);
void vaciarPila(Pila *p, int *error);
bool isEmpty(Pila P, int* error);
