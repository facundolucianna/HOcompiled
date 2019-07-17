# Respuestas de pregunta de Simbolos

Cuando se ejecuta *nm visibility.o* se obtiene:

~~~
0000000000000000 t add_abs
                 U _GLOBAL_OFFSET_TABLE_
000000000000002a T main
                 U printf
0000000000000000 r val1
0000000000000004 R val2
0000000000000000 d val3
0000000000000004 D val4
~~~

Los descriptores que aparece son:

* T - Text symbol, global. Significa que el símbolo está presente en el texto (programa) del archivo objeto, es decir esa parte esa entrada está presente y se encuentra de forma global, o de forma externa por lo que el linkeador podria usarla para otro pedazo de código similar a una librería.
* t - Text symbol, local. Significa que el símbolo está presente en el texto (programa) del archivo objeto, es decir esa parte esa entrada está presente y se encuentra de forma local, o sea no es accesible de forma externa.
* U - Undefined symbol. Significa que no está en el objeto, son los que el linkeador va a buscar en otras locaciones para agregarlos. Por ejemplo el caso de printf que está definido en *stdio.h*.
* R - Este simbolo esta presente en la sección de dato y es de solo lectura. Ademas es global, es decir es accesible de forma externa.
* r - Este simbolo esta presente en la sección de dato y es de solo lectura. Ademas es local, es decir no es accesible de forma externa.
* D - Este simbolo esta inicializado en la sección de dato. Ademas es global, es decir es accesible de forma externa.
* d - Este simbolo esta inicializado en la sección de dato. Ademas es local, es decir no es accesible de forma externa.
