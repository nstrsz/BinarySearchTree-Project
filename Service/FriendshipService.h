//
// Created by Calin on 23/05/2022.
//

#ifndef PROIECT_FINAL_FRIENDSHIPSERVICE_H
#define PROIECT_FINAL_FRIENDSHIPSERVICE_H


#include "../Repository/FriendshipRepository.h"

class FriendshipService {
private:
    FriendshipRepository repo;
public:
    ///Constructor fara parametrii
    FriendshipService() = default;

    ///Constructor cu parametrii
    FriendshipService(FriendshipRepository repo){
        this->repo = repo;
    }

    ///Functia adauga o prietenie
    bool add(int id1, int id2){
        Friendship friendship(id1, id2);
        Friendship friendship1(id2, id1);
        if(repo.search(friendship) == false && repo.search(friendship1) == false)
        {
            repo.add(friendship);
            return true;
        }
        else
            return false;
    }

    ///Functia returneaza toate prieteniile pentru un id
    List<Friendship> allFriendshipsForId(int id){
        List<Friendship> f = repo.getAll();
        List<Friendship> rez;
        for(int i=0; i<repo.getSize(); i++)
            if(f[i].getIdUser1() == id || f[i]. getIdUser2() == id)
                rez.addElem(f[i]);
        return rez;
    }

    ///Functia sterge o prietenie
    bool del(int id1, int id2){
        Friendship f1(id1,id2);
        Friendship f2(id2, id1);
        if(repo.search(f1) == true){
            repo.del(f1);
            return true;
        }
        else if(repo.search(f2) == true){
            repo.del(f2);
            return true;
        }
        else
            return false;
    }

    ///Destructor
    ~FriendshipService() = default;
};


#endif //PROIECT_FINAL_FRIENDSHIPSERVICE_H
