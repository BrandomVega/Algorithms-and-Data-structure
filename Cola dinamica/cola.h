#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    |Variable   | Estado    | Significado
        error       0           Sin errores (todo resultado es exitoso)
        error      -1           Error, COLA vacía
        error      -4           Inexistencia de la COLA, o esta apunta a NULL
        error      -5           Inexistencia de dato en la estructura 
        error      -6           Nodo inicial nulo
*/


typedef struct{
    int valor;
}Dato;

struct Nodo{
    Dato dato;
    struct Nodo* siguiente;
};

typedef struct {
    int cursor; 
    struct Nodo* cabecera;
    struct Nodo* final;
}Elemento_cola;

typedef Elemento_cola* Cola;

Cola crearCola(int *e);
void encolar(Cola *cola, int* e, Dato datoIngreso);
void desencolar(Cola* cola, int* e, Dato *datoExtraido);
// Devuelve un true o un false si la cola contiene o no Nodos:
bool estaVacia(Cola cola,int *e);
void borrarCola(Cola* cola, int *e);
void imprimeCola(Cola* cola, int* e);
