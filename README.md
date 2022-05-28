# Compilador_SSPTLII

En este repositorio se encuentran las carpetas donde se encuentra el código de las actividades realizadas para el desarrollo del Proyecto para la materia Seminario de Solución de Problemas de Traductores de Lenguaje II.

Las actividades para el desarrollo del Compilador se encuentran divididas en las siguientes carpetas:

* Actividad 1: **MiniAnalizadorLexico** - Mini Analizador Léxico
* Actividad 2: **Compilador_SSPTLII** - Analizador Léxico
* Actividad 3: **MiniAnalizadorSintactico** - Mini Analizador sintáctico
* Actividad 4: **AnalizadorSintacticoObjetos** - Analizador Sintáctico implementación usando Objetos
* Actividad 5: **AnalizadorSintacticoGramatica** - Gramática del compilador



## Mini Analizador Léxico

El contenido de esta primera etapa tiene la implementación del código para el comienzo del desarrollo de un compilador: el Análisis Léxico, con el cuál, será posible  leer secuencias de caracteres de entrada, para de esta manera analizar y buscar los componentes léxicos que recibe, comprobando si los tokens que obtiene son legales para el análisis de identificadores, números enteros, números reales, junto con operadores de adición y de multiplicacion.

En la imagen se muestra una prueba de los tokens que identifica el mini analizador léxico:

<img src="./MiniAnalizadorLexico/images/funcionamiento-mini-analizador-lexico.png">

La entrada de la cadena obtenida en 'main.cpp', de manera que cuando se obtiene un token, se analiza en los distintos casos posibles:
- Determinar si es una letra
- Determinar si es un digito
- Determinar si es un carácter de adición
- Determinar si es un carácter de multiplicación

Dentro de la carpeta *MiniAnalizadorLexico*, en el README.ms se puede leer más información acerca de ello.


## Analizador Léxico

El programa comienza solicitando una cadena al usuario, de manera que cuando este la introduce, el código va validando mediante estructuras simples si dirigirse a un estado de aceptación o al siguiente estado, para evaluar si es de aceptación. De esta manera, se va avanzando en la cadena, evaluando cada token para identificarlo, y regresandose una posición cuando es necesario para evaluar el siguiente token. Cuando termina de evaluarse todos los tokens, se imprime el final del analizador léxico, determinado por el carácter '$'.
En esta etapa se agregaron más opciones para los tokens, de acuerdo a la tabla presentada para la actividad. Se agregó también la función de aceptacion2, porque anteriormente, se imprimian la identificación de algunos tokens que capturaban un carácter de más. 

En la imagen se muestra una prueba de distintos tokens en el analizador léxico y cómo identifica el tipo de cada uno:

<img src="./Compilador_SSPTLII/images/funcionamiento-del-analizador-lexico.png">

Los casos posibles según la tabla proporcionada, se pueden clasificar como:
- Letra
- Digito
- Operador de adición
- Operador de multiplicación
- Operador relacional
- Operador lógico
- Operador de igualdad
- Parentesis, corchete
- Coma, punto y coma

Dentro de la carpeta *Compilador_SSPTLII*, en el README.ms se puede leer más información acerca de ello.


## Mini Analizador Sintáctico

El programa se desarrolla mediante el uso de una Pila de enteros, que va validando la cadena ingresada en el programa, observando lo que se encuentra en la entrada y salida con la tabla de reducciones. Observandolo más detalladamente, se puede decir que a partir de '$0' que se introducen al principio de la pila, se va a introducir el nuevo token que se encuentre en entrada, para identificarlo, comparar la pila con el resultado de la identificación del analizador léxico, y luego determinar la acción a realizar, mostrando lo que se encuentra actualmente en la pila hasta que ocurra una reducción de la regla 1, o para el ejercicio dos, que ocurran las reducciones de la regla 2 y de la 1 para su aceptacion.

En la imagen se muestran los distintos tokens analizados, en la entrada, salida y la pila:

<img src="./MiniAnalizadorSintactico/images/Funcionamiento_del_mini_analizador_sintactico.png">
<img src="./MiniAnalizadorSintactico/images/Funcionamiento_del_mini_analizador_sintactico_e2_1.png">
<img src="./MiniAnalizadorSintactico/images/Funcionamiento_del_mini_analizador_sintactico_e2_2.png">

Dentro de la carpeta *MiniAnalizadorSintactico*, en el README.ms se puede leer más información acerca de ello.

## Mini Analizador Sintáctico con Objetos



# Proyecto

https://drive.google.com/file/d/1ddA4rBIDVZXG3Wm8QdmoKxumuqb20x7B/view?usp=sharing

