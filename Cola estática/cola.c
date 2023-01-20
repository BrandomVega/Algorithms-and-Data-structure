#include "cola.h"

void encolar(int *e, Cola *cola, Nodo dato){
    if(!isFull(e,*cola)){
        cola->elementos[cola->final].valor = dato.valor;
        cola->final++;
        *e=0;
    }else{
        *e=-1;
    }   
}
void desencolar(int *e, Cola *cola, Nodo* datoExtraido){
    if(!isEmpty(e,*cola)){
        *datoExtraido = cola->elementos[cola->cabecera];
        printf("\nDato %d", datoExtraido->valor);
        cola->cabecera++;
        *e=0;
    }else{
        *e=-1;
    }
}
bool isFull(int *e, Cola cola){
    if(cola.final == TAM-1){
        *e = -1;
        return true;
    }else{
        *e=0;
        return false;
    }
}
bool isEmpty(int *e, Cola cola){
    if(cola.cabecera==0 && cola.final==0){ //cuando recien se crea la cola
        *e=-1;
        return true;
    }else if(cola.cabecera>=cola.final){ //aun hay espacio
        *e=-1;
        return true;
    }else{
        *e=0;
        return false;
    }
}
void destruirCola(int* e, Cola* cola){
    cola->cabecera=0;
    cola->final=0;
    printf("\nLa cola ha sido eliminada exitosamente");
}
void imprimirCola(int* e, Cola cola){
    Nodo datoBorrado;
    while(!isEmpty(e, cola)){
        desencolar(e, &cola, &datoBorrado);
    }

}