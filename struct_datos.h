#include <limits.h>
#include <stdio.h>

typedef struct{
    char filename[PATH_MAX];
    char comment[BUFSIZ];
    char hash[65];
}registro_archivo;

