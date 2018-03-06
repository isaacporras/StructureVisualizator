#ifndef NODOLISTACIRCULAR_H
#define NODOLISTACIRCULAR_H

#include "QString"
#include <iostream>
#include <string>

#define null 0;

/**
  *@file nodolistacircular.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title Nodo Lista Circular
  * @brief Estructura del nodo de la lista circular
  */
/**
 * @brief The NodoListaCircular class Estructura del nodo de la lista circular
 */
class NodoListaCircular {
private:
    QString dato;
    int posicion;
public:
    NodoListaCircular *siguiente;
    NodoListaCircular *anterior;
    /**
     * @brief NodoListaCircular inicializa el nodo
     * @param dat dato que va a contener el nodo
     */
    NodoListaCircular (QString dat){

        this->dato = dat;

        siguiente = null;

        anterior = null;

    }
    /**
     * @brief getDato da el dato que contiene el nodo
     * @return dato del nodo
     */
    QString getDato(){
        return dato;
    }

public:
    /**
     * @brief setPos establece la posicion del nodo
     * @param pos posicion del nodo
     */
    void setPos(int pos){
        this->posicion = pos;
    }
public:
    /**
     * @brief getPos da la posicon del nodo
     * @return  entero de la posicion
     */
    int getPos(){
        return this->posicion;
    }
public:
    /**
     * @brief setDato establece el dato del nodo
     * @param dat dato del nodo
     */
    void setDato(QString dat){
        this->dato = dat;
    }

};




#endif // NODOLISTACIRCULAR_H
