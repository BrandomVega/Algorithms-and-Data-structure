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
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        puts("Can't add this struct");
        *e = -2;
    }else{   
        nodoUsuario->dato = datoUsuario;
        nodoUsuario->siguiente = NULL;

        if((*l)->cabecera == NULL){ //cuando la lista esta vacia
            nodoUsuario->posicion = 0;
            (*l)->cabecera=nodoUsuario;

        }else{                      //cuando ya hay elementos
            struct Nodo* nodoAux = (*l)->cabecera;
            int posAux;
            while(nodoAux->siguiente != NULL){
                nodoAux = nodoAux->siguiente;
            }

            posAux = nodoAux->posicion;
            posAux++;
            nodoUsuario->posicion = posAux;
            nodoAux->siguiente = nodoUsuario;

        }
    }
}


void insertarIzquierda(Lista* l, int* e, Dato datoUsuario){
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        puts("Can't add this struct");
        *e = -2;
    }else{
        nodoUsuario->dato = datoUsuario;

        if((*l)->cabecera == NULL){ //cuando la lista esta vacia
            nodoUsuario->siguiente = NULL;
            nodoUsuario->posicion = 0;
            (*l)->cabecera=nodoUsuario;

            nodoUsuario = NULL;
            free(nodoUsuario);
        }else{                      //cuando ya hay elementos   
            int posicion;
            nodoUsuario->posicion = (*l)->cabecera->posicion; //valdra cero
            nodoUsuario->siguiente = (*l)->cabecera;
            //recorremos las posiciones de la lista
            struct Nodo* nodoAux = (struct Nodo*)malloc(sizeof(struct Nodo));
            nodoAux = (*l)->cabecera;
            while(nodoAux->siguiente != NULL){
                posicion = nodoAux->posicion;
                posicion++;
                nodoAux->posicion = posicion;
                nodoAux = nodoAux->siguiente;
            }
            posicion++;
            nodoAux->posicion = posicion;
            
            
            (*l)->cabecera = nodoUsuario;
            nodoAux = NULL; 
            free(nodoAux);
        }
    }
}




void imprimeLista(Lista* l,int* e){
    puts(" ");
    puts("IMPRIMIENDO");
    struct Nodo* nodoAux = (struct Nodo*)malloc(sizeof(struct Nodo));
    
    if(nodoAux!=NULL){
        nodoAux = (*l)->cabecera;
        printf("Dato inicial: %d  - Pos: %d\n",nodoAux->dato.valor,nodoAux->posicion);
        //printf("\nEntra a agregar por izq/der/n \n\n");
        while(nodoAux->siguiente != NULL){
            nodoAux = nodoAux->siguiente;
            printf("Dato siguiente: %d - pos: %d\n",nodoAux->dato.valor, nodoAux->posicion);
        }
        nodoAux = NULL; //liberamos esta estructura sin borrar toda la lista
        free(nodoAux);
    }
    else{
        puts("No se pudo imprimir la lista");
        *e=-2;
    }
}

void insertarPorN(Lista* l, int* e,int n, Dato datoUsuario){
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    int max = getMaxN(l,e);
    int posicion;
    if(n>0 && n<max){
        nodoUsuario->dato = datoUsuario;
        nodoUsuario->siguiente = NULL;
        nodoUsuario->posicion = n;
        //encuentra el nodo anterior a
        struct Nodo* anterior = (struct Nodo*)malloc(sizeof(struct Nodo));
        anterior = (*l)->cabecera;
        while(anterior->posicion < n-1){
            anterior = anterior->siguiente;
        }

        //Encuentra el nodo en que se encuetra n
        struct Nodo* actual = (struct Nodo*)malloc(sizeof(struct Nodo));
        actual = (*l)->cabecera;
        while(actual->posicion < n){
            actual = actual->siguiente;
        }

        anterior->siguiente = nodoUsuario;
        nodoUsuario->siguiente = actual;

        //Actualiza posiciones        
        while(actual->siguiente !=NULL){
            posicion = actual->posicion;
            posicion++;
            actual->posicion = posicion;
            actual = actual->siguiente;
        }
        posicion++;
        actual->posicion = posicion;
        
        //libera memoria
        anterior = NULL;
        free(anterior);
        actual = NULL;
        free(actual);
    }else if((*l)->cabecera == NULL){
        nodoUsuario->posicion = 0;
        (*l)->cabecera=nodoUsuario;
        nodoUsuario->siguiente = NULL;
    }else{
        puts("Inserte por derecha/izq 🤔");
    }
}

void extraerPorDerecha(Lista* l, int* e, Dato* datoExtraido){
    if((*l)->cabecera==NULL){
        puts("Ya no hay elementos");
    }else{
        struct Nodo* nodoAux = (struct Nodo*)malloc(sizeof(struct Nodo));
        nodoAux = (*l)->cabecera;
        while(nodoAux->siguiente->siguiente != NULL){
            nodoAux = nodoAux->siguiente;
        }
        *datoExtraido = nodoAux->siguiente->dato;
        printf("Dato extraido: %d\n", datoExtraido->valor);
        nodoAux->siguiente = NULL;
        nodoAux = NULL;
        free(nodoAux);
    }
}

void extraerPorIzq(Lista* l, int* e, Dato* datoExtraido){
    if((*l)->cabecera==NULL){
        puts("Ya no hay elementos");
    }else{
        int posicion;
        struct Nodo *nodoAux = (struct Nodo *)malloc(sizeof(struct Nodo));
        nodoAux = (*l)->cabecera;
        // Actualiza posiciones
        while (nodoAux->siguiente != NULL){
            posicion = nodoAux->posicion;
            posicion--;
            nodoAux->posicion = posicion;
            nodoAux = nodoAux->siguiente;
        }
        posicion++;
        nodoAux->posicion = posicion;

        nodoAux = (*l)->cabecera;
        (*l)->cabecera = (*l)->cabecera->siguiente;
        *datoExtraido = nodoAux->dato;
        printf("Dato extraido: %d\n", datoExtraido->valor);
        nodoAux = NULL;
        free(nodoAux);
    }
}

void extraePorN(Lista* l, int* e, int n,Dato* datoExtraido){
    int max = getMaxN(l,e);
    if((*l)->cabecera==NULL){
        puts("Ya no hay elementos");
    }else if(n>0 && n<max){
        puts("Extrae por izq/der");
    }else{
        
    }
    
}


int getMaxN(Lista* l,int* e){
    int N=0;
    struct Nodo* nodoAux = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodoAux = (*l)->cabecera;
    while(nodoAux->siguiente != NULL){
        nodoAux = nodoAux->siguiente;
        N++;
    }
    nodoAux = NULL; //liberamos esta estructura sin borrar toda la lista
    free(nodoAux);
    return N;
}

