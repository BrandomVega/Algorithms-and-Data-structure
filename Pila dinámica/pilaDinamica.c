#include "p.h"

void main(){
    int error;
    int i;
    int tamUsuario;
    Pila *pila = crearPila(&error);
    struct Nodo dato;
    puts("Numero de elementos a apilar");
    fflush(stdin);
    scanf("%d",&tamUsuario);

    for(i=0; i<tamUsuario; i++){
        puts("Ingresa un valor");
        fflush(stdin);
        scanf("%d", &dato.val);
        apilar(pila,&error,dato);
    }

    vaciarPila(pila,&error);
    printf("\nFin de este programa");

}