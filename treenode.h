#ifndef TREENODE_H
#define TREENODE_H


#include <iostream>
#include <string>
using std::string;
/**
  *@file treenode.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title Tree Node
  * @brief Estructura del nodo para el arbol
  */
/**
 * @brief The TreeNode class Estructura del nodo para el arbol
 */
class TreeNode {
public:
        int dato;

    public:
        TreeNode *left;
        TreeNode *right;
        TreeNode *padre;

        /**
     * @brief TreeNode incializa el nodo
     * @param dat
     */
    TreeNode(int dat){
        dato = dat;
        left = 0;
        right = 0;
        padre = 0;

    }


    public:
    /**
         * @brief setDato establece el dato del nodo
         * @param dat dato del nodo
         */
        void setDato(int dat){
            this->dato = dat;
        }

    public:
        /**
         * @brief getDato retorna el dato de un nodo
         * @return  entero del dato
         */
        int getDato(){
            return this->dato;
        }



};



#endif // TREENODE_H
