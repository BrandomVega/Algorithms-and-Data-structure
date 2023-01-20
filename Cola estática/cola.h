#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define TAM 5


typedef struct{
    int valor;
}Nodo;

typedef struct{
    Nodo elementos[TAM];
    int cabecera;
    int final;
}Cola;

void encolar(int *e, Cola *cola, Nodo dato);
void desencolar(int *e, Cola *cola, Nodo* datoExtraido);
bool isFull(int *e, Cola cola);
bool isEmpty(int *e, Cola cola);
void destruirCola(int* e, Cola* cola);
void imprimirCola(int* e, Cola cola);