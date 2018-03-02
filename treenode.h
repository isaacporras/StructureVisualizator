#ifndef TREENODE_H
#define TREENODE_H


#include <iostream>
#include <string>
using std::string;

class TreeNode {
public:
        int dato;

    public:
        TreeNode *left;
        TreeNode *right;
        TreeNode *padre;



    TreeNode(int dat){
        dato = dat;
        left = 0;
        right = 0;
        padre = 0;

    }


    public:
        void setDato(int dat){
            this->dato = dat;
        }

    public:
        int getDato(){
            return this->dato;
        }



};



#endif // TREENODE_H
