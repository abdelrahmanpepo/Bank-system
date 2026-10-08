#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <iostream>
#include <string>
#include "Client.h"
#include "FileManager.h"

using namespace std;

class ClientManager {
public:
    static void printClientMenu();
    static void updatePassword(Person* person);
    static Client* login(int id, string password);
    static bool clientOptions(Client* client);
};

#endif
