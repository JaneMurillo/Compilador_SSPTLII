# Analizador Léxico

Para la implementación  de este programa se cambios a partir del mini generador léxico, donde se agregaron más opciones para los tokens, de acuerdo a la tabla presentada para la actividad, comprobando si los tokens que se obtienen son legales, examinando la correcta construcción de cada uno de los tokens.

El programa comienza solicitando una cadena al usuario, de manera que cuando este la introduce, el código va validando mediante estructuras simples si dirigirse a un estado de aceptación o al siguiente estado, para evaluar si es de aceptación. De esta manera, se va avanzando en la cadena, evaluando cada token para identificarlo, y regresandose una posición cuando es necesario para evaluar el siguiente token. Cuando termina de evaluarse todos los tokens, se imprime el final del analizador léxico, determinado por el carácter '$'.

Se agregó también la función de aceptacion2, porque anteriormente, se imprimian la identificación de algunos tokens que capturaban un carácter de más. 

En la imagen se muestra una prueba de distintos tokens en el analizador léxico y cómo identifica el tipo de cada uno:

<img src="./images/funcionamiento-del-analizador-lexico.png">


El desarrollo de esta etapa se implementó mediante los archivos 'main.cpp', 'lexico.h' y 'lexico.cpp', donde se realizaron cambios en los archivos de 'lexico.h' y 'lexico.cpp'.


# Lexico.h

En esta etapa de la implementación completa del Analizador Léxico, se agregó a la clase Lexico la función anteriormente mencionada de 'aceptacion2()' para la correcta impresión del analisis léxico.

Por otra parte, en la clase Tipo Simbolo se añadió la declaración de 23 tipos de simbolos posibles para las palabras reservadas del lenguaje, los símbolos que denotan los distintos tipos de operadores, identificadores (de variables, de funciones, de procedimientos, de tipos, etc), separadores de sentencias, y otros símbolos empleados en las distintas construcciones del lenguaje.


# Lexico.cpp

En este archivo se añadieron distintos casos posibles, donde desde el caso 0 el caracter se puede clasificar como:
- Letra
- Digito
- Operador de adición
- Operador de multiplicación
- Operador relacional
- Operador lógico
- Operador de igualdad
- Parentesis, corchete
- Coma, punto y coma
De manera que una vez que se pasa este estado, se puede comenzar dando una aceptación u una redirección a un siguiente estado. 
Si el carácter es una letra, pasa al estado 1 donde se analiza si el identificador contiene letras y digitos hasta que se termine el identificador, observando al mismo tiempo si la cadena que se va formando forma parte de una palabra reservada ya definida; si este es el caso, se de la aceptación número 2.
En caso de ser un digito, se mantiene la validación igual que en el programa pasado, donde se pasa el carácter al caso 2 para observar si es un entero o dirigirse al caso 3 para un flotante. 
Por otro lado, el caso 4 observa si el operador de igualdad no es de un mayor o menor qué, mientras que el caso 7 y 8 analizan si no es un operador lógico Not o un operador de igualdad.
Por ultimo, el caso 5 y 6 analizan si el carácter introducido es un operador lógico. 

Al terminar, como en el programa anterior, Tipo Simbolo identifica y regresa qué tipo de simbolo es para imprimirlo en el archivo 'main.cpp'.
