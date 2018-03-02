#ifndef NODOSIMPLE_H
#define NODOSIMPLE_H

#include "QString"
#include <iostream>
#include <string>

using std::string;
#define null 0;


class NodoSimple{
    private:
            QString dato;
            int posicion;
    public:
        NodoSimple *siguiente;

    NodoSimple (QString dat){
            this->dato = dat;
            siguiente = null;
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



#endif // NODOSIMPLE_H
