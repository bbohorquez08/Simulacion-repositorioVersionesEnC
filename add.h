/*#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


Se comentan estas librerias ya que se cargan en el main, por ende no necesitan volver a cargarse
pero en caso de querer llevarse este codigo a otro proyecto si harian falta.
*/

/*
    @brief esta funcion se encarga de agregar un archivo a la base de datos por medio de la funcion
           save2 que se encuentra en guardar_db.h
    @params recibe como parametro file que es de tipo char *, el cual contendra el nombre del archivo que se
            quiere guardar.
            recibe como parametro comentario que es de tipo char *, el cual contendra el comentario con el que
            se guardara la version en la bd
    @return 0 en caso presentarse algun error durante el proceso.
            1 en caso de que se haya añadido correctamente la nueva version a la bd.

*/



int add(char * file, char * comentario){
    struct stat s;
    if(stat(file,&s)<0){
        return 0;
    }

    if(!S_ISREG(s.st_mode)){
        return 0;
    }
    char * varHash= (char*)malloc(65);

    //aqui va obtener el hash del archivo con la funcion de hash.c
    varHash=hash(file);

    char * nuevo = (char*)malloc(
        strlen(".versions/")
        + strlen(varHash)
        + 1);

    //en caso de algo aumentar +1
    sprintf(nuevo, ".versions/ %s", varHash);

    if(copiar_archivo(file,nuevo)){
        registro_archivo RegistroNuevo;
        memset(&RegistroNuevo,0,sizeof(registro_archivo));
        strcpy(RegistroNuevo.filename,file);
        strcpy(RegistroNuevo.comment,comentario);
        strcpy(RegistroNuevo.hash,varHash);
        return save2(&RegistroNuevo);
    }
    return 0;
}