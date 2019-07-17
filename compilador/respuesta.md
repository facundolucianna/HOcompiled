# Respuestas de preguntas de Compilador

### Punto 1

El primer paso es el Pre-procesador, los comandos al pre-procesador son insertados en el codigo como lineas con #. Este realiza una serie de pasos, podemos destacar:

* Reemplaza todos los comentarios por espacios simples.
* Los macros predefinidos son reemplazados.
* Tambien existen macros condicionales que permiten que alguna parte del codigo sea ignorado durante esta etapa para evitar que se compile.
* El comando #include incluye todos los archivos headers, tanto definidos por el usuario como los del sistema. El pre-compliador agrega toda las declaraciones de C de los archivos cabeceras que fueron agregados. Los headers de sistema son declaraciones a partes del sistema operativo, los de usuarios son las declaraciones hechas por el usuario.
* Otra tarea al combinar varios archivos fuentes es informar al compilador de donde cada linea de codigo de C viene de donde, cual archivo fuente y cual numero de linea.

La salida del pre-procesador es una archivo similar al de entrada, excepto por lo que todos los comandos al pre-procesador fueron reemplazados por lineas en blanco y comentarios en espacios. Ademas se agregan informacion de nombre de archivo fuente y numero de linea de la forma (# linenum filename flags) indicando de donde viene cada linea de codigo.

El segundo paso es la compilación de C a Assembler. En esta etapa el codigo obtenido del pre-procesador se traduce en instrucciones de Assembler de la arquitectura especifica del procesador en el cual se va a utilizar el codigo. En esta etapa se realizar las optimizaciones a nivel de código. Realiza una serie de pasos:

* Análisis sintáctico, semántico y léxico.
* Genera una intermediate representation (IR). El cual es una representacion intermedia de un programa entre el codigo fuente (C) y el lenguaje objetivo (Assembler). Son estrategias de separar el problema en varios pedazos mas simples y facil de manejar. Las representaciones intermedias son planas en basadas en tuplas.
* Optimizacion (reorden, union, elimación, transformación)
* Reemplaza los pedazos de IR en pedazos de lenguaje Assembler.

El tercer paso es la transformacion de Assembler a objetos en binario. En esta etapa se crean los archivos objetos. Estos archivos consisten en intrucciones para que los corra el procesador objetivo.

El cuarto y ultimo paso es el Linking. El codigo objeto generado en la etapa de ensamblaje esta compuesto por pedazos de codigo que el procesador puede entender, pero algunas partes de codigos estan fuera de orden o perdidos. Para generar un ejecutable es necesario reordenar las piezas existentes y las partes faltantes ser agregadas. Ademas va a agregar intrucciones de funciones provenientes de librerias, aunque esta el caso del linkeo dinamico, donde no se pega el codigo de la libreria, sino que se linkea dinamicamente, haciendo que en tiempo de ejecucion se va a buscar la parte del codigo, permitiendo realizar modificaciones de la librerias sin necesidad de re-compilar el programa, y haciendo que los ejecutables sean muchos mas livianos. La otra opcion, la de agregar o linekar todas las porciones de instrucciones va a hacer un ejecutable mas pesado, pero mas rapido y que no tenga dependencias.

 **Referencias**

1. [The C Preprocessor](https://www.slac.stanford.edu/comp/unix/gnu-info/cpp_1.html)
2. [Steps of compiling a C program](https://medium.com/@bchen720/steps-of-compiling-a-c-program-7a9a531eb9f8)
3. [From Source Code to Executable - Dr. Axel Kohlmeyer](https://www.ictp.it/media/539402/HPC-Appointment-6.pdf)
4. [The Four Stages of Compiling a C Program](https://www.calleerlandsson.com/the-four-stages-of-compiling-a-c-program/)

### Punto 2

La salida del pre-procesador es el archivo *calculator.pp.c*. El archivo agrego toda la información de los archivos de cabeceras (headers), ademas elimino los comentarios y reemplazo los #defines.

### Punto 3

En el archivo *calculator.asm* en la linea 10 está en donde comienza el main y la linea 39 comienza la funcion add_numbers.

### Punto 4
