#include "lista1.h" 

Lista crearLista(int* e){
    Lista l = (Lista)malloc(sizeof(Elemento_Lista));
    if(l == NULL){
        *e=-1;
    }else{
        (*l).cabecera = NULL;
        *e=0;
        return l;
    }
}


void insertarDerecha(Lista* l, int* e, Dato datoUsuario){
    //puts("Ingresando por derecha");
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));

    if(nodoUsuario==NULL){
        puts("Can't add this struct");
        *e = -2;
    }else{
        nodoUsuario->dato = datoUsuario;

        if((*l)->cabecera == NULL){ //cuando la lista esta vacia
            //puts("Ingresando por derecha vacia");
            nodoUsuario->posicion = 0;
            nodoUsuario->anterior=NULL;
            nodoUsuario->siguiente=NULL;
            (*l)->cabecera=nodoUsuario;
            //puts("Nodo insertado der");

        }else{                      //cuando ya hay elementos
            struct Nodo* nodoAux = (*l)->cabecera;
            while(nodoAux->siguiente != NULL){
                nodoAux = nodoAux->siguiente;
            }
            nodoUsuario->anterior=nodoAux;
            nodoUsuario->siguiente=NULL;
            nodoAux->siguiente = nodoUsuario;
            nodoUsuario->posicion = nodoAux->posicion+1;
            

        }
    }
    //puts("Nodo insertado der");
}

//no olvidar el lnodo anterior pq crashea
void insertarIzquierda(Lista* l, int* e, Dato datoUsuario){
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));

    if(nodoUsuario==NULL){
        puts("Can't add this struct");
        *e = -2;
    }else{
        nodoUsuario->dato = datoUsuario;
        nodoUsuario->posicion=0;
        struct Nodo* aux = (*l)->cabecera;
        
        if(aux == NULL){
            nodoUsuario->anterior=NULL;
            nodoUsuario->siguiente=NULL;
            (*l)->cabecera=nodoUsuario;

        }else{
            //COMIENZA A AGREGAR POR LA IZQ
            nodoUsuario->anterior=NULL;
            nodoUsuario->siguiente = aux;
            aux->anterior = nodoUsuario;
            (*l)->cabecera = nodoUsuario;
            //ACTUALIZA POSICIONES
            aux = (*l)->cabecera;
            while(aux->siguiente!=NULL){
                aux=aux->siguiente;
                aux->posicion = aux->posicion+1;
            }

            
        }
        
    }
    puts("Nodo insertado izq");
}


void insertarN(Lista* l, int* e, int n,Dato datoUsuario){
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));

    if(nodoUsuario==NULL){
        puts("Can't add this struct");
        *e = -2;
    }else{
        
        struct Nodo* aux = (*l)->cabecera;
        while(aux->posicion != n){
            aux = aux->siguiente;
        }
        nodoUsuario->dato = datoUsuario;
        nodoUsuario->posicion = n;


        nodoUsuario->siguiente = aux;
        nodoUsuario->anterior = aux->anterior;



        aux->anterior->siguiente = nodoUsuario;
        aux->anterior = nodoUsuario;

        while(nodoUsuario->siguiente != NULL){
            nodoUsuario = nodoUsuario->siguiente;
            nodoUsuario->posicion = nodoUsuario->posicion+1;
        }
    }
}
//busqueda secuencial
bool buscar(Lista* l,Dato datoSearch){
    struct Nodo* aux = (*l)->cabecera;
    int i;
    int tam = contarNodos(l);
    for(i=0; i<tam; i++){
        if(aux->dato.valor == datoSearch.valor){
            printf("Se ha encontrado el valor %d en la posicion %d \n",datoSearch.valor, aux->posicion);
            return true;
        }else{
            aux = aux->siguiente;
        }
    }
    return false;

}


int contarNodos(Lista* l){
    int nodos=0;
    struct Nodo* aux = (*l)->cabecera;

    while(aux->siguiente!= NULL){
        nodos++;
        aux = aux->siguiente;
    }
    nodos++;
    printf("Num Nodos: %d \n",nodos);
    return nodos;
}

void imprimeLista(Lista* l,int* e){
    puts(" ");
    puts("IMPRIMIENDO");
    struct Nodo* nodoAux = (*l)->cabecera;
    
    if(nodoAux!=NULL){
        printf("Dato inicial: %c  - Pos: %d\n",nodoAux->dato.valor,nodoAux->posicion);
        //printf("\nEntra a agregar por izq/der/n \n\n");
        while(nodoAux->siguiente != NULL){
            nodoAux = nodoAux->siguiente;
            printf("Dato siguiente: %c - pos: %d\n",nodoAux->dato.valor, nodoAux->posicion);
        }
    }
    else{
        puts("No se pudo imprimir la lista");
        *e=-2;
    }
}

void extraerDerecha(Lista* l, int* e, Dato extraido){
    struct Nodo* aux = (*l)->cabecera;
    while(aux->siguiente != NULL){
        aux = aux->siguiente;
    }
    extraido = aux->dato;
    imprimeNodo(aux);
    aux->anterior->siguiente = NULL;
    aux->siguiente = NULL;
    aux->anterior = NULL;

}

void extraerIzquierda(Lista* l, int* e, Dato extraido){
    struct Nodo* aux = (*l)->cabecera;
    extraido = aux->dato;
    imprimeNodo(aux);
    (*l)->cabecera = aux->siguiente;
    aux = (*l)->cabecera;
    aux->anterior->siguiente = NULL;
    aux->anterior = NULL;
    aux = (*l)->cabecera;
    while(aux->siguiente!=NULL){
        aux->posicion = aux->posicion - 1;
        aux = aux->siguiente;
    }
    aux->posicion = aux->posicion - 1;

}

void extraerN(Lista* l, int* e, int n, Dato extraido){
    struct Nodo* aux = (*l)->cabecera;
    struct Nodo* anterior;
    while(aux->posicion!=n){
        aux = aux->siguiente;
    }
    extraido = aux->dato;
    imprimeNodo(aux);
    anterior = aux->anterior;
    anterior->siguiente = aux->siguiente;
    aux->siguiente->anterior = anterior;
    aux->anterior=NULL;
    aux->siguiente=NULL;
    
    aux=anterior->siguiente;
    aux->posicion = aux->posicion - 1;
    while(aux->siguiente != NULL){
        aux = aux->siguiente;
        aux->posicion = aux->posicion - 1;
    }
}

void imprimeNodo(struct Nodo* nodo){
    printf("Nodo--- valor:%d posicion:%d\n", nodo->dato.valor, nodo->posicion);
}

void eliminarLista(Lista* l, int* e, Dato extraido){
   
    (*l)->cabecera->posicion = 0;
    (*l)->cabecera->siguiente = NULL;
    (*l)->cabecera->anterior = NULL;
    (*l)->cabecera = NULL;
    free(l);
    puts("Lista eliminada");

}

//PENDIENTE: ANALIZAR CODIGO BUBBLE SORT
/* Bubble sort the given linked list */
void ordenar(Lista *l){
    int swapped, i;
    struct Nodo *ptr1;
    struct Nodo *lptr = NULL;
  
    /* Checking for empty list */
    if (l == NULL)
        return;
    do{
        swapped = 0;
        ptr1 = (*l)->cabecera;
  
        while (ptr1->siguiente != lptr){
            if (ptr1->dato.valor > ptr1->siguiente->dato.valor){ 
                swap(ptr1, ptr1->siguiente);
                swapped = 1;
            }
            ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  
/* function to swap data of two nodes a and b*/
void swap(struct Nodo *a, struct Nodo *b){
    int temp = a->dato.valor;
    a->dato.valor = b->dato.valor;
    b->dato.valor = temp;
}