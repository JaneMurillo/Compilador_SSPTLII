#ifndef _LEXICO
#define _LEXICO

#include <iostream>
#include <string>
using namespace std;

class TipoSimbolo{
public:
 static const int ERROR= -1;
 static const int IDENTIFICADOR= 0;
 static const int ENTERO= 1;
 static const int REAL= 2;
 static const int OPADIC= 5;
 static const int OPMULT= 6;
 static const int PESOS= 23;

};


class Lexico{
      private:
       string fuente;

       int ind;
       bool continua;
       char c;
       int estado;
       int digito;

       char sigCaracter();
       void sigEstado(int estado);
       void aceptacion(int estado);
       bool esLetra(char c);
       bool esDigito(char c);
       bool esEspacio(char c);
       void retroceso();

      public:
       string simbolo;
       int tipo;

       Lexico(string fuente);
       Lexico();

       void entrada(string fuente);
       string tipoAcad(int tipo);

       int sigSimbolo();
       bool terminado();

};


#endif
