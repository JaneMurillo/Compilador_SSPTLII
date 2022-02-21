#include "lexico.h"

Lexico::Lexico(string fuente) {
    ind = 0;
    this->fuente = fuente;
}

Lexico::Lexico() {
    ind = 0;
}

string Lexico::tipoAcad(int tipo) {
    string cad = "";

    switch (tipo) {
    case TipoSimbolo::IDENTIFICADOR:
        cad = "0. Identificador";
        break;

    case TipoSimbolo::OPADIC:
        cad = "1. Operador de adicion";
        break;

    case TipoSimbolo::PESOS:
        cad = "2. Fin del analizador lexico";
        break;
    }

    return cad;
}

void Lexico::entrada(string fuente) {
    ind = 0;
    this->fuente = fuente;
}

int Lexico::sigSimbolo() {

    estado = 0;
    continua = true;
    simbolo = "";

    while (continua) {
    c = sigCaracter();
    switch (estado) {
        case 0:
            if (esLetra(c)) sigEstado(1);
            else
            if (esDigito(c)) sigEstado(1);
            else
            if (c == '+') aceptacion(1);
            else
            if (c == '$') aceptacion(2);
            else
            if (esEspacio(c)) this->estado = 0;
                break;
        case 1:
            if (esDigito(c)) {
                id = 1;
                sigEstado(1);
            }
            else
            if (esLetra(c)) {
                sigEstado(1);
            }
            else
            if (id == 1) {
                retroceso();
                this->estado = 0;
                id = 0;
            }
            else {
                aceptacion2(0);
                retroceso();
            }
            break;

        }
    }
        //Fin del Automata

        switch (estado) {
        case 0:
            tipo = TipoSimbolo::IDENTIFICADOR;
            break;
        case 1:
            tipo = TipoSimbolo::OPADIC;
            break;
        case 2:
            tipo = TipoSimbolo::PESOS;
            break;
        }

    return tipo;
}

char Lexico::sigCaracter() {
    if (terminado())return '$';

    return fuente[ind++];

}

void Lexico::sigEstado(int estado) {//Checa al inicio los valores
    this->estado = estado;
    simbolo += c;
}

void Lexico::aceptacion(int estado) {
    sigEstado(estado);
    continua = false;
}

void Lexico::aceptacion2(int estado) {
    this->estado = estado;
    continua = false;
}

bool Lexico::terminado() {//fin de cadena
    return ind >= fuente.length();
}

bool Lexico::esLetra(char c) {
    return isalpha(c) || c == '_';
}


bool Lexico::esDigito(char c) {
    return isdigit(c);
}

bool Lexico::esEspacio(char c) {
    return c == ' ' || c == '\t';
}

void Lexico::retroceso() {
    if (c != '$') ind--;
    continua = false;
}
