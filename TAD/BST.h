//
// Created by Calin on 22/05/2022.
//

#ifndef PROIECT_FINAL_BST_H
#define PROIECT_FINAL_BST_H

#include "BSTNode.h"
#include <vector>

using namespace std;

template <class T>
class BST {
private:
    ///arborele are ca atribut radacina sa
    BSTNode<T>* root;

    ///Adaugarea unui element e face parcurgand recursiv toate nodurile
    ///pana cand se gaseste locul pentru a adauga elementul dat
    void addNode(BSTNode<T>* node, T elem) {
        if (node->value > elem) {
            if (node->left != nullptr) {
                addNode(node->left, elem);
            }
            else {
                node->left = new BSTNode<T>(elem, nullptr, nullptr);
            }
        } else {
            if (node->right != nullptr) {
                addNode(node->right, elem);
            }
            else {
                node->right = new BSTNode<T>(elem, nullptr, nullptr);
            }
        }
    }
    /// Functia returneaza o lista ordonata cu toate elementele arborelui
    vector<T> getAll(BSTNode<T>* node, vector<T>& elems){
        if(node){
            getAll(node->left,elems);
            elems.push_back(node->value);
            getAll(node->right, elems);
        }
        return elems;
    }

    ///Actualizarea se face parcurgand recursiv toate nodurile de sub radacina
    ///pana cand se gaseste nodul cu informatia ce trebuie actualizata
    bool updateNode(BSTNode<T>* node, T value, T newValue){
        if(node == nullptr) return false;
        else if(node->value == value){
            node->value == newValue;
            return true;
        }
        else if(value <= node->value)
            return update(node->left, value, newValue);
        else
            return update(node->right, value, newValue);
    }

    /// Functia sterge un nod ce contine valoarea data din arbore
    BSTNode<T>* deleteNode(BSTNode<T>* node,T value){
        if(node == nullptr) return node;
        if(value < node->value){
            node->left = deleteNode(node->left, value);
        }
        else if(value > node->value){
            node->right = deleteNode(node->right, value);
        }
        else{
            if(node->left == nullptr && node->right == nullptr){
                if(this->root->value == node->value)
                    this->root = nullptr;
                return nullptr;
            }
            else if(node->right == nullptr){
                if(this->root == node)
                    this->root = node->left;
                node = node->left;
                return node;
            }
            else if( node->left == nullptr){
                if(this->root == node)
                    this->root = node->right;
                node = node->right;
                return node;
            }
            BSTNode<T>* aux = findMin(node->right);
            node->value = aux->value;
            node->right = deleteNode(node->right, aux->value);
            if(this->root == nullptr)
                this->root = node;
        }
        return node;
    }

    /// Functia returneaza un pointer catre nodul cu cel mai mic element
    /// dintr-un arbore sau subarbore
    BSTNode<T>* findMin(BSTNode<T>* node){
        while(node->left)
            this->root = node;
        return node;
    }

    /// Functia determina daca o valoare se afla sau nu in arbore
    bool searchValue(BSTNode<T> *node, T value){
        if(node == nullptr)
            return false;
        else if(value == node->value)
            return true;
        else if(value < node->value)
            return searchValue(node->left, value);
        else
            return searchValue(node->right, value);
    }

public:

    /// Constructor fara parametrii
    BST(){
        this->root = nullptr;
    };

    /// Functia adauga un element in arbore
    void add(T value){
        if(this->root == nullptr)
            this->root = new BSTNode<T>(value);
        else
            addNode(this->root, value);
    }

    /// Functia returneaza un vector cu elementele arborelui ordonate
    vector<T> getAll(){
        vector<T> elems;
        getAll(this->root, elems);
        return elems;
    }

    /// Functia sterge un element dat din arbore
    void del(T value){
        deleteNode(this->root, value);
    }

    /// Functia determina daca un element se afla in arbore
    bool search(T value){
        return searchValue(this->root, value);
    }

    /// Destructor
    ~BST() = default;
};


#endif //PROIECT_FINAL_BST_H
