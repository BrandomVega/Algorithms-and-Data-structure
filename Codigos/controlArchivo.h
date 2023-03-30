#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

typedef struct{
    char* binario;
    char* hexadecimal;
    int entero;
}Data;

char pathLectura[13];
char pathEscritura[64];

void escribeListaCadenasArchivo(char** listaCadenas, int tamArr);
void escribeEstructuraEnArchivo(Data* datos);
void iniciaOperacion(int argv, char** argc);