#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
    //uint16_t tipoImg; //Tipo de archivo "BMP", se debe encontrar las letras BM
    int size; //Tamaño del archivo
    uint16_t reserva1;
    uint16_t reserva2;
    int  offset; // Posición del primer byte de imagen
}CabeceraArchivo;

typedef struct{
    unsigned int tamCabecera; //Tamaño de esta estructura
    uint32_t ancho;
    uint32_t alto;
    uint16_t planosColor;
    uint16_t bpp; //bits por pixel
    uint32_t compresion;
    uint32_t tamImg;
    uint32_t resX;
    uint32_t resY;
    uint32_t rangeColor;
    uint32_t impColor;
}CabeceraImagen;

void imprimeCabeceraArchivo(CabeceraArchivo headerFile){
    printf("Tam archivo: %d\n",headerFile.size);
    printf("offSet: %d\n",headerFile.offset);
}

void imprimeCabeceraImagen(CabeceraImagen headerImg){
    printf("Ancho imagen: %d\n",headerImg.ancho);
    printf("Alto imagen: %d\n",headerImg.alto);
    printf("bpp de la imagen: %d\n",headerImg.bpp);
    printf("Tam de la imagen: %d\n",headerImg.tamImg);
    printf("planos de color de la imagen: %d\n",headerImg.planosColor);
    printf("ResX de la imagen: %d\n",headerImg.resX);
    printf("ResY de la imagen: %d\n",headerImg.resY);
    printf("impColor de la imagen: %d\n",headerImg.impColor);
}


/**
 * @brief 
 * 
 * @param nombreArchivoImg Cadena que tiene la ruta del archivo BMP
 * @param cabeceraBMP Cabecera donde se guardara la información de la imagen (características)
 * @return unsigned* Un apuntador a los datos de la imagen (arreglo de pixeles)
 */
unsigned char* cargarImagen(char* nombreArchivoImg, CabeceraImagen* cabeceraBMP){
    FILE* archivoImagen=fopen(nombreArchivoImg,"r");
    if(archivoImagen==NULL){
        puts("No se puede abrir la imagen");
        return NULL;
    } else{
        
        CabeceraArchivo headerFile;   //Variable donde se guardara la información del archivo
        unsigned char* matrizDatos=NULL;  //datos de la imagen (es una matriz que se lee de forma lineal y continua)
        //unsigned char datosImg[];
        int tipoImg=0;
        fread(&tipoImg, sizeof(uint16_t),1,archivoImagen);
        printf("Tipo imagen =%p", tipoImg);
        if(tipoImg!=0x4D42){
            puts("El formato de la imagen no corresponde");
            fclose(archivoImagen);
            return NULL;
        }
        //Lectura de las secciones
        puts("Comenzando la lectura de las cabeceras del archivo");
        //Se lee la cabecera del archivo y se resguarda en la estructura "CabeceraArchivo"
        fread(&headerFile, sizeof(CabeceraArchivo),1,archivoImagen);
        fread(cabeceraBMP,sizeof(CabeceraImagen),1,archivoImagen);

        //Imprimiendo cabeceras:
        puts("Imprimiendo cabecera de archivo");
        imprimeCabeceraArchivo(headerFile);
        puts("Imprimiendo cabecera de imagen");
        imprimeCabeceraImagen(*cabeceraBMP);
        //Reservar memoria para la matriz de datos:
        //unsigned char datosImg[cabeceraBMP->tamImg];
        matrizDatos=(unsigned char*)malloc(sizeof(unsigned char)*(cabeceraBMP->tamImg));
        if(matrizDatos==NULL){
            puts("No hubo memoria para los datos de la imagen");
            fclose(archivoImagen);
            return NULL;
        }
        //Posicionar el cursor en donde comienzan los datos de los pixeles de la imagen
        //Se utiliza fseek para llegar a la posición del primer pixel, contando desde
        //el principio del archivo.
        fseek(archivoImagen,headerFile.offset,SEEK_SET);
        fread(matrizDatos,cabeceraBMP->tamImg,1, archivoImagen);
        fclose(archivoImagen);
        return matrizDatos;
    }
}

void imprimirPixeles(CabeceraImagen cabeceraBMP, unsigned char* matrizImg){
    int posicionX=0, posicionY=0;
   // int** matriz;
    for(int ejeY=--cabeceraBMP.alto;ejeY>0; ejeY--){
        posicionX=0;
        for(int ejeX=0; ejeX<cabeceraBMP.ancho;ejeX++){
            printf("[%d][%d]=%d\n", posicionY, posicionX, matrizImg[ejeX+ejeY*(cabeceraBMP.ancho)]);
            posicionX++;
        }
        printf("\n\n");
        posicionY++;
    }
}

void main(){
    char fileName[9]="lena.bmp";
    CabeceraImagen headerImg;
    unsigned char* matrizImg=cargarImagen(fileName,&headerImg);
    imprimirPixeles(headerImg, matrizImg);
}