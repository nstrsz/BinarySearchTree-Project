//
// Created by Calin on 21/05/2022.
//

#ifndef PROIECT_FINAL_BSTNODE_H
#define PROIECT_FINAL_BSTNODE_H

using namespace std;

template <class T>
class BST;

template <class T>
class BSTNode {
private:
    /// Atributele nodului unui arbore binar
    T value;
    BSTNode<T>* left;
    BSTNode<T>* right;
public:
    /// Constructor implicit
    BSTNode() = default;

    /// Constructor cu parametru
    BSTNode(T value){
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    /// Constructor cu parametrii
    BSTNode(T value, BSTNode<T>* left, BSTNode<T>* right){
        this->value = value;
        this->left = left;
        this->right = right;
    }
    /// Destructor
    ~BSTNode() = default;


    friend class BST<T>;
};


#endif //PROIECT_FINAL_BSTNODE_H
