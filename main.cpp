#include <iostream>
#include "TAD/List.h"
#include "Domain/User.h"
#include "Tests/Tests.h"
#include "TAD/BST.h"
#include "Repository/FriendshipRepository.h"
#include "Repository/UserRepository.h"
#include "Service/FriendshipService.h"
#include "Repository/MessageRepository.h"
#include "Service/MessageService.h"
#include "Service/UserService.h"
#include "UI/UI.h"

int main() {

    tests();

    UserRepository userRepo;
    UserService userService(userRepo);

    MessageRepository messageRepo;
    MessageService messageService(messageRepo);

    FriendshipRepository friendshipRepo;
    FriendshipService friendshipService(friendshipRepo);

    userService.add(1, "ana", "femeie", 20);
    userService.add(2, "ionut", "barbat", 22);
    userService.add(3, "bogdan", "barbat", 26);
    userService.add(4, "maria", "femeie", 18);
    userService.add(5, "vasile", "barbat", 15);
    userService.add(6, "alex", "barbat", 21);
    userService.add(7, "calin", "barbat", 19);
    userService.add(8, "vosi", "barbat", 44);
    userService.add(9, "constantin", "barbat", 33);
    userService.add(10, "ilinca", "femeie", 28);
    userService.add(11, "stefana", "femeie", 19);
    userService.add(12, "iulia", "femeie", 20);
    userService.add(13, "emanuel", "barbat", 16);
    userService.add(14, "serban", "barbat", 12);
    userService.add(15, "larisa", "femeie", 65);

    friendshipService.add(1,2);
    friendshipService.add(1,3);
    friendshipService.add(2,3);
    friendshipService.add(4,5);
    friendshipService.add(4,6);
    friendshipService.add(5,6);
    friendshipService.add(7,8);
    friendshipService.add(7,9);
    friendshipService.add(8,9);
    friendshipService.add(10,11);
    friendshipService.add(10,12);
    friendshipService.add(11,12);
    friendshipService.add(13,14);
    friendshipService.add(14,15);
    friendshipService.add(15,13);

    messageService.add(1,2,"heey");
    messageService.add(2,1,"buna");
    messageService.add(1,2,"ai vazut notele la SDA?");
    messageService.add(1,3,"salutare, esti bine?");
    messageService.add(3,1,"nu prea..");
    messageService.add(1,3,"ce s-a intamplat?");
    messageService.add(2,3,"ai ajuns acasa cu bine?");
    messageService.add(3,2,"dada");
    messageService.add(3,2,"la tine e totul in regula?");
    messageService.add(5,4,"imi trimiti tema la analiza te rog?" );
    messageService.add(4,5,"nu o am nici eu");
    messageService.add(5,4,"sigur o are Radu atunci");
    messageService.add(4,6,"sunt super obosit de la sesiune");
    messageService.add(6,4,"mda, asa si eu");
    messageService.add(4,6,"abia astept sa se termine");
    messageService.add(5,6,"misto rau petrecerea de ieri, mai facem");
    messageService.add(6,5,"claar");
    messageService.add(6,5,"sa scapam de sesiunea asta");
    messageService.add(7,8,"sunt maxim fericit");
    messageService.add(7,8,"am luat 10 la SDA");
    messageService.add(8,7,"Bravooo, eu am luat 9");
    messageService.add(9,7,"am auzit ca ai luat 10 la SDA, ai putea sa ma ajuti si pe mine?");
    messageService.add(7,9,"sigur, tu nu l-ai luat?");
    messageService.add(9,7,"din pacate nu:(");
    messageService.add(10,11,"mergem la mare pana la urma?");
    messageService.add(11,10,"am gasit si cazare deja");
    messageService.add(11,10,"mai trebuie sa vorbesc cu inca 2 prieteni si fac rezervarea");
    messageService.add(10,12,"ce dor imi e de tine");
    messageService.add(12,10,"si mie, abia astept sa ne vedem");
    messageService.add(10,12,"as putea poimaine eu!!");
    messageService.add(11,12,"deci vi la mare?");
    messageService.add(12,11,"clar");
    messageService.add(11,12,"perfect");
    messageService.add(13,14,"esti bine?");
    messageService.add(13,14,"nu te am mai vazut de saptamana trecuta de la fotbal");
    messageService.add(13,14,"raspunde te rog, sunt ingrijorat");
    messageService.add(13,15,"salutare, nu stii nimic de serban?");
    messageService.add(15,13,"nu am ami vorbit nici eu cu el de ceva vreme");
    messageService.add(13,15,"hmm, sper sa fie bine");
    messageService.add(15,14,"toate bune? mi-a zis Manu ca nu da de tine");
    messageService.add(14,15,"totul ok, m-am certat cu el si nu vreau sa vorbim");
    messageService.add(15,14,"in regula");


    UI ui(userService, messageService, friendshipService);
    ui.consoleMain();

    return 0;
}
