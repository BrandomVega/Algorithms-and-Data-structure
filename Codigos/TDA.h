#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

#define TAM 2


//Nivel 2

typedef struct{
    uint16_t altura;
    uint16_t ancho;
} Puerta;

typedef struct{
    uint32_t altura;
    uint32_t ancho;
} Ventana;


//Nivel 3: TDA

typedef struct{
    Puerta puertas[TAM];
    Ventana ventanas[TAM];
    uint8_t cantidadNiveles;
} Casa;


//Prototipo de funciones para almacena y consultar datos en un TDA
Casa crearTDA(Puerta* puertas, Ventana* ventanas, uint8_t cantidadPisos);
void imprimeTDA(Casa miCasa);
void updateVentanasTDA(Casa* miCasa, Ventana ventana, int posVentana);
void ingresaPuertaTDA(Casa* miCasa, Puerta puerta, int posPuerta);
void ingresaVentanaTDA(Casa* miCasa, Ventana ventana, int posVentana);
void crearArregloTDA(Casa* casas, Casa miCasa, Casa miCasa2);
void inicioOperacion(int argc, char** argv);

