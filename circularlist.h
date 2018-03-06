#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "NodoListaCircular.h"
#include "QString"
#include <iostream>
#include <string>
#include <stdio.h>

#include "NodoListaCircular.h"

/**
  *@file circularlist.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title CircularList
  * @brief Estructura de datos lista circular
  */

/**
 * @brief The CircularList class clase que contiene la estructura de datos de la lista circular
 */
class CircularList {
public:
    NodoListaCircular *primero;
    NodoListaCircular *ultimo;
    int largo = 0;

    //DEFINICION DE LA CLASE

public:
    /**
     * @brief CircularList inicia la lista circular
     */
    CircularList(){
        primero = ultimo = null;
        ultimo = primero = null;
    }


    //INGRESAR AL FINAL

public:
    /**
     * @brief ingresarDatoFinal ingresa un dato al final de la lista
     * @param dato es un QString que es el dato del nodo
     */
    void ingresarDatoFinal(QString dato){

        NodoListaCircular *temporal = new NodoListaCircular(dato);

        if( primero == 0 ){

            primero = temporal;
            ultimo = temporal;
            temporal->siguiente = temporal;
            temporal->anterior = temporal;
            largo = largo + 1;
        }
        else {

            ultimo->siguiente = temporal;
            temporal-> anterior = ultimo;
            ultimo = temporal;
            temporal->siguiente = primero;
            primero->anterior = temporal;
            largo = largo+1;
        }

        NodoListaCircular *corredor = primero->siguiente;
        int contador = 2;

        primero->setPos(1);

        while(corredor != primero){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor -> siguiente;
        }

    }

    //INGRESAR AL INICIO

public:
    /**
     * @brief ingresarDatoInicio ingresa un dato al inicio
     * @param dato el dato del nodo
     */
    void ingresarDatoInicio(QString dato){
        NodoListaCircular *temporal = new NodoListaCircular(dato);

        if( primero == 0 ){
            primero = temporal;
            ultimo = temporal;
            temporal->siguiente = temporal;
            temporal->anterior = temporal;
            largo = largo + 1;
        }

        else{

            temporal->siguiente = primero;
            primero->anterior = temporal;

            ultimo->siguiente = temporal;
            temporal->anterior = ultimo;
            primero = temporal;
            largo = largo+1;
        }

        NodoListaCircular *corredor = primero->siguiente;
        int contador = 2;

        primero->setPos(1);

        while(corredor != primero){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor -> siguiente;
        }
    }


    // INSERTAR POR POSICION

public:
    /**
     * @brief insertarPorPosicion inserta un nodo en la lista por su posicion
     * @param pos entero que especifica la posicion en la que se quiere insertar
     * @param dato dato que se le quiere dar al nodo insertado
     */
    void insertarPorPosicion(int pos,QString dato){

        NodoListaCircular *corredor = primero;
        NodoListaCircular *temporal = new NodoListaCircular(dato);
        if(pos > largo){
            std::cout << "El rango esta fuera del alcance" << std::endl;
            return;
        }

        if(pos == 1){

            this->ingresarDatoInicio(dato);

            NodoListaCircular *corredor = primero->siguiente;
            int contador = 2;

            primero->setPos(1);

            while(corredor != primero){
                corredor->setPos(contador);
                contador = contador + 1;
                corredor = corredor -> siguiente;
            }
            return;
        }


        while(corredor-> getPos() != pos){

            corredor = corredor->siguiente;
        }

        if(corredor->getPos() == pos){

            temporal->siguiente = corredor;
            temporal->anterior = corredor->anterior;
            corredor->anterior->siguiente =temporal;
            corredor->anterior =temporal;


            NodoListaCircular *corredor = primero->siguiente;
            int contador = 2;

            primero->setPos(1);

            while(corredor != primero){
                corredor->setPos(contador);
                contador = contador + 1;
                corredor = corredor -> siguiente;
            }
        }
        else{
            std::cout << "No se pudo eliminar el dato" << std::endl;
        }

    }

    // ELIMINAR POR POSICION

public:
    /**
     * @brief eliminarPosicion eliminar un nodo por posicion
     * @param pos posicion del nodo que se quiere eliminar
     */
    void eliminarPosicion(int pos){
        if(pos > largo){
            std::cout << "No se pudo eliminar el dato porque no existe tal posicion" << std::endl;
        }

        if(pos == 1){
            eliminarInicio();
            return;
        }
        if(pos == largo){
            eliminarFinal();
            return;
        }

        NodoListaCircular *corredor = primero;

        while(corredor-> getPos()!= pos ){
            corredor = corredor->siguiente;
        }

        if(corredor->getPos() == pos){

            corredor->anterior->siguiente = corredor->siguiente;
            corredor->siguiente->anterior = corredor->anterior;

            largo = largo-1;


            NodoListaCircular *corredor = primero->siguiente;
            int contador = 2;

            primero->setPos(1);

            while(corredor != primero){
                corredor->setPos(contador);
                contador = contador + 1;
                corredor = corredor -> siguiente;
            }
        }
        else{
            std::cout << "No se pudo eliminar el dato" << std::endl;
        }

    }
    //ELIMINAR AL INICIO

public:
    /**
     * @brief eliminarInicio elimina el nodo inicial de la lista
     */
    void eliminarInicio() {

        primero = primero->siguiente;
        ultimo->siguiente = primero;
        primero->anterior = ultimo;

        largo=largo-1;

        NodoListaCircular *corredor = primero->siguiente;
        int contador = 2;

        primero->setPos(1);

        while(corredor != primero){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor -> siguiente;
        }

    }

    //ELIMINAR AL FINAL

public:
    /**
     * @brief eliminarFinal elimina el nodo final de la lista
     */
    void eliminarFinal() {


        ultimo = ultimo->anterior;
        ultimo->siguiente = primero;
        primero->anterior = ultimo;


        largo = largo -1;
        NodoListaCircular *corredor = primero->siguiente;
        int contador = 2;

        primero->setPos(1);

        while(corredor != primero){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor -> siguiente;
        }
    }

    // IMPRIMIR LISTA AL DERECHO

public:
    /**
     * @brief imprimirListaAlDerecho imprime la lista de inicio a fin
     */
    void imprimirListaAlDerecho(){
        NodoListaCircular *corredor = primero;
        if (primero == 0){
            std::cout << "No hay elementos en la lista" << std::endl;
        }
        else{

            NodoListaCircular *corredor = primero->siguiente;
            int contador = 2;

            primero->setPos(1);

            while(corredor != primero){

                contador = contador + 1;
                corredor = corredor -> siguiente;
            }
        }
    }



    //EDITAR POR POSICION

public:
    /**
     * @brief editar cambia el valor de un nodo en especifico
     * @param pos la posicion del nodo que se quiere editar
     * @param dato dato nuevo que se le quiere dar
     */
    void editar(int pos, QString dato){

        if(pos>largo){
            std::cout << "No se puede eliminar porque la pos es mayor que el largo" << std::endl;
        }

        NodoListaCircular *corredor = primero;

        while(corredor-> getPos() != pos){
            corredor = corredor->siguiente;
        }

        if(corredor->getPos() == pos){
            corredor->setDato(dato);

        }
        else{
            std::cout << "No se pudo editar el dato" << std::endl;
        }

    }

public:
    /**
     * @brief obtenerporPosicion retorna el nodo que se especifica en la posicion
     * @param pos posicion del nodo que se quiere retornar
     * @return
     */
    NodoListaCircular obtenerporPosicion(int pos){

        if (pos < largo){
            NodoListaCircular *corredor = primero;

            while(corredor-> getPos() != pos){
                corredor = corredor->siguiente;
            }

            return *corredor;
        }
        else{
            std::cout << "El largo es menor que la posicion digitada"<< std::endl;
            while(true){
                break;
            }

        }
    }

};


#endif // CIRCULARLIST_H
