/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
*/
/**
 * @brief Calcula el hash de un archivo con sha256
 * @param filename nombre del archivo de entrada 
 * @return hash del archivo, NILL si ocurre un error
 */
char * hash(char * filename);
char * hash(char * prmFilename)
{
    char * varResultado = NULL;
    char * varComando;
    FILE * fp;

    varComando = (char*)malloc(
        strlen("sha256sum ")
        + strlen(prmFilename)
        + 1);

    // Primera forma de copiar
    //strcpy(varComando, "sha256sum ");
    //strcat(varComando, filename);

    // Segunda forma
    sprintf(varComando, "sha256sum %s", prmFilename);
    

    fp = popen(varComando, "r");

    if(fp == NULL)
    {
        free(varComando);
        return NULL;
    }

    varResultado = (char*)malloc(65);

    fscanf(fp, "%s", varResultado);

    if (strlen(varResultado) == 64)
    {
        pclose(fp);
        free(varComando);
        return varResultado;
    }
    else
    {
        pclose(fp);
        free(varComando);
        free(varResultado);
        return NULL;
    }

    return varResultado;
}