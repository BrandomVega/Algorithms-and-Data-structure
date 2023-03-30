#include "archivos.h"

void leerArchivo(){
    FILE* archivo=NULL;
    archivo=fopen(pathLectura,"r");
    char caracterLeido;
    char* cadenaLeida=(char*) calloc(41, sizeof(char));
    if(archivo==NULL){
        puts("No se encontro el archivo");
        exit(1);
    }
    puts("\t\tImprimiendo archivo caracter por caracter\n");
    while(!feof(archivo)){
        caracterLeido=fgetc(archivo);
        printf("%c",caracterLeido);
    }
    //Rebobinar el cursor al principio del archivo
    rewind(archivo);
    puts("\t\tImprimiendo archivo linea por linea\n");
    while(!feof(archivo)){
        fgets(cadenaLeida,40,archivo);
        printf("Linea leida-->%s", cadenaLeida);
    }
    //Moviendo el cursor:
    //fseek(archivo,-10,SEEK_END); //Se regresa 10 posiciones desde el final del archivo
    fseek(archivo,8,SEEK_SET);  //Cuenta desde el principio del archivo 8 posiciones
    fseek(archivo, 4, SEEK_CUR); //Se mueve el cursor 4 posiciones desde donde se encuentre
    puts("\n\t\tImprimiendo archivo caracter por caracter despues de mover el cursor\n");
    while(!feof(archivo)){
        fscanf(archivo,"%c", &caracterLeido);
        //convirtiendo a digito y preguntando si es que existe alguno
        if(isdigit(caracterLeido)){
            printf("\nSe encontro al siguiente digito: %c=%d\n",caracterLeido, caracterLeido-'0');
        }
        printf("%c",caracterLeido);
    }
    fclose(archivo);
}

void escrituraArchivo(){
    FILE* archivo=NULL;
    archivo=fopen(pathEscritura,"a+");
    if(archivo==NULL){
        puts("No se encontro el archivo");
        exit(1);
    }
    int numero=10;
    char cadenaAux[3];
    //Escritura con las 3 funciones para escribir en archivos
    fputs(itoa(10,cadenaAux,16),archivo);
    fputc('\n',archivo);
    fprintf(archivo,"%d",numero);
    fputc('\n',archivo);
    fprintf(archivo,"%1.4f",67.2222222);
    fseek(archivo,-1,SEEK_END); //Moviendo el cursor una posicion antes del fin del archivo.
    fprintf(archivo,"%u",-7);
    fclose(archivo);
}

void iniciaOperacion(int argc, char** argv){
    puts("Iniciando programa");
    strcpy(pathLectura,"C:\\Users\\gusta\\Desktop\\Prueba_workspace\\ControlArchivos\\lectura.txt");
    strcpy(pathEscritura,"escritura.txt");
    //leerArchivo();
    escrituraArchivo();
    puts("Fin del programa");
}