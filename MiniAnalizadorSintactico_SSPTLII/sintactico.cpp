#include <cstdlib>
#include <iostream>
#include <string>
#include "lexico.h"
#include "sintactico.h"
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

Sintactico::Sintactico(string cadena) {
    cout << "";
}

Sintactico::Sintactico() {
    cout << "";
}

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

void Sintactico::ejercicio1(string cadena) {
    lexico.entrada(cadena);
    pila.push(TipoSimbolo::PESOS);
    pila.push(0);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR1[fila][columna];

    pila.muestra();
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    for(int i = 0;i <= 2; i++){
        pila.push(lexico.tipo);
        pila.push(accion);
        lexico.sigSimbolo();
        fila = pila.top();
        columna = lexico.tipo;
        accion = tablaLR1[fila][columna];
        pila.muestra();
        cout << "entrada: " << lexico.simbolo << endl;
        cout << "accion: " << accion << endl;
    }
    if(accion == 0){
        cout << "Error." << endl;
        return;
    }
    else{
        for(int i = 0;i <= 5; i++){
            pila.pop();
        }
        pila.muestra();
        fila = pila.top();
        columna = 3;
        accion = tablaLR1[fila][columna];
        pila.push(3);
        pila.push(accion);
        pila.muestra();
        cout << "Entrada: " << lexico.simbolo << endl;
        cout << "Accion: " << accion << endl << endl;
        fila = pila.top();
        columna = lexico.tipo;
        accion = tablaLR1[fila][columna];
    }

    pila.muestra();
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    aceptacion = accion == -1;

    if (aceptacion){
        cout << "Aceptacion" << endl;
    }
}

void  Sintactico::ejercicio2(string cadena) {
    lexico.entrada(cadena);
    pila.push(TipoSimbolo::PESOS);
    pila.push(0);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR2[fila][columna];

    pila.muestra();
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    pila.muestra();
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

