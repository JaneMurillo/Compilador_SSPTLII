#include <cstdlib>
#include <iostream>
#include <string>
#include "lexico.h"
#include "sintactico.h"
#include "pila.h"

using namespace std;

int tablaLR1[5][4] = { 2, 0, 0, 1,
                       0, 0, -1, 0,
                       0, 3, 0, 0,
                       4, 0, 0, 0,
                       0, 0, -2, 0 };

int tablaLR2[5][4] = { 2, 0, 0, 1,
                       0, 0, -1, 0,
                       0, 3, -3, 0,
                       2, 0,0, 4,
                       0, 0, -2, 0 };

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
    cout << "\tEjercicio 1" << endl << endl;
    lexico.entrada(cadena);
    pila.push(TipoSimbolo::PESOS); // Introduce $
    pila.push(0); // Introduce 0
    lexico.sigSimbolo(); // Avanza al siguiente simbolo identificado en el analizador lexico
    fila = pila.top(); // Pone en fila lo que este al tope de la pila, fila = 0
    columna = lexico.tipo; // Guarda en columna el tipo de simbolo, id = 0
    accion = tablaLR1[fila][columna]; // Compara con la tabla y ve la accion a realizar, [0][ID = 0]=d2
    pila.muestra(); // imprime
    cout << "Entrada: " << lexico.simbolo << endl; // 2 0
    cout << "Accion: " << accion << endl; // Accion 2

    for(int i = 0; i < 3; i++){
        pila.push(lexico.tipo); // Agrega el tipo a la pila, 1. id = 0 ; 2. + = 1 ; 3. id = 0
        pila.push(accion); // Agrega la accion a la pila, 1. Accion 2 ; 2. Accion 3 ; 3. Accion 4
        lexico.sigSimbolo(); // avanza y determina el sig simbolo, 1. + ; 2. id ; 3. $
        fila = pila.top(); // Fila guarda lo que hay en el tope de la pila, 1. Accion 2 ; 2. Accion 3 ; 3. Accion 4
        columna = lexico.tipo; // Guarda en columna el tipo de simbolo, 1. + = 1 ; 2. id = 0 ; 3. $
        accion = tablaLR1[fila][columna]; // 1. [2][+] = d3 ; 2. [3][id] = d4 ; 3. [4][$] = r1
        if(accion == 0){
            cout << "Error." << endl;
            return;
        }
        else{
            pila.muestra(); // 1. 2 0 0 2 ; 2. 2 0 0 2 1 3 ; 3. 2 0 0 2 1 3 0 4
            cout << "Entrada: " << lexico.simbolo << endl;
            cout << "Accion: " << accion << endl;
        }
    }
    if(accion == 0){
        cout << "Error." << endl;
        return;
    }
    else{ // Regla 1, -2, borra 6 tokens
        for(int i = 1;i <= 6; i++){
            pila.pop();
        }
        pila.muestra(); // Muestra, 2 0
        fila = pila.top(); // 0
        columna = 3; // R1, entonces la columna va al 3 para E
        accion = tablaLR1[fila][columna]; // [0][3] = 1
        pila.push(3); // 3
        pila.push(accion); // 1
        pila.muestra(); // 2 0 3 1
        cout << "Entrada: " << lexico.simbolo << endl; // $
        cout << "Accion: " << accion << endl; // 1
        fila = pila.top(); // 1
        columna = lexico.tipo; // $
        accion = tablaLR1[fila][columna]; // [1][$] = -1
    }

    pila.muestra();
    cout << "Entrada: " << lexico.simbolo << endl; // $
    cout << "Accion: " << accion << endl; // -1

    aceptacion = accion == -1; // aceptacion

    if (aceptacion){
        cout << "Aceptacion" << endl;
    }
}

void  Sintactico::ejercicio2(string cadena) {
    cout << "\n\tEjercicio 2" << endl << endl;
    Pila pila;
    Lexico lexico;
    lexico.entrada(cadena);
    pila.push(TipoSimbolo::PESOS); // 2
    pila.push(0); // 0
    lexico.sigSimbolo(); // a = id
    fila = pila.top(); // 0
    columna = lexico.tipo; // id = 0
    accion = tablaLR2[fila][columna]; // [0][0] = d2
    pila.muestra(); // 2 0
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    for(int i = 0; i < 16; i++){
    if(accion > 0){
        pila.push(lexico.tipo); // 1. id ; 2. + ; 3. id ; 4. +
        pila.push(accion); // 1. Accion 2; 2. Accion 3 ; 3. Accion 1 ; 4. Accion 3
        lexico.sigSimbolo(); // 1. + ; 2. id ; 3. + ; 4. id
        fila = pila.top();
        columna = lexico.tipo;
        accion = tablaLR2[fila][columna];
        pila.muestra(); // 1. 2 0 0 2 ; 2. 2 0 0 2 1 3 ; 3. 2 0 0 2 1 3 0 2 ; 4. 2 0 0 2 1 3 0 2 1 3
        cout << "Entrada: " << lexico.simbolo << endl; // 1. 1 ; 2. 0 ; 3. 1 ; 3. 0 ; 4. 1
        cout << "Accion: " << accion << endl; // 1. 3 ; 2. 2 ; 3. 3 ; 4. 2
    }
    if(accion < 0){
        if(accion == -3){
            pila.pop();
            pila.pop();
            fila = pila.top();
            columna = 3; // R1, entonces la columna va al 3 para E
            accion = tablaLR2[fila][columna]; // [0][3] = 1
            pila.push(3); // 3
            pila.push(accion); // 1
            pila.muestra(); // 2 0 3 1
            cout << "Entrada: " << lexico.simbolo << endl;
            cout << "Accion: " << accion << endl ;
        }
        if(accion == 4){
           for(int i = 0; i < 5; i++){
                pila.pop();
                pila.pop();
                pila.pop();
                pila.pop();
                pila.pop();
                pila.pop();
                fila = pila.top();
                columna = 3; // R1, entonces la columna va al 3 para E
                accion = tablaLR2[fila][columna]; // [0][3] = 1
                pila.push(3); // 3
                pila.push(accion); // 1
                pila.muestra(); // 2 0 3 1
                cout << "Entrada: " << lexico.simbolo << endl;
                cout << "Accion: " << accion << endl ;
            }
        }
    }
    }
    fila = pila.top(); // 1
    columna = lexico.tipo; // $
    accion = tablaLR2[fila][columna]; // [1][$] = -1
    pila.muestra();
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    aceptacion = accion == -1;

    if (aceptacion){
        cout << "Aceptacion " << endl;
    }
}

