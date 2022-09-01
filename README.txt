Elaborado por : Juan Fernando Abella      <jabella@unicauca.edu.co>
                Brandon Nicolas Bohorquez <Bbhorquez@unicauca.edu.co>

Sistema de Control de Versiones:


Los Sistemas de Control de Versiones (VCS) permiten guardar el rastro
de las modificaciones sobre determinados elementos. En el contexto de este
examen, se gestionarán versiones de archivos y directorios.

Se implemento un sistema de control de versiones simple, que permite:

Adicionar un archivo al repositorio de versiones.
Listar las versiones de un archivo en el repositorio de versiones.
Obtener la versión de un archivo del repositorio de versiones.
En esta implementación sólo se realiza el control de versiones por
directorio, en el cual sólo se pueden agregar archivos que se encuentren en el
directorio actual.

La aplicación implementada se llama versions.

Su uso será el siguiente:

uso: ./versions add archivo "Comentario"   --- Agregara el archivo a la base de datos con el debido comentario.
     ./versions list archivo               --- listara todas las versiones del archivo que se encuentren.
     ./versions get archivo numero_version --- mostrara la version especifica del archivo requerido.