//
// Created by Calin on 22/05/2022.
//

#ifndef PROIECT_FINAL_FRIENDSHIP_H
#define PROIECT_FINAL_FRIENDSHIP_H


class Friendship {
private:
    ///id-urile userilor intre care se stabileste o prietenie
    int idUser1, idUser2;
public:

    ///Constructor fara parametrii
    Friendship() = default;

    ///Constructor cu parametrii
    Friendship(int idUser1, int idUser2){
        this->idUser1 = idUser1;
        this->idUser2 = idUser2;
    }

    ///getteri
    int getIdUser1(){
        return idUser1;
    }

    int getIdUser2(){
        return idUser2;
    }

    ///setteri
    void setIdUser1(int id){
        this->idUser1 = id;
    }

    void setIdUser2(int id){
        this->idUser1 = id;
    }

    ///Supraincarcare operatorul ==
    bool operator==(const Friendship &friendship){
        if(this->idUser1 == friendship.idUser1 && this->idUser2 == friendship.idUser2)
            return true;
        return false;
    }

    ///Supraincarcare operatorul =
    Friendship& operator=(const Friendship &friendship){
        if(this != &friendship){
            this->idUser1 = friendship.idUser1;
            this->idUser2 = friendship.idUser2;
        }
        return *this;
    }

    ///Destructor
    ~Friendship() = default;
};


#endif //PROIECT_FINAL_FRIENDSHIP_H
