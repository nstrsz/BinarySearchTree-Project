//
// Created by Calin on 21/06/2022.
//

#ifndef PROIECT_FINAL_ORDEREDSET_H
#define PROIECT_FINAL_ORDEREDSET_H


#include "BST.h"

template <class T>
class OrderedSet {
private:
    BST<T> bst;
public:
    ///Constructor implicit
    OrderedSet() = default;

    ///Functia adauga un element in multime
    void add(T value){
        bst.add(value);
    }

    vector<T> getAll(){
        return bst.getAll();
    }

    void del(T value){
        bst.del(value);
    }

    bool search(T value){
        return bst.search(value);
    }

    ~OrderedSet() = default;
};


#endif //PROIECT_FINAL_ORDEREDSET_H
