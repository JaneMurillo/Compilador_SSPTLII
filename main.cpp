// Murillo Cortes, Jeanette
// Analizador lexico, con tokens de identificadores, nums. enteros, nums. reales, operador de adicion y de multiplicacion

#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"

using namespace std;

int main(int argc, char *argv[]){

    std::string cadena;
    cout << "\n\tMINI GENERADOR LEXICO\n\nEscribe la cadena a evaluar: " << endl;
    cin>> cadena;
    Lexico lexico;
    lexico.entrada(cadena);

    cout << "\n\nResultados del Analisis Lexico:" << endl << endl;
    cout << "Simbolo\t\tTipo" << endl;

    while ( lexico.simbolo.compare("$") != 0 ){
          lexico.sigSimbolo();

          cout <<  lexico.simbolo << "\t\t" << lexico.tipoAcad(lexico.tipo) << endl;
    }

    cin.get();

    return 0;
}
