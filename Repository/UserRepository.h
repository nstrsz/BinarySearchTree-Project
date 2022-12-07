//
// Created by Calin on 23/05/2022.
//

#ifndef PROIECT_FINAL_USERREPOSITORY_H
#define PROIECT_FINAL_USERREPOSITORY_H

#include "../Domain/User.h"
#include "../TAD/OrderedSet.h"

class UserRepository {
private:
    OrderedSet<User> users;
public:
    ///Constructor fara parametrii
    UserRepository() = default;
    ///Functia adauga un user
    void add(User user){
        users.add(user);
    }

    ///Functia returneaza userii
    vector<User> getAll(){
        return users.getAll();
    }

    ///Functia actualizeaza un user
    void update(User user, User newUser){
        users.del(user);
        users.add(newUser);
    }

    ///Functia sterge un user
    void del(User user){
        users.del(user);
    }

    ///Functia returneaza numarul de useri
    int getSize(){
        vector<User> u = users.getAll();
        return u.size();
    }

    ///Functia cauta un user
    bool search(User user){
        return users.search(user);
    }

    ///Destructor
   ~UserRepository() = default;
};


#endif //PROIECT_FINAL_USERREPOSITORY_H
