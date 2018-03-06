#ifndef DOBLELINKEDLIST_H
#define DOBLELINKEDLIST_H

#include "nododobleenlazado.h"
#include "QString"
#include <iostream>
#include <string>


/**
  *@file doblelinkedlist.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title DobleLinkedList
  * @brief Estructura de datos lista doblemente enlanzada
  */
/**
 * @brief The DobleLinkedList class clase que contiene la estructura de las listas doblemente enlazadas
 */
class DobleLinkedList {
public:
    NodoDobleEnlazado *primero;
    NodoDobleEnlazado *ultimo;
    int largo = 0;

    //DEFINICION DE LA CLASE

public:
    /**
     * @brief DobleLinkedList inicia la lista enlazada
     */
    DobleLinkedList(){
        primero = ultimo = 0;
        ultimo = primero = 0;
    }

    // INSERTAR POR POSICION

public:
    /**
     * @brief insertarPorPosicion inserta un nodo en una posicion especifica
     * @param pos posicion en la que se va a insertar
     * @param dato dato del nodo
     */
    void insertarPorPosicion(int pos, QString dato){

        NodoDobleEnlazado *corredor = primero;
        NodoDobleEnlazado *temporal = new NodoDobleEnlazado(dato);
        if(pos > largo){
            std::cout << "El rango esta fuera del alcance" << std::endl;
            return;
        }

        if(pos == 1){

            this->ingresarDatoInicio(dato);

            NodoDobleEnlazado *corredor2 = primero;
            int contador = 1;
            while(corredor2 != 0){
                corredor2->setPos(contador);
                contador = contador + 1;
                corredor2 = corredor2->siguiente;
            }
            return;
        }

        while(corredor->getPos() != pos){

            corredor = corredor->siguiente;
        }

        if(corredor->getPos() == pos){

            temporal->siguiente = corredor;
            temporal->anterior = corredor->anterior;
            corredor->anterior->siguiente =temporal;
            corredor->anterior =temporal;


            NodoDobleEnlazado *corredor2 = primero;
            int contador = 1;
            while(corredor2 != 0){
                corredor2->setPos(contador);
                contador = contador + 1;
                corredor2 = corredor2->siguiente;
            }
        }
        else{
            std::cout << "No se pudo eliminar el dato" << std::endl;
        }

    }

    //INGRESAR AL FINAL

public:
    /**
     * @brief ingresarDatoFinal ingresa un dato al final de la lista
     * @param dato dato del nodo
     */
    void ingresarDatoFinal(QString dato){

        NodoDobleEnlazado *temporal = new NodoDobleEnlazado(dato);

        if( primero == 0 ){

            primero = temporal;
            ultimo = temporal;
            largo = largo + 1;
        }
        else {

            ultimo->siguiente = temporal;
            temporal-> anterior = ultimo;
            ultimo = temporal;
            largo = largo+1;
        }

        NodoDobleEnlazado *corredor = primero;
        int contador = 1;

        while(corredor != 0){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor -> siguiente;
        }


    }

    //INGRESAR AL INICIO

public:
    /**
     * @brief ingresarDatoInicio ingresa un dato al inicio de la lista
     * @param dato dato del nodo
     */
    void ingresarDatoInicio(QString dato){
        NodoDobleEnlazado *temporal = new NodoDobleEnlazado(dato);

        if( primero == 0 ){
            primero = temporal;
            ultimo = temporal;
            largo = largo + 1;
        }

        else{
            temporal->siguiente = primero;
            primero->anterior = temporal;
            primero = temporal;
            largo = largo+1;
        }

        NodoDobleEnlazado *corredor = primero;
        int contador = 1;
        while(corredor != 0){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor->siguiente;
        }
    }


    // ELIMINAR POR POSICION

public:
    /**
     * @brief eliminarPosicion elimina un nodo por la posicion
     * @param pos posicion del nodo a eliminar
     */
    void eliminarPosicion(int pos){
        std::cout << "  El largo de la lista es :" <<this->largo << std::endl;
        NodoDobleEnlazado *corredor = primero;

        if(pos == 1){
            this->eliminarInicio();
            largo = largo -1;
            NodoDobleEnlazado *corredor2 = primero;
            int contador = 1;
            while(corredor2 != 0){
                corredor2->setPos(contador);
                contador = contador + 1;
                corredor2 = corredor2->siguiente;
            }
            return;
        }
        if (pos == ultimo->getPos()){
            this->eliminarInicio();
            largo = largo -1;
            NodoDobleEnlazado *corredor2 = primero;
            int contador = 1;
            while(corredor2 != 0){
                corredor2->setPos(contador);
                contador = contador + 1;
                corredor2 = corredor2->siguiente;
            }
            return;
        }

        while(corredor-> getPos() != pos){
            corredor = corredor->siguiente;
        }


        if(corredor->getPos() == pos){

            corredor->anterior->siguiente = corredor->siguiente;

            corredor->siguiente->anterior = corredor->anterior;


            largo = largo-1;


            NodoDobleEnlazado *corredor2 = primero;
            int contador = 1;
            while(corredor2 != 0){
                corredor2->setPos(contador);
                contador = contador + 1;
                corredor2 = corredor2->siguiente;
            }
        }
        else{
            std::cout << "No se pudo eliminar el dato" << std::endl;
        }

    }
    //ELIMINAR AL INICIO

public:
    /**
     * @brief eliminarInicio elimina el nodo del inicio
     */
    void eliminarInicio() {

        primero = primero->siguiente;
        primero->anterior = 0;

        largo=largo-1;


        NodoDobleEnlazado *corredor = primero;
        int contador = 1;
        while(corredor != 0){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor->siguiente;


            NodoDobleEnlazado *corredor2 = primero;
            int contador = 1;
            while(corredor2 != 0){
                corredor2->setPos(contador);
                contador = contador + 1;
                corredor2 = corredor2->siguiente;
            }
        }
    }

    //ELIMINAR AL FINAL

public:
    /**
     * @brief eliminarFinal elimina el nodo del final de la lista
     */
    void eliminarFinal() {


        ultimo = ultimo->anterior;
        ultimo->siguiente = 0;


        largo = largo -1;
        NodoDobleEnlazado*corredor = primero;
        int contador = 1;
        while(corredor != 0){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor->siguiente;
        }
    }

    // IMPRIMIR LISTA AL REVEZ

public:
    /**
     * @brief imprimirListaAlRevez imprime la lista al revez
     */
    void imprimirListaAlRevez(){
        NodoDobleEnlazado *corredor = ultimo;
        if (primero == 0){
            std::cout << "No hay elementos en la lista" << std::endl;
        }
        else{
            while(corredor != 0){


                corredor = corredor->anterior;
            }
        }
    }

     //IMPRIMIR LISTA AL DERECHO
public:
    /**
     * @brief imprimirListaDerecho imprime la lista al derecho
     */
    void imprimirListaDerecho(){
        NodoDobleEnlazado *corredor = primero;
        if (primero == 0){
            std::cout << "No hay elementos en la lista" << std::endl;
        }
        else{
            while(corredor != 0){


                corredor = corredor->siguiente;
            }
        }
    }


    //EDITAR POR POSICION

public:
    /**
     * @brief editar cambia el dato del nodo escogido
     * @param pos posicion del nodo que se quiere insertar
     * @param dato dato que se quiere cambiar
     */
    void editar(int pos, QString dato){


        NodoDobleEnlazado *corredor = primero;

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
     * @brief obtenerporPosicion retorna el nodo que se esta buscando
     * @param pos posicion del nodo buscado
     * @return el nodo buscado
     */
    NodoDobleEnlazado obtenerporPosicion(int pos){

        if (pos < largo){
            NodoDobleEnlazado *corredor = primero;

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



#endif // DOBLELINKEDLIST_H
