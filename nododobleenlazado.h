#ifndef NODODOBLEENLAZADO_H
#define NODODOBLEENLAZADO_H

#include "QString"
#include <iostream>
#include <string>
#define null 0;
/**
  *@file nododobleenlazado.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title Nodo para la lista doble enlazada
  * @brief Estructura de datos nodo para lista doble enlazada
  */
/**
 * @brief The NodoDobleEnlazado class Estructura de datos nodo para lista doble enlazada
 */
class NodoDobleEnlazado {
private:
    QString dato;
    int posicion;
public:
    NodoDobleEnlazado *siguiente;
    NodoDobleEnlazado *anterior;
    /**
     * @brief NodoDobleEnlazado inicializa el nodo
     * @param dat dato del nodo
     */
    NodoDobleEnlazado (QString dat){
        this->dato = dat;
        siguiente = null;
        anterior = null;
    }
    /**
     * @brief getDato retorna el dato que contiene el nodo
     * @return QString del nodo
     */
    QString getDato(){
        return dato;
    }

public:
    /**
     * @brief setPos establece la posicion en la lista del nodo
     * @param pos entero de la posicion
     */
    void setPos(int pos){
        this->posicion = pos;
    }
public:
    /**
     * @brief getPos da la posicion del nodo
     * @return posicion del nodo
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



#endif // NODODOBLEENLAZADO_H
