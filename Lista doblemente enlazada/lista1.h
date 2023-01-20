#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*
    LISTA DE ERRORES
    -1 = No se pudo crear la lista
    -2 = NO se pudo agregar la estrcutra error en memoria
*/


typedef struct{
    char valor;
}Dato;

struct Nodo{
    Dato dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
    int posicion;
};

typedef struct{
    int cursor;
    struct Nodo* cabecera;
}Elemento_Lista;

typedef Elemento_Lista* Lista;



//OPERACIONES TDA

//This function set dynamic memory and set the initial values
//@param e error
Lista crearLista(int* e);
//@param l is the list passed as reference
//@param e error
//@param datoUsuario is the struct you want to insert
void insertarDerecha(Lista* l, int* e, Dato datoUsuario);
void insertarIzquierda(Lista* l, int* e, Dato datoUsuario);
void insertarN(Lista* l, int* e, int n,Dato datoUsuario);

//@param l is the list passed as reference
//@param e error
void imprimeLista(Lista* l,int* e);
//@param l is the list passed as reference
//@param e error
bool buscar(Lista* l,Dato datoSearch);
int contarNodos(Lista* l);
//@param l is the list passed as reference
//@param e error
void imprimeNodo(struct Nodo* nodo);
//@param l is the list passed as reference
//@param e error
//@param datoUsuario is the struct you want to insert
void extraerDerecha(Lista* l, int* e, Dato extraido);
void extraerIzquierda(Lista* l, int* e, Dato extraido);
void extraerN(Lista* l, int* e, int n, Dato extraido);
//@param l is the list passed as reference
//@param e error
void eliminarLista(Lista* l, int* e, Dato extraido);

void ordenar(Lista* l);
void swap(struct Nodo *a, struct Nodo *b);





