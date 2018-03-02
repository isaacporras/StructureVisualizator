#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "NodoListaCircular.h"
#include "QString"
#include <iostream>
#include <string>
#include <stdio.h>

#include "NodoListaCircular.h"

class CircularList {
public:
    NodoListaCircular *primero;
    NodoListaCircular *ultimo;
    int largo = 0;

    //DEFINICION DE LA CLASE

public:
    CircularList(){
        primero = ultimo = null;
        ultimo = primero = null;
    }


    //INGRESAR AL FINAL

public:
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
