#ifndef _ARBOLSINTACTICO
#define _ARBOLSINTACTICO
#include <iostream>
#include <string>
#include "pila.h"

using namespace std;

class Tipo: public Nodo
{
    public:
        Tipo(string simbolo)
        {
            this->simbolo = simbolo;
            this->sig = NULL;
        }

        void muestra()
        {
            muestraNodo();
            cout << "<Tipo> " << simbolo << endl;
        }
};

class Expresion: public Nodo
{
    public:
        Expresion *izq, *der;
        string guardaArbol()
        {
            return "";
        }
};

class Identificador: public Expresion
{
    public:
        Identificador(string simbolo, Nodo *sig=NULL){
            this->simbolo = simbolo;
            this->sig = sig;
        }

        void muestra(){
            muestraNodo();
            cout << "<Identificador> " << simbolo << endl;
            if(sig != NULL) sig->muestra();
        }
};

class R1 : Nodo{
    public:
        Nodo* Definiciones;
        R1(Pila &pila)
        {
            Noterminal* temp;
            temp = ((Noterminal*)pila.pop());
            this->Definiciones = temp->nodo;
            pila.pop();
        }
        void muestra()
        {
            cout << "<programa>" << endl;
            Definiciones->muestra();
            if (sig != NULL) sig->muestra();
        }
};


class R3 : Nodo{
    public:
        Nodo* Definicion;
        Nodo* Definiciones;
        R3(Pila &pila)
        {
            Noterminal* temp;
            temp = ((Noterminal*)pila.pop());
            this->Definicion = temp->nodo;
            pila.pop();
            temp = ((Noterminal*)pila.pop());
            this->Definiciones = temp->nodo;
            pila.pop();
        }
        void muestra()
        {
            cout << "<Definiciones>" << endl;
            Definicion->muestra();
            Definiciones->muestra();
            if (sig != NULL) sig->muestra();
        }
};

class R4 : Nodo{
    public:
        Nodo* DefVar;
        R4(Pila &pila)
        {
            Noterminal* temp;
            temp = ((Noterminal*)pila.pop());
            this->DefVar = temp->nodo;
            pila.pop();

        }
        void muestra()
        {
            cout << "<DefVar>" << endl;
            DefVar->muestra();
            if (sig != NULL) sig->muestra();
        }
};

class R5 : Nodo{
    public:
        Nodo* DefFunc;
        R5(Pila pila)
        {
            this->DefFunc = DefFunc;
            this->sig = sig;
        }

        void muestra()
        {
            DefFunc->muestraNodo();
            if (sig != NULL) sig->muestra();
        }
};

class R6 : Nodo{
    public:
        Tipo* tipo;
        string id;
        Nodo* ListaVar;
        string coma;
        friend class Pila;
        R6(Pila &pila)
        {
            Noterminal* temp;
            pila.pop();
            this->coma = pila.pop()->regresar();
            pila.pop();
            this->tipo = new Tipo(pila.pop()->regresar());
            pila.pop();
            this->id = pila.pop()->regresar();
            pila.pop();
            temp = ((Noterminal*)pila.pop());
            this->ListaVar = temp->nodo;
        }
        void muestra()
        {
            cout << "<DefVar>" << endl;
            tipo->muestra();
            cout << id;
            ListaVar->muestraNodo();

            if (sig != NULL) sig->muestra();
        }
};

#endif
