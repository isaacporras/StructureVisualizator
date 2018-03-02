#ifndef NODODOBLEENLAZADO_H
#define NODODOBLEENLAZADO_H

#include "QString"
#include <iostream>
#include <string>
#define null 0;

class NodoDobleEnlazado {
private:
    QString dato;
    int posicion;
public:
    NodoDobleEnlazado *siguiente;
    NodoDobleEnlazado *anterior;

    NodoDobleEnlazado (QString dat){
        this->dato = dat;
        siguiente = null;
        anterior = null;
    }
    QString getDato(){
        return dato;
    }

public:
    void setPos(int pos){
        this->posicion = pos;
    }
public:
    int getPos(){
        return this->posicion;
    }
public:
    void setDato(QString dat){
        this->dato = dat;
    }

};



#endif // NODODOBLEENLAZADO_H
