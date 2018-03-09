#ifndef BINARYTREE_H
#define BINARYTREE_H

/**
  *@file binarytree.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title Binary Tree
  * @brief Archivo que tiene lo referente al arbol binario
  */

#include <iostream>
#include <string>

#include "treenode.h"
using std::string;
/**
 * @brief The BinaryTree class clase que maneja la estructura del arbol binario
 */
class BinaryTree {

    private:
        TreeNode *root;


    public:
        /**
             * @brief BinaryTree inicia el arbol binario
             */
            BinaryTree(){
                root = 0;
            }

    public:
        TreeNode* getRoot(){
            return root;
        }

    public:
        /**
         * @brief insertarNodo inserta un nodo
         * @param dato es el dato del nodo
         */
        void insertarNodo(int dato){
            string posFinal;
            TreeNode *padre = 0;
            TreeNode *corredor = root;
            TreeNode *temporal = new TreeNode(dato);

            if(root == 0){

                root = temporal;
                return;

            }


            else{
                while(corredor != nullptr){



                    if(corredor->getDato() > dato){


                        if (corredor->left == nullptr){
                            temporal->padre = corredor;
                            padre = corredor;
                            posFinal = "izquierda";

                        }

                        corredor = corredor->left;



                    }
                    else if(corredor->getDato() < dato){

                        if(corredor->right == 0){
                            temporal->padre = corredor;
                            padre = corredor;
                            posFinal = "derecha";
                        }

                        corredor = corredor->right;




                    }
                }

                if(posFinal == "izquierda"){

                    padre->left = temporal;

                }
                if(posFinal =="derecha"){

                    padre->right = temporal;

                }



            }
        }
    public:
        /**
         * @brief recorridoPreOrder es el dato del nodo
         * @param nodo nodo incial desde donde se va a recorrer
         */
        void recorridoPreOrder(TreeNode *nodo){
            if(nodo != 0){
                std::cout << "El recorrido del arbol es: " << nodo->getDato() << std::endl;
                recorridoPreOrder(nodo->left);
                recorridoPreOrder(nodo->right);
            }
        }


public:
        /**
     * @brief eliminar busca el nodo que se quiere eliminar
     * @param nodo nodo por el que se esta recorriendo
     * @param buscado valor entero que determina el valor buscado
     */
    void eliminar(TreeNode *nodo, int buscado){
        if(root == nullptr){
            return;
        }
        else if(buscado < nodo->getDato()){
            eliminar(nodo->left, buscado);
        }
        else if(buscado > nodo->getDato()){
            eliminar(nodo->right, buscado);
        }
        else{
            removeNodo(nodo);
        }
    }

public:
        bool removeNodo(TreeNode *nodo ) {


            bool tieneNodoDerecha = nodo->right != nullptr;
            bool tieneNodoIzquierda = nodo->left != nullptr;




            if (!tieneNodoDerecha && !tieneNodoIzquierda) {
                return removeNodoCaso1( nodo );
            }


            if ( tieneNodoDerecha && !tieneNodoIzquierda ) {
                return removeNodoCaso2( nodo );
            }


            if ( !tieneNodoDerecha && tieneNodoIzquierda ) {
                return removeNodoCaso2( nodo );
            }


            if ( tieneNodoDerecha && tieneNodoIzquierda ) {
                return removeNodoCaso3( nodo );
            }

            return false;
        }

public: bool removeNodoCaso1(TreeNode *nodo ) {

            TreeNode *hijoIzquierdo = nodo->padre->left;
            TreeNode *hijoDerecho = nodo->padre->right;

            if ( hijoIzquierdo == nodo ) {
                nodo->padre->left = nullptr;

                return true;
            }

            if ( hijoDerecho == nodo) {
                nodo->padre->right = nullptr;

                return true;
            }

            return false;
        }

public:
        bool removeNodoCaso2( TreeNode *nodo ) {



            TreeNode *hijoIzquierdo = nodo->padre->left;
            TreeNode *hijoDerecho = nodo->padre->right;


            TreeNode *hijoActual = nodo->left != nullptr ?
                    nodo->left : nodo->right;

            if ( hijoIzquierdo == nodo ) {
                nodo->padre->left = hijoActual;



                hijoActual->padre = nodo->padre;
                nodo->right = nullptr;
                nodo->left = nullptr;


                return true;
            }

            if ( hijoDerecho == nodo) {
                nodo->padre->right = hijoActual;



                hijoActual->padre = nodo->padre;
                hijoActual->right = nullptr;
                nodo->right = nullptr;
                nodo->left = nullptr;


                return true;
            }

            return false;
        }

public:
        bool removeNodoCaso3( TreeNode* nodo ) {

            TreeNode * nodoMasALaIzquierda = recorrerIzquierda( nodo->right);
            if ( nodoMasALaIzquierda != nullptr ) {

                nodo->setDato(nodoMasALaIzquierda->dato);


                removeNodo( nodoMasALaIzquierda );
                return true;
            }
            return false;
        }


public:
        TreeNode *recorrerIzquierda(TreeNode* nodo) {
            if (nodo->left != nullptr) {
                return recorrerIzquierda( nodo->left);
            }
            return nodo;
        }

    };



#endif // BINARYTREE_H
