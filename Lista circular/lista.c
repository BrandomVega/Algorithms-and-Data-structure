#include "lista.h" 

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


        if((*l)->cabecera == NULL){ //cuando la lista esta vacia
            nodoUsuario->posicion = 0; 
            nodoUsuario->siguiente = nodoUsuario;
            (*l)->cabecera=nodoUsuario;

        }else{                      //cuando ya hay elementos
            struct Nodo* nodoAux = (*l)->cabecera;
            do{
                nodoAux = nodoAux->siguiente;
            } while (nodoAux->siguiente != (*l)->cabecera);
            nodoUsuario->siguiente = (*l)->cabecera;
            nodoUsuario->posicion = nodoAux->posicion + 1;
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
            nodoUsuario->posicion = 0; 
            nodoUsuario->siguiente = nodoUsuario;
            (*l)->cabecera=nodoUsuario;

        }else{                      //cuando ya hay elementos
            struct Nodo* nodoAux = (*l)->cabecera;
            do{
                nodoAux = nodoAux->siguiente;
            } while (nodoAux->siguiente != (*l)->cabecera);
            nodoAux->siguiente = nodoUsuario;
            nodoUsuario->siguiente = (*l)->cabecera;
            nodoUsuario->posicion = 0;
            (*l)->cabecera = nodoUsuario;
            
            nodoAux = (*l)->cabecera;
            do{
                nodoAux = nodoAux->siguiente;
                nodoAux->posicion = nodoAux->posicion+1;
            } while (nodoAux->siguiente != (*l)->cabecera);

        }
    }
}



void extraerPorIzq(Lista* l, int* e, Dato* datoExtraido){
    struct Nodo* aux = (*l)->cabecera;
    *datoExtraido = aux->dato;

    if((*l)->cabecera == NULL){
        puts("Lista Vacia");
    }else if((*l)->cabecera == (*l)->cabecera->siguiente){
        puts("Ultimo elemento");
        free((*l)->cabecera);
    }
    else{
        do{
            aux = aux->siguiente;
        } while (aux->siguiente != (*l)->cabecera);

        aux->siguiente = (*l)->cabecera->siguiente;
        aux = (*l)->cabecera;
        (*l)->cabecera = (*l)->cabecera->siguiente;
        aux->siguiente = NULL;

        aux = (*l)->cabecera;
        do{
            aux->posicion = aux->posicion-1;
            aux = aux->siguiente;
        } while (aux->siguiente != (*l)->cabecera);
    }

}
void extraerPorDerecha(Lista* l, int* e, Dato* datoExtraido){
    struct Nodo* aux = (*l)->cabecera;
    

    if((*l)->cabecera == NULL){
        puts("Lista Vacia");
    }else if((*l)->cabecera == (*l)->cabecera->siguiente){
        puts("Ultimo elemento");
        free((*l)->cabecera);
    }
    else{
        struct Nodo* anterior  = (*l)->cabecera;
        do{
            aux = aux->siguiente;
        } while (aux->siguiente != (*l)->cabecera);
        *datoExtraido = aux->dato;
        do{
            anterior = anterior->siguiente;
        } while (anterior->siguiente != aux);
        aux->siguiente=NULL;
        anterior->siguiente = (*l)->cabecera;
        
    }
}


void imprimeLista(Lista* l,int* e){
    puts(" ");
    puts("IMPRIMIENDO");
    struct Nodo* nodoAux = (struct Nodo*)malloc(sizeof(struct Nodo));
    
    if(nodoAux!=NULL){

        struct Nodo *nodoAux = (*l)->cabecera;
        do{
            printf("Dato: %d Pos: %d\n", nodoAux->dato.valor, nodoAux->posicion);
            nodoAux = nodoAux->siguiente;
        }while (nodoAux->siguiente != (*l)->cabecera);
        printf("Dato: %d Pos: %d\n", nodoAux->dato.valor, nodoAux->posicion);


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

