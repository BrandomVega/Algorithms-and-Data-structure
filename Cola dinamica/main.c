#include "cola.h"

void main(){
    int e,i;
    Cola cola = crearCola(&e);
    Dato miDato, datoBorrado;
    for(i=0; i<5; i++){
        printf("\nIngrese el dato a encolar: ");
        scanf("%d",&miDato.valor);
        encolar(&cola, &e, miDato);
    }
    imprimeCola(&cola, &e);
    for(i=0; i<5; i++){
        desencolar(&cola, &e, &datoBorrado);
        printf("El dato extraido es: %d", datoBorrado.valor);
    }
    imprimeCola(&cola, &e);
    borrarCola(&cola, &e);
}