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
ElementoPila* simb;

int fila, columna, accion;
bool aceptacion = false;

/* Reducciones
-1. Reducción 0 (aceptación)
-2. Reducción 1
-3. Reducción 2
-4. Reducción 3
-n. Reducción n-1
*/


/*
void Sintactico::ejemplo(){
Pila pila;
Alumno *alumno;
alumno= new Licenciatura("345678", "Computacion", 200);
pila.push(alumno);
pila.push(new Bachillerato("456789", "Preparatoria 12"));
pila.push(new Licenciatura("456789", "Informatica", 50));
pila.muestra();
cout << "*********************************" << endl;
pila.pop();
pila.muestra();
}*/

void Sintactico::ejercicio1(string cadena) {
    cout << "\tEjercicio 1" << endl << endl;
    lexico.entrada(cadena);
    pila.push(new Terminal("$")); // Introduce $
    pila.push(new Estado("0")); // Introduce 0
    lexico.sigSimbolo(); // Avanza al siguiente simbolo identificado en el analizador lexico
    simb = pila.top(); //fila = pila.top();  // Pone en fila lo que este al tope de la pila, fila = 0
    fila = stoi(simb->regresar()); // 1
    columna = lexico.tipo; // Guarda en columna el tipo de simbolo, id = 0
    accion = tablaLR1[fila][columna]; // Compara con la tabla y ve la accion a realizar, [0][ID = 0]=d2
    pila.muestra(); // imprime
    cout << "Entrada: " << lexico.simb << endl; // 2 0
    cout << "Accion: " << accion << endl; // Accion 2

    for(int i = 0; i < 3; i++){
        pila.push(new Terminal(lexico.simb)); // Agrega el tipo a la pila, 1. id = 0 ; 2. + = 1 ; 3. id = 0
        pila.push(new Estado(to_string(accion))); // Agrega la accion a la pila, 1. Accion 2 ; 2. Accion 3 ; 3. Accion 4
        lexico.sigSimbolo(); // avanza y determina el sig simbolo, 1. + ; 2. id ; 3. $
        simb = pila.top(); //fila = pila.top(); // Fila guarda lo que hay en el tope de la pila, 1. Accion 2 ; 2. Accion 3 ; 3. Accion 4
        fila = stoi(simb->regresar()); // 1
        columna = lexico.tipo; // Guarda en columna el tipo de simbolo, 1. + = 1 ; 2. id = 0 ; 3. $
        accion = tablaLR1[fila][columna]; // 1. [2][+] = d3 ; 2. [3][id] = d4 ; 3. [4][$] = r1
        if(accion == 0){
            cout << "Error." << endl;
            return;
        }
        else{
            pila.muestra(); // 1. 2 0 0 2 ; 2. 2 0 0 2 1 3 ; 3. 2 0 0 2 1 3 0 4
            cout << "Entrada: " << lexico.simb << endl;
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
        simb = pila.top(); //fila = pila.top();
        fila = stoi(simb->regresar()); // 1
        columna = 3; // R1, entonces la columna va al 3 para E
        accion = tablaLR1[fila][columna]; // [0][3] = 1
        //  pila.push(new Noterminal("E")); // 3
        pila.push(new Estado(to_string(accion))); // 1
        pila.muestra(); // 2 0 3 1
        cout << "Entrada: " << lexico.simb << endl; // $
        cout << "Accion: " << accion << endl; // 1
        simb = pila.top(); //fila = pila.top();
        fila = stoi(simb->regresar()); // 1
        columna = lexico.tipo; // $
        accion = tablaLR1[fila][columna]; // [1][$] = -1
    }

    pila.muestra();
    cout << "Entrada: " << lexico.simb << endl; // $
    cout << "Accion: " << accion << endl; // -1

    aceptacion = accion == -1; // aceptacion

    if (aceptacion){
        cout << "Aceptacion" << endl;
    }
}

void  Sintactico::ejercicio2(string cadena) {
    cout << "\n\tEjercicio 2" << endl << endl;
    Pila pila;
    ElementoPila* simb;
    Lexico lexico;
    lexico.entrada(cadena);
    pila.push(new Terminal("$")); // 2
    pila.push(new Estado("0")); // 0
    lexico.sigSimbolo(); // a = id
    simb = pila.top(); //fila = pila.top();
    fila = stoi(simb->regresar()); // 1
    columna = lexico.tipo; // id = 0
    accion = tablaLR2[fila][columna]; // [0][0] = d2
    pila.muestra(); // 2 0
    cout << "Entrada: " << lexico.simb << endl;
    cout << "Accion: " << accion << endl;

    for(int i = 0; i < 16; i++){
    if(accion > 0){
        pila.push(new Terminal(lexico.simb)); // 1. id ; 2. + ; 3. id ; 4. +
        pila.push(new Estado(to_string(accion))); // 1. Accion 2; 2. Accion 3 ; 3. Accion 1 ; 4. Accion 3
        lexico.sigSimbolo(); // 1. + ; 2. id ; 3. + ; 4. id
        simb = pila.top(); //fila = pila.top();
        fila = stoi(simb->regresar()); // 1
        columna = lexico.tipo;
        accion = tablaLR2[fila][columna];
        pila.muestra(); // 1. 2 0 0 2 ; 2. 2 0 0 2 1 3 ; 3. 2 0 0 2 1 3 0 2 ; 4. 2 0 0 2 1 3 0 2 1 3
        cout << "Entrada: " << lexico.simb << endl; // 1. 1 ; 2. 0 ; 3. 1 ; 3. 0 ; 4. 1
        cout << "Accion: " << accion << endl; // 1. 3 ; 2. 2 ; 3. 3 ; 4. 2
    }
    if(accion < 0){
        if(accion == -3){
            pila.pop();
            pila.pop();
            simb = pila.top(); //fila = pila.top();
            fila = stoi(simb->regresar()); // 1
            columna = 3; // R1, entonces la columna va al 3 para E
            accion = tablaLR2[fila][columna]; // [0][3] = 1
            //  pila.push(new Noterminal("E")); // 3
            pila.push(new Estado(to_string(accion))); // 1
            pila.muestra(); // 2 0 3 1
            cout << "Entrada: " << lexico.simb << endl;
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
                simb = pila.top(); //fila = pila.top();
                fila = stoi(simb->regresar()); // 1
                columna = 3; // R1, entonces la columna va al 3 para E
                accion = tablaLR2[fila][columna]; // [0][3] = 1
                //  pila.push(new Noterminal("E")); // 3
                pila.push(new Estado(to_string(accion))); // 1
                pila.muestra(); // 2 0 3 1
                cout << "Entrada: " << lexico.simb << endl;
                cout << "Accion: " << accion << endl ;
            }
        }
    }
    }
    simb = pila.top(); //fila = pila.top();
    fila = stoi(simb->regresar()); // 1
    columna = lexico.tipo; // $
    accion = tablaLR2[fila][columna]; // [1][$] = -1
    pila.muestra();
    cout << "Entrada: " << lexico.simb << endl;
    cout << "Accion: " << accion << endl;

    aceptacion = accion == -1;

    if (aceptacion){
        cout << "Aceptacion " << endl;
    }
}

void Sintactico::Gramatica(int tablaLR[96][46], string& ejemplo, string idR[], string longR[], string nameR[]){
    int band = 0, fila, columna, accion = 1, j = 0, aceptacion = 0;
    string nameA;
    Pila pila;
    ElementoPila* simb;
    Lexico lexico;
    lexico.entrada(ejemplo);
    pila.push(new Terminal("$")); // 2
    Nodo* temp = new Nodo;
    pila.push(new Estado("0")); // 0

    Nodo* actual = new Nodo;

    while(accion != -1) // Mientras no sea la aceptación
    {
        if (j == 0){
            j = 0;
            lexico.sigSimbolo(); // a = id
        }

        simb = pila.top(); //fila = pila.top();
        fila = stoi(simb->regresar()); // 1
        columna = lexico.tipo; // id = 0
        accion = tablaLR[fila][columna]; // [0][0] = d2

        if(accion > 0){
            j = 0;
            pila.muestra(); // 2 0
            cout << "Entrada: " << lexico.simb << endl;
            cout << "Accion: " << accion << endl;
            pila.push(new Terminal(lexico.simb)); // 3
            pila.push(new Estado(to_string(accion))); // 1
            pila.muestra(); // 2 0 3 1
        }
        else if(accion < 0 && accion != -1){
            int longA = 0;
            j = 1;
            pila.muestra();
            cout << "Entrada: " << lexico.simb << endl;
            cout << "Accion: " << accion << endl;
            accion = abs(accion);
            longA = stoi(longR[accion - 2]);
            nameA = nameR[accion - 2];
            sigRegla(accion, pila);

            band++;
            if (band == 1){
                actual->simbolo = nameA;
                actual->sig = nullptr;
                temp = actual;
            }
            else
            {
                temp = push(&actual, nameA);
            }
            simb = pila.top();
            fila = stoi(simb->regresar());
            columna = stoi(idR[accion - 2]);
            pila.push(new Noterminal(temp));
            pila.muestra();
            accion = tablaLR[fila][columna];
            pila.push(new Estado(to_string(accion)));
            pila.muestra();
        }
    }
    temp->sig->muestra();
}


void Sintactico::sigRegla(int nRegla, Pila& pila)
{
    switch(nRegla - 1)
    {
        case 1:
            {
                R1 r1(pila);
            }
            break;
        case 3:
            {
                R3 r3(pila);
            }
            break;
        case 4:
            {
                R4 r4(pila);
            }
            break;
        case 5:
            {
                R5 r5(pila);
            }
            break;
        case 6:
            {
                R6 r6(pila);
            }
            break;
        case 7:
            {
                cout << "";
            }
            break;
        case 8:
            {
                cout << "";
            }
            break;
        case 9:
            {
                cout << "";
            }
            break;
        case 10:
            {
                cout << "";
            }
            break;
        case 11:
            {
                cout << "";
            }
            break;
        case 12:
            {
                cout << "";
            }
            break;
        case 13:
            {
                cout << "";
            }
            break;
        case 14:
            {
                cout << "";
            }
            break;
        case 15:
            {
                cout << "";
            }
            break;
        case 16:
            {
                cout << "";
            }
            break;
        case 17:
            {
                cout << "";
            }
            break;
        case 18:
            {
                cout << "";
            }
            break;
        case 19:
            {
                cout << "";
            }
            break;
        case 20:
            {
                cout << "";
            }
            break;
        case 21:
            {
                cout << "";
            }
            break;
        case 22:
            {
                cout << "";
            }
            break;
        case 23:
            {
                cout << "";
            }
            break;
        case 24:
            {
                cout << "";
            }
            break;
        case 25:
            {
                cout << "";
            }
            break;
        case 26:
            {
                cout << "";
            }
            break;
        case 27:
            {
                cout << "";
            }
            break;
        case 28:
            {
                cout << "";
            }
            break;
        case 29:
            {
                cout << "";
            }
            break;
        case 30:
            {
                cout << "";
            }
            break;
        case 31:
            {
                cout << "";
            }
            break;
        case 32:
            {
                cout << "";
            }
            break;
        case 33:
            {
                cout << "";
            }
            break;
        case 34:
            {
                cout << "";
            }
            break;
        case 35:
            {
                cout << "";
            }
            break;
        case 36:
            {
                cout << "";
            }
            break;
        case 37:
            {
                cout << "";
            }
            break;
        case 38:
            {
                cout << "";
            }
            break;
        case 39:
            {
                cout << "";
            }
            break;
        case 40:
            {
                cout << "";
            }
            break;
        case 41:
            {
                cout << "";
            }
            break;
        case 42:
            {
                cout << "";
            }
            break;
        case 43:
            {
                cout << "";
            }
            break;
        case 44:
            {
                cout << "";
            }
            break;
        case 45:
            {
                cout << "";
            }
            break;
        case 46:
            {
                cout << "";
            }
            break;
        case 47:
            {
                cout << "";
            }
            break;
        case 48:
            {
                cout << "";
            }
            break;
        case 49:
            {
                cout << "";
            }
            break;
        case 50:
            {
                cout << "";
            }
            break;
        case 51:
            {
                cout << "";
            }
            break;
        case 52:
            {
                cout << "";
            }
            break;

        default:
            break;
        }
}

Nodo* Sintactico::push(Nodo** head_ref, string data)
{
    Nodo* new_node = new Nodo();
    new_node->simbolo = data;
    new_node->sig = (*head_ref);
    (*head_ref) = new_node;
    return new_node;
}

