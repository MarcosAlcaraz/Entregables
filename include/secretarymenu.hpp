#ifndef __SECRETARYMENU_H__
#define __SECRETARYMENU_H__

#include<iostream>
#include<string>

#include "agentlist.hpp"
#include "clientlist.hpp"
#include "agent.hpp"
#include "client.hpp"
#include "name.hpp"
#include "time.hpp"

class SecretaryMenu
{
private:
    AgentList aList;

public:
    //CONSTRUCTOR
    SecretaryMenu();
    //SecretaryMenu(AgentList*);
    
    //MAIN MENU
    void mainMenu();

    //AGENT MENUs MANAGER
    void addAgent(); // (READY) E9
    void delAgent(); // (READY) E9
    void showAgentList(); // (READY) E9
    void sornAgentList();
    void findAgent(); // (READY) E9
    void modAgent(); // (READY) E9

    //CLIENT MENUs MANAGER
    void addClientToAgent(); // (READY)
    void deleteClientToAgent(); // (READY)
    void modAtDrtnToAgent(); // (READY) E6

    //DISK MENUs
    void saveLists();
    void loadLists();

    void pause();

};
#endif // __SECRETARYMENU_H__