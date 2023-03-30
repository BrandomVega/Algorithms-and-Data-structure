#include "TDA.h"

Casa crearTDA(Puerta* puertas, Ventana* ventanas, uint8_t cantidadPisos){
    Casa casa;
    casa.cantidadNiveles=cantidadPisos;
    int indice;
    for(indice=0; indice<TAM;indice++){
        casa.puertas[indice]=*(puertas+indice);
        casa.ventanas[indice]=ventanas[indice];
    }
}

void imprimeTDA(Casa miCasa){
    int indice;
    for(indice=0; indice<TAM;indice++){
        printf("Las caracteristicas de la puerta %d son: altura=%d y ancho=%d.\n",indice, miCasa.puertas[indice].altura, miCasa.puertas[indice].ancho);
        printf("Las caracteristicas de la ventana %d son: altura=%d y ancho=%d.\n",indice, miCasa.ventanas[indice].altura, miCasa.ventanas[indice].ancho);
    }
    printf("La cantidad de niveles de la casa: %d\n", miCasa.cantidadNiveles);
}

void updateVentanasTDA(Casa* miCasa, Ventana ventana, int posVentana){
    (*miCasa).ventanas[posVentana]=ventana;
}

void ingresaPuertaTDA(Casa* miCasa, Puerta puerta, int posPuerta){
    printf("Se reciben los siguientes datos de la puerta : ancho=%"PRIu16"\n\n",  puerta.ancho);
    miCasa->puertas[posPuerta]=puerta;
}

void ingresaVentanaTDA(Casa* miCasa, Ventana ventana, int posVentana){
    miCasa->ventanas[posVentana]=ventana;
}

void crearArregloTDA(Casa* casas, Casa miCasa, Casa miCasa2){
    casas[0]=miCasa;
    casas[1]=miCasa2;
}

void inicioOperacion(int argc, char** argv){
    int opcionUsuario;
    uint16_t anchoPuerta, altoPuerta;
    int numeroCasa;
    int contadorPuertas[2]={0};
     int contadorVentanas[2]={0};
    Puerta puerta;
    Ventana ventana;
    Casa casa1, casa2;
    Casa casas[2];
    crearArregloTDA(casas,casa1, casa2);
    do{
        puts("Por favor eliga una opcion:");
        puts("1.- Crear una puerta e ingresarla a la Estructura Casa determinada");
        puts("2.- Crear una ventana e ingresarla a la Estructura Casa determinada");
        puts("3.- Imprimir el contenido de las Casas");
        puts("4.- Salir del programa");
        fflush(stdin);
        scanf("%d", &opcionUsuario);
        switch (opcionUsuario){
            case 1:
                puts("ingresa la altura de la puerta");
                fflush(stdin);
                scanf("%d", &puerta.altura);
                puts("ingresa el ancho de la puerta");
                fflush(stdin);
                scanf("%d", &puerta.ancho);
                puts("ingresa el numero de casa donde se guardara la puerta");
                fflush(stdin);
                scanf("%d", &numeroCasa);
                printf("Las caracteristicas de la puerta son: altura=%d y ancho=%d.\n",puerta.altura, puerta.ancho);
                ingresaPuertaTDA(&casas[numeroCasa], puerta,contadorPuertas[numeroCasa]);
                contadorPuertas[numeroCasa]++;
                if(contadorPuertas[numeroCasa]==TAM){
                    puts("Se termino la capacidad de almacenamiento");
                }
                break;
            case 2:
                puts("ingresa el ancho de la ventana");
                fflush(stdin);
                scanf("%d", &ventana.ancho);
                puts("ingresa el alto de la ventana");
                fflush(stdin);
                scanf("%d", &ventana.altura);
                puts("ingresa el numero de casa donde se guardara la ventana");
                fflush(stdin);
                scanf("%d", &numeroCasa);
                ingresaVentanaTDA(&casas[numeroCasa], ventana,contadorVentanas[numeroCasa]);
                contadorPuertas[numeroCasa]++;
                if(contadorPuertas[numeroCasa]==TAM){
                    puts("Se termino la capacidad de almacenamiento");
                }
                break;
            case 3:
                imprimeTDA(casas[0]);
                imprimeTDA(casas[1]);
                break;
            case 4:
                puts("fin del programa");
                exit(0);
                break;
            default:
                puts("Ingreso en una opcion invalida");
                break;
        }//switch
    } while(opcionUsuario<5);       
} //fin de operacion