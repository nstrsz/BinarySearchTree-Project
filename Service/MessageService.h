//
// Created by Calin on 23/05/2022.
//

#ifndef PROIECT_FINAL_MESSAGESERVICE_H
#define PROIECT_FINAL_MESSAGESERVICE_H


#include "../Repository/MessageRepository.h"
#include "../Repository/UserRepository.h"

class MessageService {
private:
    MessageRepository repo;
public:
    ///Constructor fara parametrii
    MessageService() = default;

    ///Constructor cu parametrii
    MessageService(MessageRepository repo){
        this->repo = repo;
    }

    ///Adauga un mesaj
    void add(int id1, int id2, string message){
        Message m(id1, id2, message);
        repo.add(m);
    }

    ///Sterge un mesaj
    bool del(int id1, int id2, string message){
        Message m(id1, id2, message);
        if(repo.search(m) == true)
        {
            repo.del(m);
            return true;
        }
        return false;
    }

    ///Creeaza o lista a mesajelor dintre 2 useri
    vector<Message> mesgOfTwoUsers(int id1, int id2){
        List<Message> m = repo.getAll();
        vector<Message> rez;
        for(int i=0; i<m.getSize(); i++)
        {
            if(m[i].getIdUser1() == id1 && m[i]. getIdUser2() == id2)
                rez.push_back(m[i]);
            else if(m[i].getIdUser1() == id2 && m[i]. getIdUser2() == id1)
                rez.push_back(m[i]);
        }

        return rez;
    }

    ~MessageService() = default;

};


#endif //PROIECT_FINAL_MESSAGESERVICE_H
