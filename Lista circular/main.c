#include "lista.h"

void main(){
    int e;
    Lista lista = crearLista(&e);
    Dato dato;
    Dato datoExtraido;

    dato.valor = 21;
    insertarDerecha(&lista, &e, dato);
    dato.valor = 23;
    insertarDerecha(&lista, &e, dato);
    dato.valor = 2;
    insertarDerecha(&lista, &e, dato);
    dato.valor = 12;
    insertarIzquierda(&lista, &e, dato);
    dato.valor = 1442;
    insertarIzquierda(&lista, &e, dato);

    imprimeLista(&lista,&e);

    extraerPorIzq(&lista, &e, &datoExtraido);
    imprimeLista(&lista,&e);
    extraerPorDerecha(&lista, &e, &datoExtraido);
    imprimeLista(&lista,&e);

    puts("FIN DEL PROGRAMA");   
}