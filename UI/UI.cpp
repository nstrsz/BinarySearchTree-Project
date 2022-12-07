//
// Created by Calin on 23/05/2022.
//

#include "UI.h"
#include <iostream>

using namespace std;

UI::UI(UserService serviceUser, MessageService serviceMessages, FriendshipService serviceFriendship) {
    this->serviceUser = serviceUser;
    this->serviceMessage = serviceMessages;
    this->serviceFriendship = serviceFriendship;
}

void UI::showMainMenu() {
    cout<<"-------Meniu Principal-------"<<endl;
    cout<<"1. Meniu utilizatori"<<endl;
    cout<<"2. Meniu relatii de prietenie"<<endl;
    cout<<"3. Meniu mesaje"<<endl;

}

void UI::showUsersMenu() {
    cout<<"-------Meniu Utilizatori-------"<<endl;
    cout<<"1. Adauga utilizator"<<endl;
    cout<<"2. Afiseaza utilizatori"<<endl;
    cout<<"3. Actualizeaza utilizator"<<endl;
    cout<<"4. Sterge utilizator"<<endl;
    cout<<"0. Meniu anterior"<<endl;
}

void UI::showFriendshipsMenu() {
    cout<<"-------Meniu Relatii de Prietenie-------"<<endl;
    cout<<"1. Adauga prietenie"<<endl;
    cout<<"2. Afiseaza prieteniile"<<endl;
    cout<<"3. Sterge prietenie"<<endl;
    cout<<"0. Meniu anterior"<<endl;
}

void UI::showMessagesMenu() {
    cout<<"-------Meniu Mesaje-------"<<endl;
    cout<<"1. Adauga mesaj"<<endl;
    cout<<"2. Afiseaza mesajele dintre 2 utilizatori"<<endl;
    cout<<"3. Sterge mesaj"<<endl;
    cout<<"0. Meniu anterior"<<endl;
}

void UI::consoleMain() {


    int opt = 1;

    while(opt != 0){
        showMainMenu();
        cout<<"~~Dati optiunea: ";
        cin>>opt;
        switch(opt){
            case 1:{consoleUsers(); break;}
            case 2:{consoleFriendships(); break;}
            case 3:{consoleMessages(); break;}
            case 0:{break;}
            default: cout<<"Optiune inexistenta, reincercati!"<<endl;
        }
    }
}

void UI::consoleUsers() {


    int opt = 1;

    while(opt != 0){
        showUsersMenu();
        cout<<"~~Dati optiunea: ";
        cin>>opt;
        switch(opt){
            case 1:{addUser(); break;}
            case 2:{showUsers(); break;}
            case 3:{updateUser(); break;}
            case 4:{deleteUser(); break;}
            case 0:{break;}
            default: cout<<"Optiune inexistenta, reincercati!"<<endl;
        }
    }
}

void UI::consoleMessages() {


    int opt = 1;

    while(opt != 0){
        showMessagesMenu();
        cout<<"~~Dati optiunea: ";
        cin>>opt;
        switch(opt){
            case 1:{addMessage(); break;}
            case 2:{showMessagesOf2Users(); break;}
            case 3:{deleteMessage(); break;}
            case 0:{break;}
            default: cout<<"Optiune inexistenta, reincercati!"<<endl;
        }
    }
}

void UI::consoleFriendships() {


    int opt = 1;

    while(opt != 0){
        showFriendshipsMenu();
        cout<<"~~Dati optiunea: ";
        cin>>opt;
        switch(opt){
            case 1:{addFriendship(); break;}
            case 2:{showFriendships(); break;}
            case 3:{deleteFriendship(); break;}
            case 0:{break;}
            default: cout<<"Optiune inexistenta, reincercati!"<<endl;
        }
    }
}

///Operatii user
void UI::addUser() {
    int id, age;
    string userName,gender;

    cout<<"Dati id-ul: ";
    cin>>id;
    cout<<"Dati userName-ul: ";
    cin>>userName;
    cout<<"Dati genul: ";
    cin>>gender;
    cout<<"Dati varsta: ";
    cin>>age;
    if(serviceUser.searchById(id) == true)
        cout<<"Id existent, reincecati";
    else{
        serviceUser.add(id, userName, gender, age);
        cout<<"Utilizator adaugat!"<<endl;
    }

}

void UI::showUsers() {
    vector<User> u = serviceUser.getAll();
    if(u.size() == 0)
        cout<<"Nu exista utilizatori!";
    else
        for(int i=0; i<u.size(); i++)
            cout<<" *"<<u[i].getId()<<" "<<u[i].getUserName()<<endl;
}

void UI::updateUser() {
    int id, age, id2, age2;
    string userName,gender, userName2, gender2;

    cout<<"Dati id-ul: ";
    cin>>id;
    cout<<"Dati userName-ul: ";
    cin>>userName;
    cout<<"Dati genul: ";
    cin>>gender;
    cout<<"Dati varsta: ";
    cin>>age;

    cout<<"Dati noul id: ";
    cin>>id2;
    cout<<"Dati noul userName: ";
    cin>>userName2;
    cout<<"Dati noul gen: ";
    cin>>gender2;
    cout<<"Dati noua varsta: ";
    cin>>age2;

    bool rez = serviceUser.update(id, userName, gender, age, id2, userName2, gender2, age2);

    if(rez == true)
        cout<<"Actualizare realizata cu succes!"<<endl;
    else
        cout<<"User inexistent!"<<endl;
}

void UI::deleteUser() {
    int id, age;
    string userName,gender;

    cout<<"Dati id-ul: ";
    cin>>id;
    cout<<"Dati userName-ul: ";
    cin>>userName;
    cout<<"Dati genul: ";
    cin>>gender;
    cout<<"Dati varsta: ";
    cin>>age;

    bool rez = serviceUser.del(id, userName, gender, age);

    if(rez == true)
        cout<<"Stergere realizata cu succes!"<<endl;
    else
        cout<<"User inexistent!"<<endl;

}

///Operatii mesaje
void UI::addMessage() {
    int s, r;
    string message;

    cout<<"Dati id-ul expeditorului: ";
    cin>>s;

    cout<<"Dati id-ul destinatarului: ";
    cin>>r;

    cout<<"Dati mesajul: ";
    cin>>message;

    if(serviceUser.searchById(s) && serviceUser.searchById(r)){
        serviceMessage.add(s, r, message);
        cout<<"Mesaj trimis cu succes!"<<endl;
    }
    else
        cout<<"Useri inexistenti!"<<endl;

}

void UI::showMessagesOf2Users() {
    int id1, id2;
    cout<<"Dati id-ul primului utilizator: ";
    cin>>id1;
    cout<<"Dati id-ul celuilalt utilizator: ";
    cin>>id2;

    if(serviceUser.searchById(id1) && serviceUser.searchById(id2)){
        vector<Message> m = serviceMessage.mesgOfTwoUsers(id1, id2);

        for(int i=0; i<m.size(); i++)
        {
            int hour, minute;
            User u = serviceUser.returnById(m[i].getIdUser1());
            cout<<u.getUserName()<<": "<<m[i].getMessage()<<endl;
        }

        if(m.size() == 0)
            cout<<"Nu exista mesaje intre cei 2 utilizatori"<<endl;
    }
    else
        cout<<"Utilizatorii nu exista!"<<endl;
}

void UI::deleteMessage() {
    int sender, reciver;
    string message;

    cout<<"Dati id-ul expeditorului: ";
    cin>>sender;
    cout<<"Dati id-ul destinatarului: ";
    cin>>reciver;
    cout<<"Dati mesajul: ";
    cin>>message;

    bool rez = serviceMessage.del(sender, reciver, message);

    if(rez == true)
        cout<<"Mesajul a fost sters!"<<endl;
    else
        cout<<"Mesaj inexistent!"<<endl;
}

void UI::addFriendship() {
    int id1, id2;

    cout<<"Dati id-ul primului utilizator: ";
    cin>>id1;
    cout<<"Dati id-ul celuilalt utilizator: ";
    cin>>id2;

    bool rez;
    if(serviceUser.searchById(id1) && serviceUser.searchById(id2))
        rez = serviceFriendship.add(id1, id2);

    if(rez == true)
        cout<<"Prietenie creeata!"<<endl;
    else
        cout<<"Utilizatori inexistenti sau prietenie existenta!"<<endl;
}

void UI::showFriendships() {

    vector<User> users = serviceUser.getAll();
    for(int u=0; u<users.size(); u++){
        int id;
        id = users[u].getId();
        cout<<users[u].getUserName()<<": ";

        List<Friendship> friendships = serviceFriendship.allFriendshipsForId(id);

        for(int i=0; i<friendships.getSize(); i++){
            if(friendships[i].getIdUser1() != id){
                int idFr = friendships[i].getIdUser1();
                if(serviceUser.searchById(idFr)){
                    User frnd = serviceUser.returnById(idFr);
                    cout<<frnd.getUserName()<<", ";
                }

            }
            else if(friendships[i].getIdUser2() != id){
                int idFr = friendships[i].getIdUser2();
                if(serviceUser.searchById(idFr)){
                    User frnd = serviceUser.returnById(idFr);
                    cout<<frnd.getUserName()<<", ";
                }

            }
        }
        cout<<endl;
    }
}

void UI::deleteFriendship() {
    int id1, id2;

    cout<<"Dati id-ul primului utilizator: ";
    cin>>id1;
    cout<<"Dati id-ul celuilalt utilizator: ";
    cin>>id2;

    bool rez = serviceFriendship.del(id1,id2);

    if(rez)
        cout<<"Prietenie stearsa!"<<endl;
    else
        cout<<"Utilizatori inexistenti sau prietenie ineexistenta!"<<endl;

}

