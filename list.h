/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
*/


int listar(char * file_name){
    FILE * fp;
    registro_archivo  r;
    //abrir el archivo ".versions/versions.db"
    fp=fopen(VERSIONS_FILE,"r");

    if (fp==NULL){
        //retorna 0 si el proceso fallo
        return 0;
    }
    int cont=1;

    while(!feof(fp)) {
        if(fread(&r,sizeof(registro_archivo),1,fp)!=1){
            break;
         }
       if(strcmp(r.filename,file_name)==0){
            printf("Version:%d\nHash:%s\nComentario:%s\n",cont,r.hash,r.comment);
            cont++;
        }
    }
   return 1;
}


