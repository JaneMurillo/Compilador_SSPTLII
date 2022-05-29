#ifndef _SINTACTICO
#define _SINTACTICO
#include <iostream>
#include <string>
#include "pila.h"
#include "ArbolSintactico.h"

using namespace std;

class Sintactico{
      private:

      public:
        Sintactico(string cadena);
        Sintactico();
        void ejercicio1(string cadena);
        void ejercicio2(string cadena);
        void Gramatica(int tablaLR[96][46], string& ejemplo, string idR[], string longR[], string nameR[]);
        void sigRegla(int nRegla, Pila& pila, string nameA, Nodo** head);
        Nodo* push(Nodo** head_ref, string data);

};

#endif
