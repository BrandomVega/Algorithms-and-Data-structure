#include "lista1.h"

void main(){
    int e,i;
    Lista lista = crearLista(&e);
    Dato dato;
    Dato datoExtraido;
    int numCaracteres=5;
    for(i=0; i<numCaracteres; i++){
        printf("\nIngrese el caracter: ");
        fflush(stdin);
        scanf("%c",&dato.valor);
        insertarDerecha(&lista,&e,dato);
    }
    imprimeLista(&lista, &e);

    puts("ORDENANDO");
    ordenar(&lista);
    imprimeLista(&lista, &e);


    puts("FIN DEL PROGRAMA");   
}