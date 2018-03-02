#ifndef NODOLISTACIRCULAR_H
#define NODOLISTACIRCULAR_H

#include "QString"
#include <iostream>
#include <string>

#define null 0;

class NodoListaCircular {
private:
    QString dato;
    int posicion;
public:
    NodoListaCircular *siguiente;
    NodoListaCircular *anterior;

    NodoListaCircular (QString dat){

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




#endif // NODOLISTACIRCULAR_H
