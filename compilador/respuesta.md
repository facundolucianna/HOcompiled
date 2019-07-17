# Respuestas de preguntas de Compilador

### Punto 1

El primer paso es el Pre-procesador, los comandos al pre-procesador son insertados en el código como líneas con #. Este realiza una serie de pasos, podemos destacar:

* Reemplaza todos los comentarios por espacios simples.
* Los macros predefinidos son reemplazados.
* También existen macros condicionales que permiten que alguna parte del código sea ignorado durante esta etapa para evitar que se compile.
* El comando #include incluye todos los archivos headers, tanto definidos por el usuario como los del sistema. El pre-compliador agrega toda las declaraciones de C de los archivos cabeceras que fueron agregados. Los headers de sistema son declaraciones a partes del sistema operativo, los de usuarios son las declaraciones hechas por el usuario.
* Otra tarea al combinar varios archivos fuentes es informar al compilador de donde cada linea de codigo de C viene de donde, cual archivo fuente y cual numero de linea.

La salida del pre-procesador es una archivo similar al de entrada, excepto por lo que todos los comandos al pre-procesador fueron reemplazados por líneas en blanco y comentarios en espacios. Ademas se agregan información de nombre de archivo fuente y numero de linea de la forma (# linenum filename flags) indicando de donde viene cada linea de codigo.

El segundo paso es la compilación de C a Assembler. En esta etapa el código obtenido del pre-procesador se traduce en instrucciones de Assembler de la arquitectura específica del procesador en el cual se va a utilizar el código. En esta etapa se realizar las optimizaciones a nivel de código. Realiza una serie de pasos:

* Análisis sintáctico, semántico y léxico.
* Genera una intermediate representation (IR). El cual es una representación intermedia de un programa entre el código fuente (C) y el lenguaje objetivo (Assembler). Son estrategias de separar el problema en varios pedazos más simples y facil de manejar. Las representaciones intermedias son planas en basadas en tuplas.
* Optimización (reorden, unión, eliminación, transformación)
* Reemplaza los pedazos de IR en pedazos de lenguaje Assembler.

El tercer paso es la transformación de Assembler a objetos en binario. En esta etapa se crean los archivos objetos. Estos archivos consisten en instrucciones para que los corra el procesador objetivo.

El cuarto y último paso es el Linking. El código objeto generado en la etapa de ensamblaje está compuesto por pedazos de código que el procesador puede entender, pero algunas partes de codigos estan fuera de orden o perdidos. Para generar un ejecutable es necesario reordenar las piezas existentes y las partes faltantes ser agregadas. Además va a agregar instrucciones de funciones provenientes de librerías, aunque está el caso del linkeo dinámico, donde no se pega el código de la librería, sino que se linkea dinámicamente, haciendo que en tiempo de ejecución se va a buscar la parte del código, permitiendo realizar modificaciones de la librerías sin necesidad de re-compilar el programa, y haciendo que los ejecutables sean muchos más livianos. La otra opción, la de agregar o linekar todas las porciones de instrucciones va a hacer un ejecutable mas pesado, pero mas rapido y que no tenga dependencias.

 **Referencias**

1. [The C Preprocessor](https://www.slac.stanford.edu/comp/unix/gnu-info/cpp_1.html)
2. [Steps of compiling a C program](https://medium.com/@bchen720/steps-of-compiling-a-c-program-7a9a531eb9f8)
3. [From Source Code to Executable - Dr. Axel Kohlmeyer](https://www.ictp.it/media/539402/HPC-Appointment-6.pdf)
4. [The Four Stages of Compiling a C Program](https://www.calleerlandsson.com/the-four-stages-of-compiling-a-c-program/)

### Punto 2

La salida del pre-procesador es el archivo *calculator.pp.c*. El archivo agrego toda la información de los archivos de cabeceras (headers), además eliminó los comentarios y reemplazo los #defines.

### Punto 3

En el archivo *calculator.asm* en la línea 10 está en donde comienza el main y la línea 39 comienza la función add_numbers.

### Punto 4

Cuando se ejecuta *nm calculator.o* se obtiene:

~~~
000000000000003e T add_numbers
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T main
                 U printf
~~~

La tercera columna son las entradas de las funciones. Las del código *calculator.c* son **add_numbers** y **main**, las otras están definidas en los headers y los va a resolver el compilador. Los descriptores que aparece son:

* T - Text symbol, global. Significa que el símbolo está presente en el texto del archivo objeto, es decir esa parte esa entrada está presente y se encuentra de forma global, o de forma externa por lo que el linkeador podria usarla para otro pedazo de código similar a una librería.
* U - Undefined symbol. Significa que no está en el objeto, son los que el linkeador va a buscar en otras locaciones para agregarlos. Por ejemplo el caso de printf que está definido en *stdio.h*.

### Punto 5

Aunque ambos posean código maquina de ellos, el ejecutable es el resultado del cuarto paso, o sea linkeo y es el que el sistema puede ejecutar. El linker toma uno o más archivos objetos generador por la etapa de ensamblaje y los combina en un archivo ejecutable. Básicamente, une el programa con las funciones y librerías de sistema que el programa requiere, llenando todos aquellos huecos que puede presentarse de llamados a funciones o porciones de código que no se encuentran en el cuerpo.
