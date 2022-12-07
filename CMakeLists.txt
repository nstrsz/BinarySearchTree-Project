cmake_minimum_required(VERSION 3.21)
project(Proiect_Final)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proiect_Final main.cpp TAD/List.h Domain/User.h Tests/Tests.cpp Tests/Tests.h TAD/BSTNode.h TAD/BST.h Domain/Friendship.h Domain/Message.h Repository/FriendshipRepository.h Repository/UserRepository.h Repository/MessageRepository.h Service/UserService.h Service/FriendshipService.h Service/MessageService.h Time.h UI/UI.cpp UI/UI.h TAD/OrderedSet.h)
