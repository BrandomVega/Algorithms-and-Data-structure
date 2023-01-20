#include "cola.h"

void main(){
    Cola micola;
    micola.final=0;
    micola.cabecera=0;
    Nodo dato;
    int e,i;
    for(i=0; i<TAM; i++){
        printf("\nIngrese el valor a encolar: ");
        fflush(stdin);
        scanf("%d",&dato.valor);
        encolar(&e, &micola, dato);
    }
    imprimirCola(&e, micola);
    destruirCola(&e, &micola);
    puts("\nFin del programa");
}