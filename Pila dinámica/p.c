#include "p.h"

Pila* crearPila(int *error){
    Pila *p = (Pila*)malloc(sizeof(Pila));
    if(p == NULL){
        *error = -1;
        perror("No hay espacio para crear la pila");
        exit(-1);
    }

    p->cima = NULL;
    p->cursor = 0;
    *error = 0;
    return p;
}

int apilar(Pila *p, int* error, struct Nodo dato){
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodoUsuario == NULL){
        *error = -1;
        perror("No hay espacio para un nuevo elemento, elimine alguno de la pila");
    }else{
        //Asigna los datos de parametro a los datos de la pila
        nodoUsuario->val = dato.val;
        nodoUsuario->nodoAnterior = p->cima;
        p->cima = nodoUsuario;
        p->cursor++;
        *error = 0;
        return 0;
    }
}

void desapilar(Pila *p, int* error, struct Nodo *datoExtraido){
    if(!isEmpty(*p, error)){
        struct Nodo* aux = p->cima; //apuntador creado para apuntar a la cima(ultimo nodo existente)
        p->cima = aux->nodoAnterior;    //la cima apunta al penultimo nodo, pero aux guardo el ultimo
        aux->nodoAnterior = NULL;   
        p->cursor--;
        datoExtraido->val = aux->val;
        *error = 0;
        free(aux);
    }else{
        perror("La cima ya no contiene elementos");
        *error = -3;
    }
}

void vaciarPila(Pila *p, int *error){
    struct Nodo valorExtraido;
    while(!isEmpty(*p, error)){
        desapilar(p,error,&valorExtraido);
        printf("\nEl valor extraido es: %d", valorExtraido.val);
        *error=0;
    }
    printf("\nLa pila ha sido vaciada");
}

bool isEmpty(Pila P, int* error){
    if(P.cima == NULL){
        *error = -3;
        return true;
    }else{
        *error = 0;
        return false;
    }
}
