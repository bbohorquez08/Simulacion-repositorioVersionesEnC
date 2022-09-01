//librerias del sistema 
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//Cabeceras realizadas para el desarrollo del parcial
#include "constantes.h"
#include "struct_datos.h"
#include "crear_directorio.h"
#include "hash.h"
#include "copiar.h"
#include "guardar_db.h"
#include "add.h"
#include "get.h"
#include "list.h"

/* 
    @brief Esta funcion se encarga de hacer todas las validaciones, primero comprobando
           que el metodo que se solicita en argv[1] exista, de ser asi, pasa a verificar
           la cantidad de parametros para cada metodo. 
    @params recibe como parametro un entero argc el cual sirve para validar que la cantidad de parametros pasados por
            linea de comando sea correcto.
            recibe como parametro argv[] el cual es un vector de tipo char *, que contiene el
            valor de todostodos los parametros recibidos por linea de comando
*/
void AccionARealizar(int argc , char * argv[]);

/*
    @brief esta funcion simplemente es la encargada de mostrar los mensajes de errores que ocurren
           durante la validaciones que se hacen en AccionARealizar(argc,argv[]) y posteriormente ejecutar
           un exit(EXIT_FAILURE)

    @params recibe como parametro prmMensajeError que es de tipo char * , el cual contendra el mensaje
            con el error que se presento.
*/
void MsjError(char * prmMensajeError);



int main(int argc, char * argv[])
{
    //crea los directorios necesarios para comenzar la ejecucion del proyecto
    //retorna 0 en caso de que no se haya podido crear, por tanto entraria a la condicion
    //del if.
    if(!crear_directorio_versiones())
    {
        fprintf(stderr, "No se puede crear el directorio %s\n", VERSIONS_DIR);
        exit(EXIT_FAILURE);
    }

    //se verifica que al menos se le pasen dos parametros, los cuales serian el nombre del ejecutable
    //y el nombre de la accion a realizar
    if(argc<2){
        fprintf(stderr,"debe indicar correctamente los parametros\n");
        exit(EXIT_FAILURE);
    }
    AccionARealizar(argc,argv);

    exit(EXIT_SUCCESS);
}

void AccionARealizar(int argc , char * argv[]){
    if(strcmp(argv[1],"add")==0){
        if(argc==4){
            if(add(argv[2],argv[3])){
                printf("Se ha agregado correctamenta la nueva version a la base de datos.\n");
            }
        }else{
            MsjError("para el metodo add, debe ingresar el nombre del archivo\na guardar y tambien un comentario.\n");
        }
    }else if(strcmp(argv[1],"list")==0){
        if(argc==3){
           listar(argv[2]);
        }else{
            MsjError("para el metodo list, debe ingresar el nombre del archivo\nal cual se le quiere revisar las versiones.\n");
        }
    }else if(strcmp(argv[1],"get")==0){
        if(argc==4){
            get(argv[2],atoi(argv[3]));
        }else{
            MsjError("para el metodo get, debe ingresar el nombre del archivo\ny el numero de version que quiere consultar.\n");
        }
        
    }
}

void MsjError(char * prmMensajeError){
    fprintf(stderr,prmMensajeError);
    exit(EXIT_FAILURE);
}

