//
// Created by Calin on 10/05/2022.
//

#ifndef PROIECT_FINAL_USER_H
#define PROIECT_FINAL_USER_H

#include <iostream>
using namespace std;

class User {
private:
    int id, age;
    string userName, gender;
public:
    ///constructor fara parametrii
    User() = default;

    ///constructor cu parametrii
    User(int id, string userName, string gender,int age ){
        this->id = id;
        this->userName = userName;
        this->age = age;
        this->gender = gender;
    }

    ///getteri
    int getId() const {
        return id;
    }

    const string &getUserName() const {
        return userName;
    }

    const string &getGender() const {
        return gender;
    }

    int getAge() const {
        return age;
    }

    ///setteri
    void setId(int id) {
        User::id = id;
    }

    void setUserName(const string &userName) {
        User::userName = userName;
    }

    void setGender(const string &gender) {
        User::gender = gender;
    }

    void setAge(int age) {
        User::age = age;
    }

    ///Suprasincarcamm operatorul >
    bool operator>(const User &user){
        if(this->id > user.id)
            return true;
        else
            return false;
    }

    ///Supraincarcare operatorul <
    bool operator<(const User &user){
        if(this->id < user.id)
            return true;
        else
            return false;
    }

    ///Supraincarcare operatorul ==
    bool operator==(const User &rhs) const {
        return id == rhs.id &&
               age == rhs.age &&
               userName == rhs.userName &&
               gender == rhs.gender;
    }

    ~User() = default;
};


#endif //PROIECT_FINAL_USER_H
