//
// Created by Calin on 23/05/2022.
//

#ifndef PROIECT_FINAL_MESSAGEREPOSITORY_H
#define PROIECT_FINAL_MESSAGEREPOSITORY_H


#include "../TAD/List.h"
#include "../Domain/Message.h"
#include <vector>

using namespace std;

class MessageRepository {
private:
    List<Message> messages;
public:
    ///Constructor fara parametrii
    MessageRepository() = default;

    ///Functia adauga un mesaj
    void add(Message message){
        messages.addElem(message);
    }

    ///Functia returneaza mesajele
    List<Message> getAll(){
        return messages;
    }

    ///Functia sterge un mesaj
    bool del(Message message){
        return messages.deleteElem(message);
    }

    ///Functia returneaza numarul de prietenii
    int getSize(){
        return messages.getSize();
    }

    bool search(Message message){
        if(messages.searchElem(message) != -1)
            return true;
        else
            return false;
    }
    ///Destructor
    ~MessageRepository() = default;
};


#endif //PROIECT_FINAL_MESSAGEREPOSITORY_H
