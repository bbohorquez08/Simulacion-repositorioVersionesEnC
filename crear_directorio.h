/*
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "constantes.h"

Se comentan estas librerias ya que se cargan en el main, por ende no necesitan volver a cargarse
pero en caso de querer llevarse este codigo a otro proyecto si harian falta.
*/

/*
    @brief esta funcion se encarga de crear el directorio VERSIONS_DIR que esta definido en constantes.h
           cabe aclarar que solo se creara en caso de que no exista.
    @return 0 en caso de presentarse algun error durante el proceso.
            1 en caso de que el proceso se haga de forma correcta.
*/
int crear_directorio_versiones()
{
    struct stat s;

    //Verifica si el directorio existe
    if(stat(VERSIONS_DIR, &s) == 0)
    {
        if (S_ISDIR(s.st_mode))
            return 1;
        else
            return 0;
    }
    //Verifica si se puede crear el directorio
    if(stat(VERSIONS_DIR, &s) != 0)
    {
        if (mkdir(VERSIONS_DIR, 0755) != 0)
        {
            fprintf(stderr, "No se puede crear el directorio de versiones");
            return 0;
        }    
        else
            return 1;
    }
}
