# Reglas para compilar

### Paso 1

Se crearon los archivos *c-sum.h* y *c-sum.c*. Se tuvo en cuenta que la funcion no devuelva un argumento, sino el resultado de la operacion de la funcion es por puntero. La funciones que se declaren y definan en C, sus argumentos deben ser punteros.

```c
void sum_abs_(int *in, int *num, int *out);
```

En este caso, el parametro *\*in* en Fortran va a ir el array entero *data*. Observese que la función en C debe llamarse con el _ al final de la función para que el linker despues pueda encontrarla.

```fortran
call sum_abs(data,n,asum)
```

Esta es la forma que debe llamarse la función en Fortran. Las variables usadas son

* integer :: data(n), asum, i

### Paso 2

Se crearon los objetos tanto del archivo main programado en Fortran con el compilado en Fortran (gfortran).

```
gfortran -c f-main.f90 -o f-main_f90.o
```

Como asi tambien el objeto de la parte en C (gcc).

```
gcc -c c-sum.c -o c-sum.o
```

### Paso 3

Si se ve el comando *nm* en cada objeto se tiene:

**f-main_f90.o**

```
[shell]$ nm f-main_f90.o
                 U _gfortran_set_args
                 U _gfortran_set_options
                 U _gfortran_st_write
                 U _gfortran_st_write_done
                 U _gfortran_transfer_character_write
                 U _gfortran_transfer_integer_write
                 U _GLOBAL_OFFSET_TABLE_
0000000000000115 T main
0000000000000000 t MAIN__
0000000000000020 r options.1.3882
                 U __stack_chk_fail
                 U sum_abs_
```

**c-sum.o**

```
[shell]$ nm c-sum.o
0000000000000000 T sum_abs_
```

### Paso 4

Una vez verificado todo con el comando *nm*, se pasa a linekar usando el linker de *gfortran* ya que el programa es en Fortran (observese que si se usa gcc no va poder resolver las llamadas de sistema tipo *_gfortran_set_args*).

```
gfortran f-main_f90.o c-sum.o -o main
```
