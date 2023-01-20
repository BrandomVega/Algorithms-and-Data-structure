#include "pila.h"

void main(int argc, char** argv){
    int error;
    Pila p;
    crearPILA(&error,&p);
    Nodo datoUsuario;
    //Llenar la pila con datos de usuario
    while(!isFull(p,&error)){
        puts("\nIngresa un valor: ");
        fflush(stdin);
        scanf("%d",&datoUsuario);
        apilar(&p,&error,datoUsuario);
    }
    //que quedaria en la cima al finalizar el while? R=El ultimo valor ingresado por el usuario
    desapilar(&p,&error,&datoUsuario);
    printf("\nEl valor desapilado es %d", datoUsuario.valor); //se desapila el ultimo
    //libera todos los recursos
    vaciarPila(&p,&error);

}