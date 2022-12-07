//
// Created by Calin on 22/05/2022.
//

#ifndef PROIECT_FINAL_FRIENDSHIPREPOSITORY_H
#define PROIECT_FINAL_FRIENDSHIPREPOSITORY_H

#include "../Domain/Friendship.h"
#include "../TAD/List.h"

class FriendshipRepository {
private:
    List<Friendship> friendships;
public:
    ///Constructor fara parametrii
    FriendshipRepository() = default;

    ///Functia adauga o prietenie in lista de prietenii
    void add(Friendship friendship){
        friendships.addElem(friendship);
    }

    ///Functia returneaza lista de prietenii
    List<Friendship> getAll(){
        return friendships;
    }

    ///Functia actualizeaza o prietenie in lista de prietenii
    bool update(Friendship friendship, Friendship newFriendship){
        return friendships.updateElem(friendship, newFriendship);
    }

    ///Functia sterge o prietenie din lista de prietenii
    bool del(Friendship friendship){
        if(friendships.searchElem(friendship) == -1)
            return false;
        else
            friendships.deleteElem(friendship);
            return true;
    }

    ///Functia returneaza numarul de prietenii
    int getSize(){
        return friendships.getSize();
    }

    ///Functia cauta o prietenie
    bool search(Friendship friendship){
        if(friendships.searchElem(friendship) == -1)
            return false;
        else
            return true;
    }
    ///Destructor
    ~FriendshipRepository() = default;
};


#endif //PROIECT_FINAL_FRIENDSHIPREPOSITORY_H
