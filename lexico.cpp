#include "lexico.h"

  Lexico::Lexico(string fuente){
    ind= 0;
    this->fuente= fuente; // Se mueve al recorrer la cadena
  }

  Lexico::Lexico(){
    ind= 0;
  }

  string Lexico::tipoAcad(int tipo){
         string cad= "";

         switch (tipo){
           case TipoSimbolo::ERROR:
                cad= "-1. Error";
                break;

           case TipoSimbolo::IDENTIFICADOR:
                cad= "0. Identificador";
                break;

           case TipoSimbolo::ENTERO:
                cad= "1. Numero Entero";
                break;

           case TipoSimbolo::REAL:
                cad= "2. Numero Real";
                break;

           case TipoSimbolo::OPADIC:
                cad= "5. Operador de adicion";
                break;

           case TipoSimbolo::OPMULT:
                cad= "6. Operador de multiplicacion";
                break;

           case TipoSimbolo::PESOS:
                cad= "23. Fin del analizador lexico";
                break;
         }

         return cad;
  }

  void Lexico::entrada(string fuente){
       ind= 0;
      this->fuente= fuente;
  }

int Lexico::sigSimbolo(){ // Primera función que se llama

    estado=0;
    continua= true;
    simbolo= "";

    //Inicio del Automata
    while (continua){
      c= sigCaracter(); // Segunda func. que se llama - Mientras el sig caracter no sea el último, el indice avanza

      switch (estado){ // Primera evaluación de tokens
        case 0:
             if (esLetra(c)) sigEstado(1);
             else
             if (esDigito(c)) sigEstado(2);
             else
             if ( c == '+' || c=='-') aceptacion(5);
             else
              if ( c == '*' ) aceptacion(6);
             else
              if ( c == '$' ) aceptacion(23);
             break;
       case 1: // Evaluación de Identificador
             if (esDigito(c)) sigEstado(1);
             else
             if (esLetra(c)) sigEstado(1);
             else{
               retroceso();
               this->estado = 0; // Identificador
             }
             break;
       case 2: // Evaluación de Entero
             if (esDigito(c)) sigEstado(2);
             else
             if (c != '.' ){
               retroceso();
               this->estado = 1; // Entero
             }
             else
             if (c == '.') sigEstado(3); // Ver si es real
             break;
       case 3: // Evaluación de Real
             if (esDigito(c)) sigEstado(3);
             else
             if (!esDigito(c)){
               retroceso();
               this->estado = 2; // Real
             }
             break;
      }

   }
    //Fin del Automata

      switch (estado){
         case 0:
              tipo= TipoSimbolo::IDENTIFICADOR; // Estado 0
              break;
         case 1:
              tipo= TipoSimbolo::ENTERO; // Estado 1
              break;
         case 2:
              tipo= TipoSimbolo::REAL; // Estado 2
              break;
         case 5:
              tipo= TipoSimbolo::OPADIC; // Estado 5
              break;
         case 6:
              tipo= TipoSimbolo::OPMULT; // Estado 6
              break;
         case 23:
              cout << endl;
              tipo= TipoSimbolo::PESOS; // Estado 23
              break;
        dafault:
              tipo= TipoSimbolo::ERROR; // Estado -1
      }

	return tipo;
}

 char Lexico::sigCaracter(){ // Mientras el sig caracter no sea el último, el indice avanza
      if (terminado()) return '$';

      return fuente[ind++];
 }

  void Lexico::sigEstado(int estado){ // Checa al inicio los valores
       this->estado= estado;
       simbolo+= c;
  }

  void Lexico::aceptacion(int estado){ // Acepta el estado y lo envia al switch
       sigEstado(estado);
       continua= false;
  }

  bool Lexico::terminado(){ // Fin de cadena
         return ind >= fuente.length();
  }

   bool Lexico::esLetra(char c){ // Si caracter es letra
        return isalpha(c) || c=='_';
   }


   bool Lexico::esDigito(char c){ // Si caracter es digito
        return isdigit(c);
   }

   bool Lexico::esEspacio(char c){ // Si caracter es espacio
        return c== ' ' || c== '\t';
   }


   void Lexico::retroceso(){ // Da un retroceso en el indice
      if ( c != '$') ind--;
        continua= false;
    }
