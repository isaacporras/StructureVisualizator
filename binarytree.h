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
            eliminarNodo(nodo);
        }
    }

public:
    /**
     * @brief eliminarNodo cambia las referencias del nodo para poder eliminarlo
     * @param nodo nodo que se elimina
     */
    void eliminarNodo(TreeNode *nodo){
        if(nodo->left != nullptr && nodo->right != nullptr){
            TreeNode *menor = minimo(nodo->right);
            nodo->dato = menor->dato;
            eliminarNodo(menor);
        }
        else if(nodo->left != nullptr){
            remplazar(nodo,nodo->left);
            destroy(nodo);
        }
        else if(nodo->right){
            remplazar(nodo, nodo->right);
            destroy(nodo);
        }
        else{
            remplazar(nodo, nullptr);
            destroy(nodo);
        }

    }


public:
    /**
     * @brief minimo busca el nodo por el cual se va a remplazar
     * @param nodo nodo por el cual se va recorriendo
     * @return  retorna el nodopor el cual se va a sustituir
     */
    TreeNode *minimo(TreeNode *nodo){
        if(nodo == nullptr){
            return nullptr;
        }
        if(nodo->left){
            return minimo(nodo->left);
        }
        else{
            return nodo;
        }

    }

public:
    /**
     * @brief remplazar remplaza el nodo que se busca por el minimo a su derecha
     * @param nodo nodo que se va a elimianr
     * @param nodonuevo nodo
     */
    void remplazar(TreeNode *nodo,TreeNode *nodonuevo){
        if(nodo->padre) {
            if (nodo->dato == nodo->padre->left->dato) {
                nodo->padre->left = nodonuevo;
            } else if (nodo->dato == nodo->padre->right->dato) {
                nodo->padre->right = nodonuevo;
            }
        }
        if(nodonuevo!= nullptr){
            nodonuevo->padre = nodo->padre;
        }
    }

public: void
    /**
     * @brief destroy elimina el nodo cambiadole las referencias
     * @param node el nodo a eliminar
     */
    destroy(TreeNode *node){
        node->left = nullptr;
        node->right = nullptr;
        delete( node);
    }


};



#endif // BINARYTREE_H
