#include "pila.h"
#include "lexico.h"
#include <sstream>
/*
void Pila::push( Alumno *x){
    lista.push_front(x);
}

Alumno* Pila::pop(){
    Alumno* x= *lista.begin();
    lista.erase ( lista.begin() );
    return x;
}

Alumno* Pila::top(){
    return *lista.begin();
}

void Pila::muestra(){
    list <Alumno*>::reverse_iterator it;
    Alumno *x;
    cout << "Pila: ";
    for (it= lista.rbegin(); it != lista.rend(); it++){
    x= *it;
    x->muestra();
    //cout << (*it) << " ";
    }
    cout << endl;
}*/

void Pila::push(ElementoPila x){
    lista.push_front(x);
}

int  Pila::pop(){
    int x= *lista.begin();
    lista.erase ( lista.begin() );
    return x;
}

int Pila::top(){
    return *lista.begin();
}

void Pila::muestra(){
    list <int>::reverse_iterator  it;
    cout << "Pila: ";
    for (it= lista.rbegin(); it != lista.rend(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
}
