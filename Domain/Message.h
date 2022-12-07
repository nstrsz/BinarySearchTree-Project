//
// Created by Calin on 22/05/2022.
//

#ifndef PROIECT_FINAL_MESSAGE_H
#define PROIECT_FINAL_MESSAGE_H


#include <string>
#include "../Time.h"

using namespace std;

class Message {
private:
    ///un mesaj are ide-urile user-ilor, mesajul si ora la care a fost trimis
    int idUser1, idUser2;
    string message;
public:
    ///Constructor fara parametrii
    Message() = default;

    ///Constructor cu parametrii
    Message(int idUser1, int idUser2, string message){
        this->idUser1 = idUser1;
        this->idUser2 = idUser2;
        this->message = message;
    }
    ///getteri
    int getIdUser1() const {
        return idUser1;
    }

    int getIdUser2() const {
        return idUser2;
    }

    const string &getMessage() const {
        return message;
    }


    ///setteri
    void setIdUser1(int idUser1) {
        Message::idUser1 = idUser1;
    }

    void setIdUser2(int idUser2) {
        Message::idUser2 = idUser2;
    }

    void setMessage(const string &message) {
        Message::message = message;
    }


    bool operator==(const Message &rhs) const {
        return idUser1 == rhs.idUser1 &&
               idUser2 == rhs.idUser2 &&
               message == rhs.message;
    }

    ///destructor
    ~Message() = default;
};


#endif //PROIECT_FINAL_MESSAGE_H
