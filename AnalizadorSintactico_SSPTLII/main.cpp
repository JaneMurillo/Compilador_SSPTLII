// Murillo Cortes, Jeanette
// Etapa: Analizador lexico

#include <cstdlib>
#include <iostream>
#include <string>
#include "lexico.h"
#include "sintactico.h"
#include "pila.h"

using namespace std;

int main(int argc, char *argv[]){


    //string cadena1 = "hola+mundo$";
    //string cadena2 = "a+b+c+d+e+f$";
    Lexico lexico;
    Pila pila;
    Sintactico sintactico;
    //sintactico.ejercicio1(cadena1);
    //sintactico.ejercicio2(cadena2);
    int tablaLR[96][46];
    string idR[52]{}, longR[52]{}, nameR[52]{};


    return 0;
}


