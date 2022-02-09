// Murillo Cortes, Jeanette
// Etapa: Analizador lexico

#include <cstdlib>
#include <iostream>
#include <string>
#include "lexico.h"
#include "sintactico.h"

using namespace std;

int main(int argc, char *argv[]){

    string cadena1 = "hola+mundo$";
    string cadena2 = "a+b+c+d+e+f$";
    Lexico lexico;
    Sintactico sintactico;
    sintactico.ejercicio1(cadena1);
    sintactico.ejercicio2(cadena2);

    while (lexico.simbolo.compare("$") != 0 ){
          lexico.sigSimbolo();

          cout <<  lexico.simbolo << "\t\t" << lexico.tipoAcad(lexico.tipo) << endl;
    }

    cin.get();

    return 0;
}
