#include "cola.h"

Cola crearCola(int *e){
    Cola cola = (Cola)malloc(sizeof(Elemento_cola)); //elemento cola es la cola sin el apuntador
    if(cola == NULL){
        *e=-4;
        puts("No se logro almacenar la cola");
    }
    cola->cabecera = NULL; 
    cola->final = NULL;
    cola->cursor = 0;
    *e=0;
    return cola;
}

//Insertar elemento a cola por el final
void encolar(Cola *cola, int* e, Dato datoIngreso){
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodoUsuario == NULL){
        *e=-6;
        puts("La memoria para el dato a ingresar está llena. Libera dato de la cola");
    }else if(estaVacia(*cola, e)){ //caso cuando recien se crea la cola y no hay elementos
        nodoUsuario->dato = datoIngreso;
        nodoUsuario->siguiente = NULL;
        (*cola)->cabecera = nodoUsuario;
        (*cola)->final=nodoUsuario;
    }else{ //caso donde ya hay elementos en la cola
        nodoUsuario->dato = datoIngreso;
        nodoUsuario->siguiente = NULL;
        (*cola)->final->siguiente = nodoUsuario;
        (*cola)->final = nodoUsuario;
    }
    (*cola)->cursor++;
    *e=0;
}

//Eliminar dato por la cabecera
void desencolar(Cola* cola, int* e, Dato *datoExtraido){
    printf("\nEn proceso de desencolado...\n");
    struct Nodo* nodoAuxiliar=(struct Nodo*)malloc(sizeof(struct Nodo));

    if(estaVacia(*cola,e)){
        *e=-1;
        puts("La cola esta vacia, no es posible leer un elemento\n");
    } else if((*cola)->cursor>1){ //cuando tiene elementos
        nodoAuxiliar->siguiente = NULL;
        nodoAuxiliar=(*cola)->cabecera;
        (*cola)->cabecera=(*cola)->cabecera->siguiente;
    } else if((*cola)->cursor==1){ //cuando es el ultimo elemento
        nodoAuxiliar=(*cola)->cabecera;
        (*cola)->cabecera=NULL;
        (*cola)->final=NULL;
    }
    (*cola)->cursor--;
    *datoExtraido=nodoAuxiliar->dato;
    free(nodoAuxiliar); //se ha liberado las conexiones y los datos
    *e=0;
}

bool estaVacia(Cola cola,int *e){
    if(cola->cabecera == NULL && cola->final== NULL && cola->cursor == 0){
        *e=-1;
        return true;
    }else{
        *e=0;
        return false;
    }
}


void borrarCola(Cola* cola, int *e){
    if(!estaVacia(*cola, e)){
        struct Nodo* nodoAuxiliar, *nodoAuxiliarRespaldo;
        nodoAuxiliar = (*cola)->cabecera;
        while(nodoAuxiliar != NULL){
            nodoAuxiliarRespaldo = nodoAuxiliar->siguiente;
            free(nodoAuxiliar);
            nodoAuxiliar=nodoAuxiliarRespaldo;
        }
        (*cola)->cabecera = NULL;
        (*cola)->final = NULL;
        (*cola)->cursor = 0;
        *e=0;
        free(*cola);
        printf("\nLa cola ha sido eliminada correctamente");
    }else{
        printf("\nLa cola ya esta vacia");
    }
}

void imprimeCola(Cola* cola, int* e){
    struct Nodo* nodoAuxiliar, *nodoAuxiliarRespaldo;
    nodoAuxiliar = (*cola)->cabecera;
    while(nodoAuxiliar != NULL){
        printf("\nvalor: %d",nodoAuxiliar->dato.valor);
        nodoAuxiliar=nodoAuxiliar->siguiente;
    }
    free(nodoAuxiliar);
}



