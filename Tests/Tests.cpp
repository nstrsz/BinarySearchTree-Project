//
// Created by Calin on 10/05/2022.
//

#include <cassert>
#include "Tests.h"
#include "../Domain/User.h"
#include "../TAD/List.h"
#include "../Domain/Message.h"
#include "../Domain/Friendship.h"
#include "../TAD/BST.h"
#include "../Repository/MessageRepository.h"
#include "../Repository/FriendshipRepository.h"
#include "../Service/MessageService.h"
#include "../Service/FriendshipService.h"
#include "../TAD/OrderedSet.h"
#include "../Service/UserService.h"

void testUser(){
    User u1(1,"Calin", "barbat", 19);
    User u2(2, "Stefana", "femeie", 21);
    User u3(3, "Serban", "barbat", 20);

    assert(u1.getId() == 1);
    assert(u1.getUserName() == "Calin");
    assert(u1.getGender() == "barbat");
    assert(u1.getAge() == 19);

    assert(u2.getId() == 2);
    assert(u2.getUserName() == "Stefana");
    assert(u2.getGender() == "femeie");
    assert(u2.getAge() == 21);

    assert(u3.getId() == 3);
    assert(u3.getUserName() == "Serban");
    assert(u3.getGender() == "barbat");
    assert(u3.getAge() == 20);


}

void testMessage(){
    Message m1(1,2,"salut");
    Message m2(2,3,"hello");
    Message m3(2,1,"salutare, nu am mai vorbit de mult!");

    assert(m1.getIdUser1() == 1);
    assert(m1.getIdUser2() == 2);
    assert(m1.getMessage() == "salut");

    assert(m2.getIdUser1() == 2);
    assert(m2.getIdUser2() == 3);
    assert(m2.getMessage() == "hello");

    assert(m3.getIdUser1() == 2);
    assert(m3.getIdUser2() == 1);
    assert(m3.getMessage() == "salutare, nu am mai vorbit de mult!");


}

void testFriendship(){
    Friendship f1(1,2);
    Friendship f2(1,3);
    Friendship f3(2,3);

    assert(f1.getIdUser1() == 1);
    assert(f1.getIdUser2() == 2);

    assert(f2.getIdUser1() == 1);
    assert(f2.getIdUser2() == 3);

    assert(f3.getIdUser1() == 2);
    assert(f3.getIdUser2() == 3);

}

void testList(){
    List<int> numbers;
    List<Message> messages;
    List<Friendship> friendships;

    ///teste pentru lista folosind tipul de data int
    numbers.addElem(1);
    numbers.addElem(2);
    numbers.addElem(3);

    assert(numbers.getSize() == 3);
    assert(numbers[0] == 1);
    assert(numbers[1] == 2);
    assert(numbers[2] == 3);
    numbers.deleteElem(3);
    numbers.updateElem(1,4);
    assert(numbers.getSize() == 2);
    assert(numbers[0] == 4);
    assert(numbers[1] == 2);

    ///teste pentru lista folosind tipul de data Message
    Message m1(1,2,"salut");
    Message m2(2,3,"hello");
    Message m3(2,1,"salutare, nu am mai vorbit de mult!");

    messages.addElem(m1);
    messages.addElem(m2);
    messages.addElem(m3);

    assert(messages.getSize() == 3);
    assert(messages[0].getIdUser1() == 1);
    assert(messages[1].getIdUser1() == 2);
    assert(messages[2].getIdUser1() == 2);
    messages.deleteElem(m3);
    assert(messages.getSize() == 2);
    assert(messages[0].getIdUser1() == 1);
    assert(messages[1].getIdUser1() == 2);

    ///teste pentru lista folosind tipul de data Friendship
    Friendship f1(1,2);
    Friendship f2(1,3);
    Friendship f3(2,3);
    Friendship f4(4,5);

    friendships.addElem(f1);
    friendships.addElem(f2);
    friendships.addElem(f3);

    assert(friendships.getSize() == 3);
    assert(friendships[0] == f1);
    assert(friendships[1] == f2);
    assert(friendships[2] == f3);
    friendships.deleteElem(f2);
    friendships.updateElem(f1,f4);
    assert(friendships.getSize() == 2);
    assert(friendships[0] == f4);
    assert(friendships[1] == f3);

}

void testBST(){
    BST<int> numbers;
    BST<User> users;

    ///teste pentru arborele binar de cautare folosind tipul de data int
    numbers.add(1);
    numbers.add(2);
    numbers.add(4);
    numbers.add(3);

    vector<int> rez = numbers.getAll();

    assert(rez.size() == 4);
    assert(rez[0] == 1);
    assert(rez[1] == 2);
    assert(rez[2] == 3);
    assert(rez[3] == 4);

    numbers.del(1);

    rez = numbers.getAll();

    assert(rez.size() == 3);
    assert(rez[0] == 2);
    assert(rez[1] == 3);
    assert(rez[2] == 4);

    ///teste pentru arborele binar de cautare folosind tipul de data User
    User u1(1,"Calin", "barbat", 19);
    User u2(2, "Stefana", "femeie", 21);
    User u3(3, "Serban", "barbat", 20);
    User u4(4, "Ionut", "barbat", 12);

    users.add(u4);
    users.add(u2);
    users.add(u3);
    users.add(u1);

    vector<User> rezU = users.getAll();

    assert(rezU.size() == 4);
    assert(rezU[0] == u1);
    assert(rezU[1] == u2);
    assert(rezU[2] == u3);
    assert(rezU[3] == u4);

    users.del(u2);
    rezU = users.getAll();

    assert(rezU.size() == 3);
    assert(rezU[0] == u1);
    assert(rezU[1] == u3);
    assert(rezU[2] == u4);

}

void testOrderedSet(){
    OrderedSet<int> numbers;
    OrderedSet<User> users;

    ///teste pentru multimea ordonata folosind tipul de data int
    numbers.add(1);
    numbers.add(2);
    numbers.add(4);
    numbers.add(3);

    vector<int> rez = numbers.getAll();

    assert(rez.size() == 4);
    assert(rez[0] == 1);
    assert(rez[1] == 2);
    assert(rez[2] == 3);
    assert(rez[3] == 4);

    numbers.del(1);

    rez = numbers.getAll();

    assert(rez.size() == 3);
    assert(rez[0] == 2);
    assert(rez[1] == 3);
    assert(rez[2] == 4);

    ///teste pentru multimea ordonata folosind tipul de data User
    User u1(1,"Calin", "barbat", 19);
    User u2(2, "Stefana", "femeie", 21);
    User u3(3, "Serban", "barbat", 20);
    User u4(4, "Ionut", "barbat", 12);

    users.add(u4);
    users.add(u2);
    users.add(u3);
    users.add(u1);

    vector<User> rezU = users.getAll();

    assert(rezU.size() == 4);
    assert(rezU[0] == u1);
    assert(rezU[1] == u2);
    assert(rezU[2] == u3);
    assert(rezU[3] == u4);

    users.del(u2);
    rezU = users.getAll();

    assert(rezU.size() == 3);
    assert(rezU[0] == u1);
    assert(rezU[1] == u3);
    assert(rezU[2] == u4);
}

void testMessageRepository(){
    MessageRepository messages;

    Message m1(1,2,"salut");
    Message m2(2,3,"hello");
    Message m3(2,1,"salutare, nu am mai vorbit de mult!");

    messages.add(m1);
    messages.add(m2);
    messages.add(m3);

    assert(messages.getSize() == 3);
    assert(messages.search(m1) == true);
    assert(messages.search(m2) == true);
    assert(messages.search(m3) == true);

    messages.del(m2);

    assert(messages.getSize() == 2);
    assert(messages.search(m1) == true);
    assert(messages.search(m2) == false);
    assert(messages.search(m3) == true);


}

void testFriendshipRepository(){
    FriendshipRepository friendships;

    Friendship f1(1,2);
    Friendship f2(1,3);
    Friendship f3(2,3);
    Friendship f4(4,3);

    friendships.add(f1);
    friendships.add(f2);
    friendships.add(f3);

    assert(friendships.getSize() == 3);
    assert(friendships.search(f1) == true);
    assert(friendships.search(f2) == true);
    assert(friendships.search(f3) == true);
    assert(friendships.search(f4) == false);

    friendships.del(f3);
    friendships.update(f2,f4);

    assert(friendships.getSize() == 2);
    assert(friendships.search(f1) == true);
    assert(friendships.search(f3) == false);
    assert(friendships.search(f4) == true);

}

void testUserRepository(){
    UserRepository users;

    User u1(1, "Calin", "barbat", 19);
    User u2(2, "Stefana", "femeie", 21);
    User u3(3, "Serban", "barbat", 20);
    User u4(4, "Ionut", "barbat", 12);

    users.add(u4);
    users.add(u2);
    users.add(u3);
    users.add(u1);

    vector<User> rezU = users.getAll();

    assert(rezU.size() == 4);
    assert(rezU[0] == u1);
    assert(rezU[1] == u2);
    assert(rezU[2] == u3);
    assert(rezU[3] == u4);

    users.del(u2);
    rezU = users.getAll();

    assert(rezU.size() == 3);
    assert(rezU[0] == u1);
    assert(rezU[1] == u3);
    assert(rezU[2] == u4);

}
void testMessageService(){
    MessageRepository repo;
    MessageService messageService(repo);

    messageService.add(1,2,"salut");
    messageService.add(2,1,"buna");
    messageService.add(3,2,"NU CRED");
    messageService.add(1,2,"cum mai esti?");

    vector<Message> messages = messageService.mesgOfTwoUsers(1,2);

    assert(messages.size() == 3);
    assert(messages[0].getMessage() == "salut");
    assert(messages[1].getMessage() == "buna");
    assert(messages[2].getMessage() == "cum mai esti?");


    messageService.del(1,2,"cum mai esti?");
    messages = messageService.mesgOfTwoUsers(1,2);

    assert(messages.size() == 2);
    assert(messages[0].getMessage() == "salut");
    assert(messages[1].getMessage() == "buna");


}

void testFriendshipService(){
    FriendshipRepository repo;
    FriendshipService friendshipService(repo);

    Friendship f1(1,2);
    Friendship f2(3,1);
    Friendship f3(4,1);

    friendshipService.add(1,2);
    friendshipService.add(2,1);
    friendshipService.add(3,1);
    friendshipService.add(4,1);

    List<Friendship> rez = friendshipService.allFriendshipsForId(1);

    assert(rez.getSize() == 3);
    assert(rez[0] == f1);
    assert(rez[1] == f2);
    assert(rez[2] == f3);

    friendshipService.del(2,1);

    rez = friendshipService.allFriendshipsForId(1);
    assert(rez.getSize() == 2);
    assert(rez[0] == f2);
    assert(rez[1] == f3);


}
void testUserService(){
    UserRepository repo;
    UserService userService(repo);

    User u1(1, "Calin", "barbat", 19);
    User u2(2, "Stefana", "femeie", 21);
    User u3(3, "Serban", "barbat", 20);
    User u4(4, "Ionut", "barbat", 12);
    User u5(4, "Ionut", "barbatALFA", 20);

    userService.add(1, "Calin", "barbat", 19);
    userService.add(2, "Stefana", "femeie", 21);
    userService.add(3, "Serban", "barbat", 20);
    userService.add(4, "Ionut", "barbat", 12);

    vector<User> rez = userService.getAll();

    assert(rez.size() == 4);
    assert(rez[0] == u1);
    assert(rez[1] == u2);
    assert(rez[2] == u3);
    assert(rez[3] == u4);

    userService.del(3, "Serban", "barbat", 20);
    userService.update(4, "Ionut", "barbat", 12, 4, "Ionut", "barbatALFA", 20);

    rez = userService.getAll();
    assert(rez.size() == 3);
    assert(rez[0] == u1);
    assert(rez[1] == u2);
    assert(rez[2] == u5);
};

void tests(){
    testUser();
    testMessage();
    testFriendship();
    testList();
    testBST();
    testOrderedSet();
    testMessageRepository();
    testFriendshipRepository();
    testUserRepository();
    testMessageService();
    testFriendshipService();
    testUserService();
}