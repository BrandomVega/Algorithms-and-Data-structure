#include "pila.h"
/*
Pila* crearPILA(int* error){
    Pila pila;
    pila.cima=-1; //Se coloca en NULL
    *error = 0;
    return &pila;
}*/

void crearPILA(int* error, Pila *p){
    p->cima=-1; //Se coloca en NULL
    *error = 0;
}

int apilar(Pila *p, int* error, Nodo dato){
    if(!isFull(*p, error)){
        p->cima++;
        p->elementos[p->cima] = dato;
        *error = 0;
        //puts("Apilado correctamente");
    } else{
        *error=-2;
    }
}

void desapilar(Pila *p, int* error, Nodo *datoExtraido){
    if(!isEmpty(*p, error)){
        *datoExtraido = p->elementos[p->cima];
        p->cima--;
        *error = 0;
    } else{
        *error=-3;
    }
}

int consultarCima(Pila p, int* error){
    if(!isEmpty(p,error) && *error==0){
        printf("\nEl valor de la cima es: %d",p.elementos[p.cima]);
        *error = 0;
    }else{
        puts("No hay elementos en la cima");
        *error = -3;
    }
}
void vaciarPila(Pila *p, int* error){
    Nodo aux;
    printf("\nVaciando Pila");
    while(!isEmpty(*p,error) && *error==0){
        desapilar(p,error,&aux);
        printf("\nElemento extraido: %d",aux.valor);
    }
    *error=0;
}

bool isEmpty(Pila p, int* error){
    if(p.cima == -1){
        *error = -3;
        return true;
    }else{
        *error=0;
        return false;
    }
}

bool isFull(Pila p, int* error){
    if(p.cima == TAM-1){
        *error = -2;
        return true;
    }else{
        *error=0;
        return false;
    }
}