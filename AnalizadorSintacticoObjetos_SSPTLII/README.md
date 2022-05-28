# Mini Analizador Sintáctico con Objetos

El contenido de esta etapa tiene la implementación del código para el uso de una pila de objetos. Será posible leer cadenas como objetos de entrada, para de esta manera analizar y buscar los componentes sintácticos en la tabla LR para llegar a la aceptación de los ejercicios 1 y 2 que recibe, comprobando si los tokens que se obtienen son legales.

En las imagenes se muestra cómo se realiza el análisis mediante el Algoritmo de apilar con Objetos:

<img src="./images/Funcionamiento_del_mini_analizador_sintactico.png">
<img src="./images/Funcionamiento_del_mini_analizador_sintactico_e2_1.png">
<img src="./images/Funcionamiento_del_mini_analizador_sintactico_e2_2.png">

Los cambios de esta etapa se realizaron en los archivos 'Pila. h', 'Pila.cpp' y 'Sintactico.cpp'. 

# Pila.h
En este archivo es donde se implementa la clase padre ElementoPila, donde de ella surgen sus clases hijos 'Terminal', 'NoTerminal' y 'Estado' para que la clase Pila que tenia originalmente, reciba los objetos que regresan estas clases..

# Pila.cpp
De igual manera, el archivo .cpp tiene las funciones que serán utilizadas para hacer push, top, pop y show de los objetos obtenidos en el análizis del mini sintáctico.

# Sintáctico.cpp
Recibe la entrada de la cadena obtenida en 'main.cpp', separando los tokens en objetos, los cuales se analizan al introducir uno a uno en la Pila de objetos ya sea con su clasificación de Terminal, Estado o No Terminal.


