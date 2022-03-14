#ifndef _PILA
#define _PILA
#include <list>
#include <iostream>
#include <string>

using namespace std;

/*class Alumno{
    protected:
    string codigo;

    public:
    virtual void muestra(){}
};

class Bachillerato: public Alumno{
    protected:
    string preparatoria;

    public:
    Bachillerato(string codigo, string preparatoria){
        this->codigo= codigo;
        this->preparatoria= preparatoria;
    }
    void muestra(){
        cout << "Alumno Bachillerato" << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Preparatoria: " << preparatoria << endl << endl;
    }
};

class Licenciatura: public Alumno{
    protected:
    string carrera;
    int creditos;

    public:
    Licenciatura(string codigo, string carrera, int creditos){
        this->codigo= codigo;
        this->carrera= carrera;
        this->creditos= creditos;
    }
    void muestra(){
        cout << "Alumno Licenciatura" << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Carrera: " << carrera << endl;
        cout << "Creditos: " << creditos << endl << endl;
    }
};*/

/*
class ElementoPila{
    static const int IDENTIFICADOR= 0;
    static const int OPADIC= 1;
    static const int PESOS= 2;

public:
    int tipo;
    string simbolo;

    void elementoPila();
//https://github.com/Erosval2101/Traductores_de_Lenguaje_II/blob/5b0a43275534850ae978d73396586e969c1acbeb/Tarea%204/analizadorSintactico/Pila.cs
    string ToString()
    {
        return simbolo;
    }
};

class Terminal: ElementoPila{
public:
    void terminal(int id);
    void terminal(int id, string sim);
};

class NoTerminal: ElementoPila{
public:
    void noTerminal(int id, string sim);
};

class Estado : ElementoPila{
public:
    estado(int id, string estado);
};*/

class Pila{
   private:
      list <int> lista;

   public:
      void push(ElementoPila x);
      void top();
      void pop();
      void muestra();
};

#endif
