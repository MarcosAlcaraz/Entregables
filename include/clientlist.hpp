#ifndef __CLIENTLIST_H__
#define __CLIENTLIST_H__

#include <iostream>
#include "simplynode.hpp"

class ClientList
{
private:
    // ARTRIBUTOS
    SimplyNode *anchor;

public:
    // CONSTRUCTOR
    ClientList(); // E4
    ClientList(const ClientList &); // E4
    ~ClientList(); // (READY) E5

    bool isEmpty();  // E4
    void deleteAll(); // (READY) E5 E6
    void deleteClient(); // (READY) E5 E6
    void insertOrdered(SimplyNode&); // E4 E6 
    bool isValidPos(SimplyNode&); //(READY) Test
    void printList();  // E4

    void readFromDisk(const std::string &);
    void writeToDisk(const std::string &);

    SimplyNode *getFirstPos() const;
    SimplyNode *getLastPos() const;
    SimplyNode *getNextPos() const;
    SimplyNode *getPreviousPos(const SimplyNode &); // (X) E5

    std::string findData(const Client &) const; // (READY) E5

    Client retrieve(SimplyNode&); // (READY)

    void deleteClientList();
};

#endif // __CLIENTLIST_H__