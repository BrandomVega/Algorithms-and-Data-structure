#include "lista1.h"

void main(){
    int e;
    Lista lista = crearLista(&e);
    Dato dato;
    Dato datoExtraido;

    dato.valor = 1;
    insertarDerecha(&lista, &e, dato);
    dato.valor = 2;
    insertarDerecha(&lista, &e, dato);
    dato.valor = 3;
    insertarDerecha(&lista, &e, dato);
    dato.valor = 123;
    insertarDerecha(&lista, &e, dato);
    puts(" ");
    puts(" ");
    imprimeLista(&lista, &e);
    dato.valor = 0;
    insertarIzquierda(&lista, &e, dato);
    dato.valor = -1;
    insertarIzquierda(&lista, &e, dato);
    imprimeLista(&lista, &e);


    int posmax = getMaxN(&lista, &e);
    printf("La posicion maxima es: %d (contando el cero como valor inicial)\n", posmax);

    dato.valor = 555555;
    insertarPorN(&lista, &e, 1, dato);
    imprimeLista(&lista, &e);
    puts("EXTRAYENDO DER");
    extraerPorDerecha(&lista, &e, &datoExtraido);
    imprimeLista(&lista, &e);
    puts("EXTRAYENDO IZQ");
    extraerPorIzq(&lista, &e, &datoExtraido);
    imprimeLista(&lista, &e);

    puts("FIN DEL PROGRAMA");   
}