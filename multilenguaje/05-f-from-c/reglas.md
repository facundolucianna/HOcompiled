# Reglas para compilar

### Paso 1

Se crearon los archivos *f-sum.f90* con la subrutina sum_abs

```fortran
subroutine sum_abs(inp, num, asum)
```

En la cabecera del archivo *c-main.c* se debe declarar la funcion sum_abs como externa, para que el compilado sepá que se encuentra en otro archivo.

```c
extern void sum_abs_(int *inp, int *num, int *asum);
```

Observese los argumentos de la funcion como punteros y el agregado del _ , sin esto no funcionará. El argumento inp cuando se lo llame en el codigo, es el puntero al array.

```c
sum_abs_(data, &num, &suma);
```

### Paso 2

Se crearon los objetos tanto del archivo main programado en C con el compilador de C (gcc).

```
gcc -c c-main.c -o c-main.o
```

Como asi tambien el objeto de la parte en Fortran (gfortran).

```
gfortran -c f-sum.f90 -o f-sum.o
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
0000000000000004 C suma
                 U sum_abs_
```

**f-sum.o**

```
[shell]$ nm f-sum.o
0000000000000000 T sum_abs_
```

### Paso 4

Una vez verificado todo con el comando *nm*, se pasa a linekar usando el linker de *gcc* ya que el programa es en C.

```
gcc c-main.o f-sum.o -o main
```
