# Reglas para compilar

### Paso 1

En este caso ya existen los archivos necesario para realizar el ejercicio. Pero si se obtiene el archivo objeto de la parte en c++, cuando se ejecuta el comando *nm* se ve:

```
[shell]$ gcc -c cpp-sum.cpp -o cpp-sum.o

[shell]$ nm cpp-sum.o
0000000000000000 T _Z7sum_absPKii
```

Lo cual va a ser una complicación a la hora de linkear. Por lo que en el primer paso, en el archivo *cpp.sum.h* se debe agregar las sentencia **extern "C" {}** y poner entre corchetes las funciones que se deseen usar en C. Por lo que el archivo *cpp.sum.h* queda:

```cpp
#ifndef C_SUM_H
#define C_SUM_H

extern "C" {

  int sum_abs(const int * const in, const int num);

}

#endif

```

### Paso 2

Una vez hecho esto se crean los archivos objetos.

```
gcc -c c-main.c -o c-main.o
```

Como asi tambien el objeto de la parte en Fortran (gfortran).

```
gcc -c cpp-sum.cpp -o cpp-sum.o
```

### Paso 3

Si se ve el comando *nm* en cada objeto se tiene:

**c-main.o**

```
[shell]$ nm c-main.o
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T main
                 U printf
                 U __stack_chk_fail
                 U sum_abs
```

**cpp-sum.o**

```
[shell]$ nm cpp-sum.o
0000000000000000 T sum_abs
```

### Paso 4

Una vez verificado todo con el comando *nm*, se pasa a linekar usando el linker de *gcc* ya que el programa es en C.

```
gcc c-main.o cpp-sum.o -o main
```
