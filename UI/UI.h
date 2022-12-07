//
// Created by Calin on 23/05/2022.
//

#ifndef PROIECT_FINAL_UI_H
#define PROIECT_FINAL_UI_H


#include "../Service/UserService.h"
#include "../Service/MessageService.h"
#include "../Service/FriendshipService.h"

class UI {
private:
    UserService serviceUser;
    MessageService serviceMessage;
    FriendshipService serviceFriendship;

    void addUser();
    void showUsers();
    void updateUser();
    void deleteUser();

    void addMessage();
    void showMessagesOf2Users();
    void deleteMessage();

    void addFriendship();
    void showFriendships();
    void deleteFriendship();

public:
    ///constructor fara parametrii
    UI() = default;

    ///Constructor cu parametrii
    UI(UserService serviceUser, MessageService serviceMessages, FriendshipService serviceFriendship);

    ///Functia afiseaza meniul principal
    void showMainMenu();

    ///Functia afiseaza meniul pentru utilizatori
    void showUsersMenu();

    ///Functia afiseaza meniul pentru mesaje
    void showMessagesMenu();

    //////Functia afiseaza meniul pentru prietenii
    void showFriendshipsMenu();

    ///Consola apeleaza functiile pentru fiecare
    ///optiune data
    void consoleMain();

    void consoleUsers();

    void consoleMessages();

    void consoleFriendships();



    ///Destructor
    ~UI() = default;
};


#endif //PROIECT_FINAL_UI_H
