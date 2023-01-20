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
    int valor;
}Dato;

struct Nodo{
    Dato dato;
    struct Nodo* siguiente;
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
//@param n  the position you want to insert
void insertarPorN(Lista* l, int* e,int n, Dato datoUsuario);

//@param datoExtraido is the struct where you want to save the deleted data
void extraerPorDerecha(Lista* l, int* e, Dato* datoExtraido);
void extraerPorIzq(Lista* l, int* e, Dato* datoExtraido);
void extraePorN(Lista* l, int* e, Dato* datoExtraido);

//@param l is the list passed as reference
//@param e error
void imprimeLista(Lista* l,int* e);

//@param e error
int getMaxN(Lista* l,int* e);




