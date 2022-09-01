/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "struct_datos.h"

Se comentan estas librerias ya que se cargan en el main, por ende no necesitan volver a cargarse
pero en caso de querer llevarse este codigo a otro proyecto si harian falta.
*/


/*
    @brief esta funcion se encarga de mostrar los datos de una version en especifico de algun archivo.
    @params recibe como parametro file_name que es de tipo char *, la cual tendra el nombre del archivo al 
            que se le quiere buscar la version.
            recibe como parametro version que es de tipo int, la cual contendra el numero de la version
            que se mostrara en pantalla

    @return 0 si ocurre un error al tratar de abrir el directorio de la bd.
            1 si no ocurrio ningun error, es decir, se completo el proceso satisfactoriamente

*/

int get(char * file_name,int version){
    FILE * fp;
    registro_archivo r;
    fp=fopen(VERSIONS_FILE,"r");
    
    if(fp==NULL){
        return 0;
    }

    int cont=1;

    while(!feof(fp)){
        if(fread(&r,sizeof(registro_archivo),1,fp)!=1){
            break;
        }
        if(strcmp(r.filename,file_name)==0){
            if(cont==version){
                printf("Version:%d\nHash:%s\nComentario:%s\n",cont,r.hash,r.comment);
                copiar_archivo(r.hash,r.filename);
                break;
            }else{
                cont=cont+1;
            }
        }
    }
    fclose(fp);
    return 1;
}