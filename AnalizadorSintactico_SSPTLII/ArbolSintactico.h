#ifndef _ARBOLSINTACTICO
#define _ARBOLSINTACTICO
#include <iostream>
#include <string>
#include "pila.h"

using namespace std;

class Tipo: public Nodo
{
    public:
        Tipo(string simbolo){
            this->simbolo =  simbolo;
            this->pts = NULL;
        }
        void muestra(){
            muestraNodo();
            cout << "Tipo" << simbolo << endl;
        }
};

class Expresion: public Nodo
{
    public:
        Expresion *izq, *der;
        string guardaArbol(){
            return "";
        }
};

string esp = ""; int i = 0;

void apila(){
	i++;
	esp = esp + "   ";
}
void desapilar(){
	i--;
	esp = "";
	for (int x = 0; x < i; x++){
		esp = esp + "   ";
	}
}

class Identificador: public Expresion
{
    public:
        Identificador(string simbolo, Nodo *sig=NULL){
            this->simbolo = simbolo;
            this->pts = sig;
        }
        void muestra(){
            muestraNodo();
            cout << "Identificador" << simbolo << endl;
            if(pts != NULL) pts->muestra();
        }
};

class RR : public Nodo
{
    public:
        void muestra() { cout << this->simbolo <<endl; }
};

class R1 : Nodo{
    public:
        Nodo* Definiciones;
        R1(Pila &pila)
        {
            pila.pop();
            this->Definiciones = ((Noterminal*)pila.pop())->getNodo();
        }
        void muestra()
        {
            cout << "programa" << endl;
            if (Definiciones != NULL) Definiciones->muestra();
            cout << "-Programa\n" << endl;
        }
};


class R3 : Nodo{
    public:
        Nodo* Definicion;
        Nodo* Definiciones;
        R3(Pila &pila)
        {
            pila.pop();
            this->Definicion = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->Definiciones = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra()
        {
            cout << esp << "Definiciones" << endl; apila();
            if (Definicion != NULL)Definicion->muestra();
            if (Definiciones != NULL)Definiciones->muestra();
            desapilar();
            cout << esp << "-Definiciones" << endl;
        }
};

class R4 : Nodo{
    public:
        Nodo* DefVar;
        R4(Pila &pila)
        {
            pila.pop();
            DefVar = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra()
        {
            cout << esp << "DefVar" << endl; apila();
            if(DefVar!=NULL) DefVar->muestra();
            desapilar();
            cout << esp << "-Definicion" << endl;
        }
};

class R5 : Nodo{
    public:
        Nodo* DefFunc;
        R5(Pila pila)
        {
            pila.pop();
            DefFunc = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra()
        {
            cout << esp << "Definicion" << endl; apila();
            if (DefFunc != NULL) DefFunc->muestra();
            desapilar();
            cout << esp << "-Definicion" << endl;
        }
};

class R6 : Nodo{
    public:
        string tipo;
        string id;
        Nodo* ListaVar;
        R6(Pila &pila)
        {
            pila.pop();
            pila.pop();
            pila.pop();
            this->ListaVar = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->id = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->tipo = ((Terminal*)pila.pop())->regresar();
        }
        void muestra()
        {
            cout << esp <<"DefVar" << endl; apila();
            cout << tipo <<endl;
            cout << id << endl;
            if(ListaVar != NULL)ListaVar->muestra();
            cout << esp << endl;
            desapilar();
            cout << esp << "-DefVar" << endl;
        }
};

class R8 : public Nodo
{
    public:
        string id;
        Nodo* ListaVar;
        R8(Pila& pila)
        {
            pila.pop();
            this->ListaVar = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->id = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            pila.pop();
        }

        void muestra()
        {
            cout << esp << "ListaVar" << endl; apila();
            cout << esp << id << endl;
            if (ListaVar != NULL) ListaVar->muestra();
            desapilar();
            cout << esp << "-ListaVar" << endl;
        }
};

class R9 : public Nodo
{
    public:
        string id, tipo, pa, pc;
        Nodo *Parametros;
        Nodo *BloqFunc;
        R9(Pila& pila)
        {
            pila.pop();
            this->BloqFunc = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->pc = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->Parametros = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->pa = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->id = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->tipo = ((Terminal*)pila.pop())->regresar();
        }
        void muestra()
        {
            cout << esp << "DefFunc" << endl; apila();
            cout << esp << tipo;
            cout << id;
            cout << pa;
            if (Parametros != NULL) Parametros->muestra();
            cout << pc << endl;
            if (BloqFunc != NULL) BloqFunc->muestra();
            desapilar();
            cout << esp << "-DefFunc" << endl;
        }
};

class R11 : public Nodo
{
    public:
        string tipo;
        string id;
        Nodo *ListaParam;
        R11(Pila& pila)
        {
            pila.pop();
            this->ListaParam = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->id = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->tipo = ((Terminal*)pila.pop())->regresar();
        }

        void muestra()
        {
            cout << esp << "Parametros" << endl; apila();
            cout << esp << tipo ;
            cout << id;
            if (ListaParam != NULL) ListaParam->muestra();
            desapilar();
            cout << esp << "-Parametros" << endl;
        }
};

class R13 : public Nodo
{
    public:
        string tipo;
        string id;
        Nodo *ListaParam;
        R13(Pila& pila)
        {
            pila.pop();
            this->ListaParam = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->id = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->tipo = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            pila.pop();
        }
        void muestra()
        {
            cout << esp << "ListaParam" << endl; apila();
            cout << esp << tipo;
            cout << id;
            if (ListaParam != NULL) ListaParam->muestra();
            desapilar();
            cout << esp << "-ListaParam\n";
        }
};

class R14 : public Nodo
{
    public:
        string la, lc;
        Nodo* DefLocales;
        R14(Pila& pila)
        {
            pila.pop();
            this->lc = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->DefLocales = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->la = ((Terminal*)pila.pop())->regresar();
        }
        void muestra() {
            cout << esp << "BloqFunc"<<endl; apila();
            cout << esp << la << endl;
            if (DefLocales != NULL) DefLocales->muestra();
            cout << esp << lc << endl;
            desapilar();
            cout << esp << "-BloqFunc"<<endl;
        }
};

class R16 : public Nodo
{
    public:
        Nodo* DefLocal;
        Nodo* DefLocales;
        R16(Pila& pila)
        {
            pila.pop();
            this->DefLocales = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->DefLocal = ((Noterminal*)pila.pop())->nodo;
        }

        void muestra()
        {
            cout << esp << "DefLocales"<<endl; apila();
            if (DefLocal != NULL) DefLocal->muestra();
            if (DefLocales != NULL) DefLocales->muestra();
            desapilar();
            cout << esp << "DefLocales"<<endl;
        }
};

class R17 : public Nodo
{
    public:
        Nodo* DefVar;
        R17(Pila& pila)
        {
            pila.pop();
            this->DefVar = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra() {
            cout << esp << "DefLocal"<<endl; apila();
            if (DefVar != NULL) DefVar->muestra();
            desapilar();
            cout << esp << "-DefLocal"<<endl;
        }
};

class R18 : public Nodo
{
    public:
        Nodo *Sentencia;
        R18(Pila& pila)
        {
            pila.pop();
            this->Sentencia= ((Noterminal*)pila.pop())->nodo;
        }

        void muestra() {
            cout << esp << "DefLocal"<<endl; apila();
            if (Sentencia != NULL) Sentencia->muestra();
            desapilar();
            cout << esp << "-DefLocal"<<endl;
        }
};

class R20 : public Nodo
{
    public:
        Nodo* Sentencia;
        Nodo* Sentencias;
        R20(Pila& pila)
        {
            pila.pop();
            this->Sentencias = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->Sentencia = ((Noterminal*)pila.pop())->nodo;
        }

        void muestra() {
            cout << esp << "Sentencias"<<endl; apila();
            if (Sentencias != NULL) Sentencias->muestra();
            if (Sentencia != NULL) Sentencia->muestra();
            desapilar();
            cout << esp << "-Sentencias"<<endl;
        }
};

class R21 : public Nodo
{
    public:
        string id, asignacion;
        Nodo* Expresion;
        R21(Pila& pila)
        {
            pila.pop();
            pila.pop();
            pila.pop();
            this->Expresion=((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->asignacion=((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->id= ((Terminal*)pila.pop())->regresar();
        }
        void muestra()
        {
            cout << esp << "Sentencia" << endl; apila();
            cout << esp << id;
            cout << asignacion << endl;
            if (Expresion != NULL) Expresion->muestra();
            desapilar();
            cout << esp << "-Sentencia" << endl;
        }
};

class R22 : public Nodo
{
    public:
        string If, pa, pc;
        Nodo* Expresion;
        Nodo* SentenciaBloque;
        Nodo* Otro;
        R22(Pila& pila)
        {
            pila.pop();
            this->Otro= ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->SentenciaBloque= ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->pc= ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->Expresion= ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->pa= ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->If= ((Terminal*)pila.pop())->regresar();
        }
        void muestra() {
            cout << esp << "Sentencia"<<endl; apila();
            cout << esp << If;
            cout << pa;
            if (Expresion != NULL) Expresion->muestra();
            cout << pc;
            if (SentenciaBloque != NULL) SentenciaBloque->muestra();
            if (Otro != NULL) Otro->muestra();
            desapilar();
            cout << esp << "-Sentencia"<<endl;
        }
};

class R23 : public Nodo
{
    public:
        Nodo* Expresion;
        Nodo* Bloque;
        string pa, pc, While;
        R23(Pila& pila){
            pila.pop();
            this->Bloque = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->pc = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->Expresion = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->pa = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->While = ((Terminal*)pila.pop())->regresar();
        }

        void muestra(){
            cout << esp << "Sentencia" << endl; apila();
            cout << esp << While;
            cout << pa;
            if (Expresion != NULL) Expresion->muestra();
            cout << pc;
            if (Bloque != NULL) Bloque->muestra();
            desapilar();
            cout << esp << "-Sentencia" << endl;
        }
};

class R24 : public Nodo
{
    public:
        Nodo *ValorRegresa;
        string bac;
        R24(Pila& pila){
            pila.pop();
            pila.pop();
            pila.pop();
            this->ValorRegresa= ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->bac= ((Terminal*)pila.pop())->regresar();
        }
        void muestra(){
            cout << esp << "Sentencia" << endl; apila();
            cout << esp << bac;
            if (ValorRegresa != NULL) ValorRegresa->muestra();
            desapilar();
            cout << esp << "-Sentencia" << endl;
        }
};

class R25 : public Nodo
{
    public:
        Nodo* LlamadaFunc;
        R25(Pila& pila){
            pila.pop();
            pila.pop();
            pila.pop();
            this->LlamadaFunc = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "Sentencia" << endl; apila();
            if (LlamadaFunc != NULL) LlamadaFunc->muestra();
            desapilar();
            cout << esp << "-Sentencia" << endl;
        }
};

class R27 : public Nodo
{
    public:
        Nodo *SentenciaBloque;
        string Else;
        R27(Pila& pila){
            pila.pop();
            this->SentenciaBloque = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->Else = ((Terminal*)pila.pop())->regresar();
        }
        void muestra(){
            cout << esp << "Otro" << endl; apila();
            cout << esp << Else;
            if (SentenciaBloque != NULL) SentenciaBloque->muestra();
            desapilar();
            cout << esp << "-Otro" << endl;
        }
};

class R28 : public Nodo
{
    public:
        Nodo *Sentencias;
        string pa, pc;
        R28(Pila& pila){
            pila.pop();
            this->pc = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->Sentencias = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->pa = ((Terminal*)pila.pop())->regresar();
        }
        void muestra() {
            cout << esp << "Bloque" << endl; apila();
            cout << esp << pa << endl;
            if (Sentencias != NULL) Sentencias->muestra();
            cout << pc << endl;
            desapilar();
            cout << esp << "-Bloque" << endl;
        }
};

class R30 : public Nodo
{
    public:
        Nodo* Expresion;
        R30(Pila& pila){
            pila.pop();
            this->Expresion = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "ValorRegresa" << endl; apila();
            if (Expresion != NULL) Expresion->muestra();
            desapilar();
            cout << esp << "-ValorRegresa" << endl;
        }
};

class R32 : public Nodo
{
    public:
        Nodo* Expresion;
        Nodo* ListaArgumentos;
        R32(Pila& pila){
            pila.pop();
            this->Expresion = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->ListaArgumentos = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "Argumentos" << endl; apila();
            if (Expresion != NULL) Expresion->muestra();
            if (ListaArgumentos != NULL) ListaArgumentos->muestra();
            desapilar();
            cout << esp << "-Argumentos" << endl;
        }
};

class R34 : public Nodo
{
    public:
        Nodo* Expresion;
        Nodo* ListaArgumentos;
        R34(Pila& pila)
        {
            pila.pop();
            this->ListaArgumentos = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->Expresion = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            pila.pop();
        }
        void muestra() {
            cout << esp << "ListaArgumentos" << endl; apila();
            if (Expresion != NULL) Expresion->muestra();
            if (ListaArgumentos != NULL) ListaArgumentos->muestra();
            desapilar();
            cout << esp << "-ListaArgumentos" << endl;
        }
};

class R35 : public Nodo
{
    public:
        Nodo* LlamadaFunc;
        R35(Pila& pila){
            pila.pop();
            this->LlamadaFunc = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra() {
            cout << esp << "Termino" << endl; apila();
            if (LlamadaFunc != NULL) LlamadaFunc->muestra();
            desapilar();
            cout << esp << "-Termino" << endl;
        }
};

class R36 : public Nodo
{
    public:
        string id;
        R36(Pila& pila){
            pila.pop();
            this->id = ((Terminal*)pila.pop())->regresar();
        }
        void muestra() {
            cout << esp << "Termino" << endl; apila();
            cout << esp << this->id << endl;
            desapilar();
            cout << esp << "-Termino" << endl;
        }
};

class R37 : public Nodo
{
    public:
        string entero;
        R37(Pila& pila){
            pila.pop();
            this->entero = ((Terminal*)pila.pop())->regresar();
        }
        void muestra(){
            cout << esp << "Termino" << endl; apila();
            cout << esp << entero << endl;
            desapilar();
            cout << esp << "-Termino";
        }
};

class R38 : public Nodo
{
    public:
        string real;
        R38(Pila& pila){
            pila.pop();
            this->real= ((Terminal*)pila.pop())->regresar();
        }
        void muestra(){
            cout << esp << "Termino" << endl; apila();
            cout << esp << real << endl;
            desapilar();
            cout << esp << "-Termino" << endl;
        }
};

class R39 : public Nodo
{
    public:
        string cadena;
        R39(Pila& pila){
            pila.pop();
            cadena = ((Terminal*)pila.pop())->regresar();
        }
        void muestra(){
            cout << esp << "Termino" << endl; apila();
            cout << esp << cadena << endl;
            desapilar();
            cout << esp << "-Termino" << endl;
        }
};

class R40 : public Nodo
{
    public:
        string id, pa, pc;
        Nodo *Argumentos;
        R40(Pila& pila){
            this->pc = ((Terminal*)pila.pop())->regresar();
            this->Argumentos = ((Noterminal*)pila.pop())->nodo;
            this->pa = ((Terminal*)pila.pop())->regresar();
            this->id = ((Terminal*)pila.pop())->regresar();
        }
        void muestra(){
            cout << esp << "LlamadaFunc" << endl; apila();
            cout << esp << id;
            cout << pa;
            if (Argumentos != NULL) Argumentos->muestra();
            cout << pc << endl;
            desapilar();
            cout << esp << "-LlamadaFunc" << endl;
        }
};

class R41 : public Nodo
{
    public:
        Nodo* Sentencia;
        R41(Pila& pila){
            pila.pop();
            this->Sentencia = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "SentenciaBloque" << endl; apila();
            if (Sentencia != NULL) Sentencia->muestra();
            desapilar();
            cout << esp << "-SentenciaBloque" << endl;
        }
};

class R42 : public Nodo
{
    public:
        Nodo* Bloque;
        R42(Pila& pila){
            pila.pop();
            this->Bloque = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "SentenicaBloque" << endl; apila();
            if (Bloque != NULL) Bloque->muestra();
            desapilar();
            cout << esp << "-SentenciaBloque" << endl;
        }
};

class R43 : public Nodo
{
    public:
        Nodo* expresion;
        string pa, pc;
        R43(Pila& pila){
            pila.pop();
            this->pc = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->expresion = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->pa = ((Terminal*)pila.pop())->regresar();
        }
        void muestra(){
            cout << esp << "Expresion" << endl; apila();
            cout << esp << pa << endl;
            if (expresion != NULL) expresion->muestra();
            cout << pc << endl;
            desapilar();
            cout << esp << "-Expresion" << endl;
        }
};

class R44 : public Nodo
{
    public:
        string opSuma;
        Nodo *expresion;
        R44(Pila& pila){
            pila.pop();
            expresion = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            opSuma = ((Terminal*)pila.pop())->regresar();
        }
        void muestra(){
            cout << esp << "Expresion" << endl; apila();
            cout << esp << opSuma << "\n";
            if (expresion != NULL) expresion->muestra();
            desapilar();
            cout << esp << "-Expresion" << endl;
        }
};

class R45 : public Nodo
{
    public:
        string opNot;
        Nodo *expresion;
        R45(Pila& pila){
            pila.pop();
            this->expresion = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->opNot = ((Terminal*)pila.pop())->regresar();
        }
        void muestra(){
            cout << esp << "Expresion" << endl; apila();
            cout << esp << opNot << endl;
            if (expresion != NULL) expresion->muestra();
            desapilar();
            cout << esp << "-Expresion" << endl;
        }
};

class R46 : public Nodo
{
    public:
        Nodo* expresion1;
        Nodo* expresion2;
        string opMult;
        R46(Pila& pila){
            pila.pop();
            this->expresion2 = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->opMult = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->expresion1 = ((Noterminal*)pila.pop())->nodo;
        }

        void muestra(){
            cout << esp << "Expresion" << endl; apila();
            if (expresion1 != NULL) expresion1->muestra();
            cout << esp << opMult << endl;
            if (expresion2 != NULL) expresion2->muestra();
            desapilar();
            cout << esp << "-Expresion" << endl;
	}
};

class R47 :public Nodo
{
    public:
        Nodo* expresion1;
        Nodo* expresion2;
        string opSuma;
        R47(Pila& pila){
            pila.pop();
            this->expresion2 = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->opSuma = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->expresion1 = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "Expresion" << endl; apila();
            if (expresion1 != NULL) expresion1->muestra();
            cout << esp << opSuma << endl;
            if (expresion2 != NULL) expresion2->muestra();
            desapilar();
            cout << esp << "-Expresion" << endl;
        }
};

class R48 : public Nodo
{
    public:
        Nodo* expresion1;
        Nodo* expresion2;
        string opRelac;
        R48(Pila& pila){
            pila.pop();
            this->expresion2 = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->opRelac = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->expresion1 = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "Expresion" << endl; apila();
            if (expresion1 != NULL) expresion1->muestra();
            cout << esp << opRelac << endl;
            if (expresion2 != NULL) expresion2->muestra();
            desapilar();
            cout << esp << "-Expresion" << endl;
        }
};

class R49 : public Nodo
{
    public:
        Nodo* expresion1;
        Nodo* expresion2;
        string opIgual;
        R49(Pila& pila)
        {
            pila.pop();
            this->expresion2 = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->opIgual = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->expresion1 = ((Noterminal*)pila.pop())->nodo;
        }

        void muestra() {
            cout << esp << "Expresion" << endl; apila();
            if (expresion1 != NULL) expresion1->muestra();
            cout << esp << opIgual << endl;
            if (expresion2 != NULL) expresion2->muestra();
            desapilar();
            cout << esp << "-Expresion" << endl;
        }
};

class R50 : public Nodo
{
    public:
        Nodo* expresion1;
        Nodo* expresion2;
        string opAnd;
        R50(Pila& pila){
            pila.pop();
            this->expresion2 = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->opAnd = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->expresion1 = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "Expresion" << endl; apila();
            if (expresion1 != NULL) expresion1->muestra();
            cout << esp << opAnd << endl;
            if (expresion2 != NULL) expresion2->muestra();
            desapilar();
            cout << esp << "-Expresion" << endl;
        }
};

class R51 : public Nodo //<Expresion>
{
    public:
        Nodo* expresion1;
        Nodo* expresion2;
        string opOr;
        R51(Pila& pila){
            pila.pop();
            this->expresion2 = ((Noterminal*)pila.pop())->nodo;
            pila.pop();
            this->opOr = ((Terminal*)pila.pop())->regresar();
            pila.pop();
            this->expresion1 = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "Expresion" << endl; apila();
            if (expresion1 != NULL) expresion1->muestra();
            cout << esp << opOr << endl;
            if (expresion2 != NULL) expresion2->muestra();
            desapilar();
            cout << esp << "-Expresion" << endl;
        }
};

class R52 : public Nodo
{
    public:
        Nodo *Termino;
        R52(Pila &pila){
            pila.pop();
            Termino = ((Noterminal*)pila.pop())->nodo;
        }
        void muestra(){
            cout << esp << "Expresion" << endl; apila();
            if (Termino != NULL) Termino->muestra();
            desapilar();
            cout << esp << "-Expresion" << endl;
        }
};

#endif
