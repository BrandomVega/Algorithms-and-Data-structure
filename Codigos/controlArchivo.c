#include "controlArchivo.h"

void escribeListaCadenasArchivo(char** listaCadenas, int tamArr){
    FILE* archivo=fopen(pathEscritura,"w+");
    int i;
    if(archivo==NULL){
        puts(strcat("No se pudo abrir el archivo: ",pathEscritura));
        exit(1);
    }
    //Escribir la lista caracter a caracter en una sola linea
   for(i=0; i<tamArr; i++){//se recorre la lista de palabras
        for(int j=0; j<strlen(listaCadenas[i]); j++) //
            fputc(listaCadenas[i][j],archivo); //Se recorre caracter por caracter cada palabra en la lista
        fputc(';',archivo);
    }
    //Separacion con saltos de linea:
    fputc('\n',archivo);
    fputc('\n',archivo);
    //escribir la lista de cadenas recibidas
    for(i=0; i<tamArr; i++)
        fputs(strcat(listaCadenas[i],"\n"),archivo);


    fclose(archivo);
}

void escribeEstructuraEnArchivo(Data* datos){
    FILE* archivo=fopen("estructura.txt","w+");
    if(archivo==NULL){
        puts(strcat("No se pudo abrir el archivo: ","estructura.txt"));
        exit(1);
    }
    fputs("Numero:",archivo);
    fprintf(archivo,"%d",datos->entero);
    fputc('\n',archivo);
    fputs("binario:",archivo);
    fputs(datos->binario,archivo);
    fputs("\nhex:",archivo);
    fputs(datos->hexadecimal,archivo);
    fclose(archivo);
}

void iniciaOperacion(int argv, char** argc){
    puts("Iniciando programa...");
    strcpy(pathEscritura,"C:\\Users\\gusta\\Desktop\\Prueba_workspace\\Archivos\\escritura.txt");
    int tamCad=40;
    char bufferAux[10]={0};
    char** cadenas=(char**) calloc(tamCad,sizeof(char*)); //Se reserva memoria para una lista de 40 palabras
    char* palabraLinea=(char*)calloc(10,sizeof(char));
    
    if(cadenas==NULL || palabraLinea==NULL){
        puts("No hay suficiente memoria para la lista o para la palabraLinea");
        exit(1);
    }

    strcpy(palabraLinea,"Linea");
    for(int i=0;i<tamCad;i++){
        strcpy(palabraLinea,"Linea");
        cadenas[i]=(char*) calloc(20,sizeof(char)); //Se reserva memoria para que cada palabra de la lista tenga 20 caracteres
        if(cadenas[i]==NULL){
            puts(" No hay memoria suficiente para la palabra");
            exit(1);
        }
        //guardando palabra numerada

        strcat(palabraLinea, itoa(i,bufferAux,10)); //se concate el numero del contador
        strcpy(cadenas[i],palabraLinea); //se envia a la lista la plabra con el numero
    }
    escribeListaCadenasArchivo(cadenas,tamCad);
    puts("Creando estructura");
    //creando estructura que puede almacenar datos
    Data valorUsuario;
    //Reservando memoria para las cadenas internas de la estructura
    valorUsuario.binario=(char*)calloc(10,sizeof(char));
    valorUsuario.hexadecimal=(char*)calloc(10,sizeof(char));
    valorUsuario.entero=20;
    itoa(valorUsuario.entero,valorUsuario.binario,2);
    itoa(valorUsuario.entero,valorUsuario.hexadecimal,16);
    escribeEstructuraEnArchivo(&valorUsuario); //paso por referencia
    
    //liberando memoria
    for(int j=0;j<tamCad;j++)
        free(cadenas[j]);
    free(cadenas);
    free(palabraLinea);
    free(valorUsuario.binario);
    free(valorUsuario.hexadecimal);
    puts("Finalizando programa...");
}