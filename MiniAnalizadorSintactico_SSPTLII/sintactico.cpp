#include <cstdlib>
#include <iostream>
#include <string>
#include "lexico.h"
#include "pila.h"

using namespace std;

int tablaLR1[5][4] = { 2,0,0,1,
                      0,0,-1,0,
                      0,3,0,0,
                      4,0,0,0,
                      0,0,-2,0 };

int tablaLR2[5][4] = { 2,0,0,1,
                      0,0,-1,0,
                      0,3,-3,0,
                      2,0,0,4,
                      0,0,-2,0 };


Pila pila;
Lexico lexico;

int fila, columna, accion;
bool aceptacion = false;

/* Reducciones
-1. Reducción 0 (aceptación)
-2. Reducción 1
-3. Reducción 2
-4. Reducción 3
-n. Reducción n-1
*/

void ejercicio1() {
    lexico.entrada("hola+mundo");
    pila.push(TipoSimbolo::PESOS);
    pila.push(0);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR1[fila][columna];

    pila.muestra();
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;


    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR1[fila][columna];
    pila.muestra();
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    aceptacion = accion == 2;

    if (aceptacion){
        cout << "Aceptacion" << endl;
    }
}

void ejercicio2() {
    lexico.entrada("a+b+c+d+e+f");
    pila.push(TipoSimbolo::PESOS);
    pila.push(0);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR2[fila][columna];

    pila.muestra();
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;


    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR2[fila][columna];
    pila.muestra();
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    aceptacion = accion == -1;

    if (aceptacion){
        cout << "Aceptacion" << endl;
    }
}

