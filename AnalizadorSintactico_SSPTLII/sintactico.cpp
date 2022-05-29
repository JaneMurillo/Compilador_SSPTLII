#include <cstdlib>
#include <iostream>
#include <string>
#include "lexico.h"
#include "sintactico.h"
#include "pila.h"
#include "ArbolSintactico.h"

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
    cout << "Entrada: " << lexico.simbolo << endl; // 2 0
    cout << "Accion: " << accion << endl; // Accion 2

    for(int i = 0; i < 3; i++){
        pila.push(new Terminal(lexico.simbolo)); // Agrega el tipo a la pila, 1. id = 0 ; 2. + = 1 ; 3. id = 0
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
        simb = pila.top(); //fila = pila.top();
        fila = stoi(simb->regresar()); // 1
        columna = 3; // R1, entonces la columna va al 3 para E
        accion = tablaLR1[fila][columna]; // [0][3] = 1
        //  pila.push(new Noterminal("E")); // 3
        pila.push(new Estado(to_string(accion))); // 1
        pila.muestra(); // 2 0 3 1
        cout << "Entrada: " << lexico.simbolo << endl; // $
        cout << "Accion: " << accion << endl; // 1
        simb = pila.top(); //fila = pila.top();
        fila = stoi(simb->regresar()); // 1
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
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    for(int i = 0; i < 16; i++){
    if(accion > 0){
        pila.push(new Terminal(lexico.simbolo)); // 1. id ; 2. + ; 3. id ; 4. +
        pila.push(new Estado(to_string(accion))); // 1. Accion 2; 2. Accion 3 ; 3. Accion 1 ; 4. Accion 3
        lexico.sigSimbolo(); // 1. + ; 2. id ; 3. + ; 4. id
        simb = pila.top(); //fila = pila.top();
        fila = stoi(simb->regresar()); // 1
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
            simb = pila.top(); //fila = pila.top();
            fila = stoi(simb->regresar()); // 1
            columna = 3; // R1, entonces la columna va al 3 para E
            accion = tablaLR2[fila][columna]; // [0][3] = 1
            //  pila.push(new Noterminal("E")); // 3
            pila.push(new Estado(to_string(accion))); // 1
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
                simb = pila.top(); //fila = pila.top();
                fila = stoi(simb->regresar()); // 1
                columna = 3; // R1, entonces la columna va al 3 para E
                accion = tablaLR2[fila][columna]; // [0][3] = 1
                //  pila.push(new Noterminal("E")); // 3
                pila.push(new Estado(to_string(accion))); // 1
                pila.muestra(); // 2 0 3 1
                cout << "Entrada: " << lexico.simbolo << endl;
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
    cout << "Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    aceptacion = accion == -1;

    if (aceptacion){
        cout << "Aceptacion " << endl;
    }
}

void Sintactico::Gramatica(int tablaLR[96][46], string& ejemplo, string idR[], string longR[], string nameR[]){
    int j = 0, fila, columna, accion = 1, nterm = 0;
    string nameA;
    Pila pila;
    ElementoPila* simbolo;
    Lexico lexico;
    lexico.entrada(ejemplo);
    pila.push(new Terminal("$")); // 2
    pila.push(new Estado("0")); // 0
    list<Nodo> lista;
    Nodo* actual = NULL;

    while(accion != -1) // Mientras no sea la aceptación
    {
        if (j == 0){
            j = 0;
            lexico.sigSimbolo(); // a = id
        }

        simbolo = pila.top(); //fila = pila.top();
        fila = stoi(simbolo->regresar()); // 1
        columna = lexico.tipo; // id = 0
        accion = tablaLR[fila][columna]; // [0][0] = d2

        if(accion > 0){
            j = 0;
            pila.muestra(); // 2 0
            cout << "Entrada: " << lexico.simbolo << endl;
            cout << "Accion: " << accion << endl;
            pila.push(new Terminal(lexico.simbolo)); // 3
            pila.push(new Estado(to_string(accion))); // 1
            pila.muestra(); // 2 0 3 1
        }
        else if(accion < 0 && accion != -1){
            int longA = 0;
            j = 1;
            nterm++;
            // pila.muestra();
            cout << "Entrada: " << lexico.simbolo << endl;
            cout << "Accion: " << accion << endl;
            accion = abs(accion);
            longA = stoi(longR[accion - 2]);
            nameA = nameR[accion - 2];
            sigRegla(accion, pila, nameA, &actual);

            pila.muestra();
            simbolo = pila.top();
            fila = stoi(simbolo->regresar());
            columna = stoi(idR[accion - 2]);
            pila.push(new Noterminal(actual));
            pila.muestra();
            accion = tablaLR[fila][columna];
            pila.push(new Estado(to_string(accion)));
            pila.muestra();
            }
            else{ if (accion == 0){ break; } }
    }
    actual->muestra();
}


void Sintactico::sigRegla(int nRegla, Pila& pila, string nameA, Nodo** head)
{
    Nodo* nodo_ = new Nodo();
    switch(nRegla - 1)
    {
        case 1:
            {   R1 *r1 = new R1(pila); r1->simbolo = nameA;
                r1->pts = (*head); (*head) = r1; }
            break;
        case 3:
            {   R3* r3 = new R3(pila); r3->simbolo = nameA;
                r3->pts = (*head); (*head) = r3;
            }
            break;
        case 4:
            {   R4* r4 = new R4(pila); r4->simbolo = nameA;
                r4->pts = (*head); (*head) = r4;
            }
            break;
        case 5:
            {   R5* r5 = new R5(pila); r5->simbolo = nameA;
                r5->pts = (*head); (*head) = r5;
                break;
            }
        case 6:
            {   R6* r6 = new R6(pila); r6->simbolo = nameA;
                r6->pts = (*head); (*head) = r6;
                break;
            }
        case 8:
            {   R8* r8 = new R8(pila); r8->simbolo = nameA;
                r8->pts = (*head); (*head) = r8;
                break;
            }
        case 9:
            {   R9* r9 = new R9(pila); r9->simbolo = nameA;
                r9->pts = (*head); (*head) = r9;
                break;
            }

        case 11:
            {   R11* r11 = new R11(pila); r11->simbolo = nameA;
                r11->pts = (*head); (*head) = r11;
                break;
            }
        case 13:
            {   R13* r13 = new R13(pila); r13->simbolo = nameA;
                r13->pts = (*head); (*head) = r13;
                break;
            }

        case 14:
            {   R14* r14 = new R14(pila); r14->simbolo = nameA;
                r14->pts = (*head); (*head) = r14;
                break;
            }
        case 16:
            {   R16* r16 = new R16(pila); r16->simbolo = nameA;
                r16->pts = (*head); (head) = r16;
                break;
            }
        case 17:
            {   R17* r17 = new R17(pila);
                r17->simbolo = nameA;
                r17->pts = (*head);
                (*head) = r17;
                break;
            }
        case 18:
            {   R18* r18 = new R18(pila); r18->simbolo = nameA;
                r18->pts = (*head); (*head) = r18;
                break;
            }
        case 20:
            {   R20* r20 = new R20(pila); r20->simbolo = nameA;
                r20->pts = (*head); (*head) = r20;
                break;
            }
        case 21:
            {   R21* r21 = new R21(pila); r21->simbolo = nameA;
                r21->pts = (*head); (*head) = r21;
                break;
            }
        case 22:
            {   R22* r22 = new R22(pila); r22->simbolo = nameA;
                r22->pts = (*head); (*head) = r22;
                break;
            }
        case 23:
            {   R23* r23 = new R23(pila); r23->simbolo = nameA;
                r23->pts = (*head); (*head) = r23;
                break;
            }
        case 24:
            {   R24* r24 = new R24(pila); r24->simbolo = nameA;
                r24->pts = (*head); (*head) = r24;
                break;
            }
        case 25:
            {   R25* r25 = new R25(pila); r25->simbolo = nameA;
                r25->pts = (*head); (*head) = r25;
                break;
            }
        case 27:
            {   R27* r27 = new R27(pila); r27->simbolo = nameA;
                r27->pts = (*head); (*head) = r27;
                break;
            }
        case 28:
            {   R28* r28 = new R28(pila); r28->simbolo = nameA;
                r28->pts = (*head); (*head) = r28;
                break;
            }
        case 30:
            {   R30* r30 = new R30(pila); r30->simbolo = nameA;
                r30->pts = (*head); (*head) = r30;
                break;
            }
        case 32:
            {   R32* r32 = new R32(pila); r32->simbolo = nameA;
                r32->pts = (*head); (*head) = r32;
                break;
            }
        case 34:
            {
                R34* r34 = new R34(pila); r34->simbolo = nameA;
                r34->pts = (*head); (*head) = r34;
                break;
            }
        case 35:
            {   R35* r35 = new R35(pila); r35->simbolo = nameA;
                r35->pts = (*head); (*head) = r35;
                break;
            }
        case 36:
            {   R36* r36 = new R36(pila); r36->simbolo = nameA;
                r36->pts = (*head); (*head) = r36;
                break;
            }
        case 37:
            {   R37* r37 = new R37(pila); r37->simbolo = nameA;
                r37->pts = (*head); (*head) = r37;
                break;
            }
        case 38:
            {   R38* r38 = new R38(pila); r38->simbolo = nameA;
                r38->pts = (*head); (*head) = r38;
                break;
            }
        case 39:
            {   R39* r39 = new R39(pila); r39->simbolo = nameA;
                r39->pts = (*head); (*head) = r39;
                break;
            }
        case 40:
            {   R40* r40 = new R40(pila); r40->simbolo = nameA;
                r40->pts = (*head); (*head) = r40;
                break;
            }
        case 41:
            {   R41* r41 = new R41(pila); r41->simbolo = nameA;
                r41->pts = (*head); (*head) = r41;
                break;
            }
        case 42:
            {   R42* r42 = new R42(pila); r42->simbolo = nameA;
                r42->pts = (*head); (*head) = r42;
                break;
            }
        case 43:
            {   R43* r43 = new R43(pila); r43->simbolo = nameA;
                r43->pts = (*head); (*head) = r43;
                break;
            }
        case 44:
            {   R44* r44 = new R44(pila); r44->simbolo = nameA;
                r44->pts = (*head); (*head) = r44;
                break;
            }
        case 45:
            {   R45* r45 = new R45(pila); r45->simbolo = nameA;
                r45->pts = (*head); (*head) = r45;
                break;
            }
        case 46:
            {   R46* r46 = new R46(pila); r46->simbolo = nameA;
                r46->pts = (*head); (*head) = r46;
                break;
            }
        case 47:
            {   R47* r47 = new R47(pila); r47->simbolo = nameA;
                r47->pts = (*head); (*head) = r47;
                break;
            }
        case 48:
            {   R48* r48 = new R48(pila); r48->simbolo = nameA;
                r48->pts = (*head); (*head) = r48;
                break;
            }
        case 49:
            {   R49* r49 = new R49(pila); r49->simbolo = nameA;
                r49->pts = (*head); (*head) = r49;
                break;
            }
        case 50:
            {   R50* r50 = new R50(pila); r50->simbolo = nameA;
                r50->pts = (*head); (*head) = r50;
                break;
            }
        case 51:
            {   R51* r51 = new R51(pila); r51->simbolo = nameA;
                r51->pts = (*head); (*head) = r51;
                break;
            }
        case 52:
            {   R52* r52 = new R52(pila); r52->simbolo = nameA;
                r52->pts = (*head); (*head) = r52;
                break;
            }

        default:
            RR* rr = new RR(); rr->simbolo = name;
            rr->pts = (*head); (*head) = rr;
            break;
    }
}

Nodo* Sintactico::push(Nodo** head_ref, string data)
{
    Nodo* new_node = new Nodo();
    new_node->simbolo = data;
    new_node->pts = (*head_ref);
    (*head_ref) = new_node;
    return new_node;
}

