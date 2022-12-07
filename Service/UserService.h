//
// Created by Calin on 23/05/2022.
//

#ifndef PROIECT_FINAL_USERSERVICE_H
#define PROIECT_FINAL_USERSERVICE_H


#include "../Repository/UserRepository.h"

class UserService {
private:
    UserRepository repo;
public:
    ///Constructor fara parametrii
    UserService() = default;

    ///Constructor cu parametrii
    UserService(UserRepository repo){
        this->repo = repo;
    }

    ///Functia adauga un user in repository
    bool add(int id, string userName, string gender, int age){
        User user(id, userName, gender, age);
        if(repo.search(user) == false)
        {
            repo.add(user);
            return true;
        }
        else
            return false;
    }

    ///Functia returneaza o lista cu toti userii
    vector<User> getAll(){
        return repo.getAll();
    }

    ///Functia actualizeaza un user
    bool update(int id, string userName, string gender, int age,int newId, string newUserName, string newGender, int newAge){
        User user(id, userName, gender, age);
        User newUer(newId, newUserName, newGender, newAge);
        if(repo.search(user) == true)
        {
            repo.del(user);
            repo.add(newUer);
            return true;
        }
        else
            return false;
    }
    ///Functia sterge un utilizator
    bool del(int id, string userName, string gender, int age){
        User user(id, userName, gender, age);
        if(repo.search(user) == true)
        {
            repo.del(user);
            return true;
        }
        else
            return false;
    }

    ///Functia verifica daca exista un id in lista de useri
    bool searchById(int id){
        vector<User> u = repo.getAll();
        for(int i=0; i<u.size(); i++)
            if(u[i].getId() == id)
                return true;
        return false;
    }

    User returnById(int id){
        vector<User> u = repo.getAll();
        for(int i=0; i<u.size(); i++)
            if(u[i].getId() == id)
                return u[i];
    }
    ~UserService() = default;
};


#endif //PROIECT_FINAL_USERSERVICE_H
