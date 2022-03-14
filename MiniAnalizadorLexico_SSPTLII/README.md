# Mini Analizador Léxico

El contenido de esta primera etapa tiene la implementación del código para el comienzo del desarrollo de un compilador: el Análisis Léxico, con el cuál, será posible  leer secuencias de caracteres de entrada, para de esta manera analizar y buscar los componentes léxicos que recibe, comprobando si los tokens que obtiene son legales para el análisis de identificadores, números enteros, números reales, junto con operadores de adición y de multiplicacion.

En la imagen se muestra una prueba de los tokens que identifica el mini analizador léxico:

<img src="./images/funcionamiento-del-mini-analizador-lexico.png"

El desarrollo de esta etapa se implementó mediante los archivos 'main.cpp', 'lexico.h' y 'lexico.cpp'

# Main.cpp

En este archivo, la primera parte obtiene una cadena que va a ser analizada en el archivo 'lexico.cpp'. La segunda parte, mediante un while, verifica si el siguiente simbolo de la cadena es '$', si no, avanza de simbolo en simbolo, pasandole el caracter a el archivo 'lexico.cpp', de manera que cuando se termina de hacer el analisis, el carácter vuelve y se imprime.

# Lexico.h

Declara una clase Lexico y una clase Tipo Simbolo.

La clase Lexico contiene declaraciones para variables de indices, caracteres, digitos, estados y funciones para moverse entre caracteres, estados, hacer retrocesos, determinar una aceptación y detectar letras, digitos y espacios.

La clase Tipo Simbolo declara variacles constantes enteras que determinan el qué tipo de caso del analizis es qué número.

# Lexico.cpp

En este archivo se recibe la entrada de la cadena obtenida en 'main.cpp', de manera que cuando se obtiene un caracter de la función 'sigSimbolo()', se analiza en los distintos casos posibles, iniciando en el caso 0 (porque el estado se encuentra en 0), el cual analiza el caracter para:
- Determinar si es una letra
- Determinar si es un digito
- Determinar si es un carácter de adición
- Determinar si es un carácter de multiplicación
Una vez que se pasa este estado, se puede dar una aceptación a los operadores de adición y multiplicación. 
Si el carácter es una letra, pasa al estado 1 donde se analiza si el identificador contiene letras y digitos hasta que se termine el identificador y se de la aceptación.
En caso de ser un digito, se pasa al caso 2 donde se verifica si el digito es solo un entero (y se da aceptación) o si es un flotante (de manera que se dirige al caso 3 y ahí se da aceptación).

Las aceptaciones se dan de acuerdo al numero del estado determinado en los casos anteriores, de manera que Tipo Simbolo los identifica por medio de un switch y regresa qué tipo de simbolo es para imprimirlo en el archivo 'main.cpp'.
