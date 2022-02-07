// Murillo Cortes, Jeanette
// Etapa: Analizador lexico

#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"

using namespace std;

int main(int argc, char *argv[]){

    string cadena;
    cout << "\n\tMINI GENERADOR LEXICO\n\nEscribe la cadena a evaluar: " << endl;
    getline(cin, cadena);
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
