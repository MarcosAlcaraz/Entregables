#include <iostream>
#include "agentlist.hpp"

using namespace std;


AgentList::AgentList() : anchor(nullptr) { } // E7

AgentList::AgentList(const AgentList&) : anchor(nullptr) { }

AgentList::~AgentList()
{
    deleteAll();
}

void AgentList::insertAgent(DoubleNode& nuevoAgente) // E7
{
    nuevoAgente.setNext(anchor); //nuevoAgente apunta a lo que apunta anchor
    anchor = &nuevoAgente;
}

bool AgentList::isEmpty() // E7
{
    return anchor == nullptr;
}

bool AgentList::isValidPos(DoubleNode& p)
{
    if(&p == nullptr)
    {
        return false;
    } else {
        return true;
    }
}

string AgentList::toString() // E7
{
    DoubleNode *printlist = nullptr;
    printlist = anchor;
    char myString[4096];
    string m;
    for(int i = 1; printlist != nullptr; i++)
    {
        sprintf(myString, "(%i) %s", printlist->getData().toString());
        printlist = printlist->getNext();
    }
    return myString;
}

void AgentList::deleteAll()
{
    DoubleNode* aux = nullptr;
    
    while (anchor != nullptr)
    {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

void AgentList::deleteNode(DoubleNode* del)
{
    delete del;
}

void AgentList::sornList()
{
    //Aquí va un método de ordenamiento recursivo para los agentes.
}

void AgentList::readFromDisk(const std::string&)
{
    //Lee de un archivo
}

void AgentList::writeToDisk(const std::string&)
{
    //Escribe en un archivo
}

DoubleNode* AgentList::getFirstPos() const
{
    return anchor;
}

DoubleNode* AgentList::getLastPos() const
{
    if(isEmpty) 
    {
        return nullptr;
    }

    DoubleNode * aux = anchor;

    do
    {
        if ( aux->getNext() == nullptr )
        {
            return aux;
        }
        aux = aux->getNext();
    } while ( aux->getNext() == nullptr );
    
}

DoubleNode* AgentList::getNextPos(DoubleNode & p) const
{
    return p.getNext();
}

DoubleNode* AgentList::getPreviousPos(DoubleNode & p) const
{
    return p.getprev();
}

DoubleNode* AgentList::findData(DoubleNode& p)
{
    if(!(isValidPos(p)))
    {
        return nullptr;
    }

    DoubleNode * aux = anchor;

    do {
        if( aux->getData().extensionNumberToInt() == p.getData().extensionNumberToInt() )
        {
            return aux;
        } else {
            aux = aux->getNext();
        }
    } while (aux->getData().extensionNumberToInt() != p.getData().extensionNumberToInt());
}

Agent AgentList::retrieve(DoubleNode& p)
{
    if(!(isValidPos(p)))
    {
        Agent aux;
        return aux;
    }
    return p.getData();
}