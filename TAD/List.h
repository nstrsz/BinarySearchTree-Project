//
// Created by Calin on 10/05/2022.
//

#ifndef PROIECT_FINAL_LIST_H
#define PROIECT_FINAL_LIST_H


template <class T>
class List {
private:
    int nrElems;
    int size;
    T* array;
    ///Verifica daca numarul de elemente este egal cu lungimea array-ului caz in care dubleaza lungimea
    void increaseSize(){
        if(nrElems == size){
            T* newArray = new T[size*2];
            for(int i=0; i<size; i++)
                newArray[i] = array[i];
            size *= 2;
            delete[] array;
            array = newArray;
        }
    }
public:
    ///Constructorul implicit
    List(){
        nrElems = 0;
        size = 10;
        array = new T[size];
    }

    ///Adauga un element in array
    void addElem(T elem){
        increaseSize();
        array[nrElems++] = elem;
    }
    ///Cauta un element dat in array
    int searchElem(T elem){
        for(int i=0; i < nrElems; i++)
            if(array[i] == elem)
                return i;
        return -1;
    }
    ///Sterge un element din array daca acesta exista
    bool deleteElem(T elem){
        int position = searchElem(elem);
        if(array[position] == elem){
            for(int i = position; i < nrElems-1;  i++)
                array[i] = array[i+1];
            nrElems--;
            return true;
        }
        return false;
    }
    ///Updateaza un element in array daca acesta exista
    bool updateElem(T elem, T newElem){
        int position = searchElem(elem);
        if(array[position] == elem){
            array[position] = newElem;
            return true;
        }
        return false;
    }
    ///Returneaza numarul de elemente din array
    int getSize(){
        return nrElems;
    }

    ///Supraincarcare operatorul []
    T operator[](int index){
        return array[index];
    };

    ///Destructorul array-ului
    ~List() = default;
};

#endif //PROIECT_FINAL_LIST_H
