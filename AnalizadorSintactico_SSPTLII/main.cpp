// Murillo Cortes, Jeanette
// Etapa: Analizador Sintactico

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "lexico.h"
#include "sintactico.h"
#include "ArbolSintactico.h"
#include "pila.h"

using namespace std;


int main(int argc, char *argv[]){
    Lexico lexico;
    Pila pila;
    Sintactico sintactico;

    int tablaLR[96][46];
    int num, mat, filas, columnas;
    string idR[52]{}, longR[52]{}, nameR[52]{};
    string cadena1 = "hola+mundo$", cadena2 = "a+b+c+d+e+f$";
    string ejemplo = "int hola;", salida = "", forsave = "";

    // Abrir el archivo del compilador lr
    ifstream archivolr("compilador.lr");
    if (!archivolr.is_open())
    {
        cout << "Error al abrir el archivo." << endl;
    } else if (archivolr.is_open()){
        cout << "Entre al archivo wii" << endl << endl;
        getline(archivolr, forsave); // Numero 52
        num = atoi(forsave.c_str());
        for (int i = 0; i < num; i++) {
            //forsave.clear();
			//getline(archivolr, forsave);
            archivolr >> idR[i];
            archivolr >> longR[i];
            archivolr >> nameR[i];
        }
        archivolr >> forsave;
        archivolr >> forsave;
        for (filas = 0;filas < 95; filas++) {
            for (columnas = 0;columnas < 46; columnas++) {
                archivolr >> tablaLR[filas][columnas];
            }
        }
	}
	archivolr.close();
    sintactico.Gramatica(tablaLR, ejemplo, idR, longR, nameR);
    return 0;
}



