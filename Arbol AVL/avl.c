#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a > b) ? a : b)

typedef struct{
    int dato;
    int altura;
} Dato;

typedef struct nodo{
    Dato datos;
    struct nodo *izq,*der;
} Elemento_De_Arbol_Binario;

typedef Elemento_De_Arbol_Binario* Arbol;

Arbol crearNodo(Dato valor){
    Arbol arbol=(Arbol) malloc(sizeof(Elemento_De_Arbol_Binario));
    if(arbol==NULL){
        perror("No hay memoria para tu nodo");
    } else{
        arbol->izq=arbol->der=NULL;
        arbol->datos=valor;
    }
    return arbol;
}

/**
 * @param raiz Nueva raiz con Hijo izquierdo e hijo derecho, con valorRaiz como clave
 * @param Hizq  Nodo que se coloca a la izquierda del nuevo nodo raiz, previamente creado o NULL
 * @param Hder Nodo ue se coloca a la derecha del nuevo nodo raiz, previamente creado o NULL
 */
void nuevoArbol(Arbol* raiz, Arbol Hizq, Arbol Hder, Dato valorRaiz){ 
    (*raiz)=crearNodo(valorRaiz);
    (*raiz)->der=Hder;
    (*raiz)->izq=Hizq;
}

int cuentaNodos(Arbol raiz){
    if(!raiz){
        return 0;
    } else{
        return (cuentaNodos(raiz->izq)+1+cuentaNodos(raiz->der));
    }
}


void preOrden(Arbol raiz){ 
    if(raiz){
		printf("valor:%c-altura:%d,",raiz->datos.dato, raiz->datos.altura);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void posOrden(Arbol raiz){ 
	if(raiz){
		posOrden(raiz->izq);
		posOrden(raiz->der);
		printf("valor:%c-altura:%d,",raiz->datos.dato, raiz->datos.altura);
	}
}

void inOrden(Arbol raiz){ 
	if(raiz){
		inOrden(raiz->izq);
		printf("valor:%c-altura:%d,",raiz->datos.dato, raiz->datos.altura);
		inOrden(raiz->der);
	}
}

void eliminarArbol(Arbol* raiz){ 
    if(*raiz){
        eliminarArbol(&((*raiz)->izq));
        eliminarArbol(&((*raiz)->der));
        free(*raiz);
		*raiz=NULL;
    }
}

void buscarNodo(Arbol raiz, Dato valor, Arbol* nodoEncontrado){ 
    if(raiz){
        if(raiz->datos.dato==valor.dato){
            *nodoEncontrado=raiz;       //Aqui se sobre escribe el valor nulo, por el valor encontrado.
        } else if(valor.dato>raiz->datos.dato){
            buscarNodo(raiz->der, valor, nodoEncontrado);
        } else{
            buscarNodo(raiz->izq, valor, nodoEncontrado);
        }
    } 
}

Arbol nodoMinimo(Arbol raiz) {
  Arbol actual = raiz;
  // Buscamos en todos los subarboles izquierdos
  while (actual && actual->izq != NULL)
    actual = actual->izq;
  return actual;
}

Arbol nodoMaximo(Arbol raiz) {
  Arbol actual = raiz;
  // Buscamos en todos los subarboles izquierdos
  while (actual && actual->der != NULL)
    actual = actual->der;
  return actual;
}

int altura(Arbol raiz){
    if(!raiz)
        return -1;
    else
        return(raiz->datos.altura);
}

Arbol rotacionIzq(Arbol raiz){
    Arbol q=raiz->izq;
    raiz->izq=q->der;
    q->der=raiz;
    raiz->datos.altura=max(altura(raiz->izq),altura(raiz->der))+1;
    q->datos.altura=max(altura(q->izq),raiz->datos.altura)+1;
    return q; //Esta es la nueva raiz en la rotación
}

Arbol rotacionDer(Arbol raiz){
    Arbol p=raiz->der;
    raiz->der=p->izq;
    p->izq=raiz;
    raiz->datos.altura=max(altura(raiz->izq),altura(raiz->der))+1;
    p->datos.altura=max(altura(p->der),raiz->datos.altura)+1;
    return p; //Esta es la nueva raiz en la rotación
}
//:OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO 
Arbol rotacionDerIzq(Arbol raiz){
    raiz->izq=rotacionDer(raiz->izq);
    return rotacionIzq(raiz);
}

Arbol rotacionIzqDer(Arbol raiz){
    raiz->der=rotacionIzq(raiz->der);
    return rotacionDer(raiz);
}

Arbol* insertar(Dato valorUsuario, Arbol raiz){
    if(!raiz){
        raiz=crearNodo(valorUsuario);
    } else if(valorUsuario.dato< raiz->datos.dato){
        raiz->izq=insertar(valorUsuario,raiz->izq);
        if(altura(raiz->izq)-altura(raiz->der)==2)
            if(valorUsuario.dato < raiz->izq->datos.dato)
                raiz=rotacionIzq(raiz);
            else
                raiz=rotacionDerIzq(raiz); 
    } else if(valorUsuario.dato>=raiz->datos.dato){
        raiz->der=insertar(valorUsuario,raiz->der);
        if(altura(raiz->der)-altura(raiz->izq)==2)
            if(valorUsuario.dato > raiz->der->datos.dato)
                raiz=rotacionDer(raiz);
            else
                raiz=rotacionIzqDer(raiz); 
    }
    raiz->datos.altura=max(altura(raiz->izq),altura(raiz->der))+1;
    return raiz;
}

void visualizarNodosPorNivel(int nivel, Arbol raiz){
    int i;
    if(raiz){
        visualizarNodosPorNivel(nivel+1, raiz->der);
        printf("\n");
        for(i=0; i<nivel; i++){
            printf("\t");
        }
        printf("%d", raiz->datos.dato);
        visualizarNodosPorNivel(nivel+1, raiz->izq);
    }
}