/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

Se comentan estas librerias ya que se cargan en el main, por ende no necesitan volver a cargarse
pero en caso de querer llevarse este codigo a otro proyecto si harian falta.
*/

/*
    @brief esta funcion se encarga de verificar si existe el directorio que reciba por parametro
    @params recibe como parametro prmFP que es de tipo FILE.
    @return 0 en caso de que el FILE pasado por parametro sea nulo
            1 en caso de que sea diferente de nulo

*/

int SePuedeAbrir(FILE *prmFp){
    if(prmFp==NULL){
        return 0;
    }
    return 1;
}

/*
    @brief esta funcion se encarga de copiar un archivo
    @params recibe como parametro fuente que es de tipo char * , el cual contendra el nombre del archivo
            que se quiere copiar.
            recibe como parametro destino que es de tipo char * , la cual contendra el nombre del archivo
            en donde se copiara la fuente.
    @return 0 si el FILE de la fuente o el destino son nulos, esto significa que no existen.
            1 si todo salio de manera correcta.

*/
int copiar_archivo(char * fuente, char * destino){
    FILE *ArchivoFuente;
    FILE *ArchivoDestino; 
    ArchivoFuente=fopen(fuente,"r");
    
    if(!SePuedeAbrir(ArchivoFuente))
    {
        return 0;
    }

    ArchivoDestino=fopen(destino,"w");
    
    if(!SePuedeAbrir(ArchivoDestino)){
        return 0;
    }
    int data1 =0;
    
    //fgetc que retorna un entero igual 
    //a EOF si llegamos al fin del archivo
    while ( (data1 = fgetc ( ArchivoFuente )) != EOF ) {
        fputc ( data1, ArchivoDestino );
    }
    fclose ( ArchivoFuente);
    fclose ( ArchivoDestino );

    return 1;
}



