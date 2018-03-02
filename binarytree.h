#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>

#include "treenode.h"
using std::string;

class BinaryTree {

    private:
        TreeNode *root;


    public:
            BinaryTree(){
                root = 0;
            }

    public:
        TreeNode* getRoot(){
            return root;
        }

    public:
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
        void recorridoPreOrder(TreeNode *nodo){
            if(nodo != 0){
                std::cout << "El recorrido del arbol es: " << nodo->getDato() << std::endl;
                recorridoPreOrder(nodo->left);
                recorridoPreOrder(nodo->right);
            }
        }


public:
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
    destroy(TreeNode *node){
        node->left = nullptr;
        node->right = nullptr;
        delete( node);
    }


};



#endif // BINARYTREE_H
