/*Prueba la funcionalidad de la base de datos de estructuras

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


int SeHicieronCambios(char * file_name,char * prmHash){
    FILE *fp=fopen(VERSIONS_FILE,"r");
    int cont = 0;
    registro_archivo  r;
    while(!feof(fp)) {
        if(fread(&r,sizeof(registro_archivo),1,fp)!=1){
            break;
         }
        if(strcmp(r.hash,prmHash)==0){
            printf("No se ha realizado ningun cambio.\n");
            return 0;
        }
    }
    fclose(fp);
    return 1;
}
/*
* @brief esta funcion se encarga de guardar una nueva version en la base de datos, y esto solo se hara
         si se detecta algun cambio en el archivo.
* @params recibe como parametro v que es de tipo registro_archivo
  @return
*
*/
int save2(registro_archivo *v){
	FILE *fp;
	int nmemb;

	fp=fopen(VERSIONS_FILE,"a");
	
	if(fp==NULL){
		perror("fopen");
		return 0;
	}
	if(SeHicieronCambios(v->filename,v->hash)){
	nmemb=fwrite(v,
		      sizeof(registro_archivo),
		      1,
		      fp);
	//cerrar la db
	fclose(fp);
	if(nmemb==1){
		return 1;
	}else{
		return 0;
	}
    }
    fclose(fp);
    return 0;
}

/*
    ESTA ES OTRA MANERA DE GUARDAR ARCHIVOS EN LA BASE DE DATOS.

int save(registro_archivo *v){
    int fd;
    //abrir la base de datos
    fd= open(VERSIONS_FILE,     //archivo
     O_CREAT | O_WRONLY | O_APPEND,    //flags
      S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);    //modo

    if (fd<0){
        perror("open");
        return 0;
    } 

    ssize_t nbytes=write(
        fd,     //descriptor de archivo
        v,       //referencia a memoeria(buffer)
        sizeof(registro_archivo)
        );

    //cerrar la base de datos
    close(fd);

    if(nbytes==sizeof(registro_archivo)){
        return 1;

    }else{
        return 0;
    }
    
    return 0;
}
*/