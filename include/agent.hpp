#ifndef __AGENT_H__
#define __AGENT_H__

//Librerias de Compilador
#include <iostream>
#include <string>

//Librerias de Usuario
#include "clientlist.hpp"
#include "name.hpp"
#include "time.hpp"

//Clase
class Agent
{
private:
    //Atributos

    std::string extensionNumber;
    std::string specialty;
    
    std::string employeeNumber;
    int extraHours;

    Name name;
    Time startTime;
    Time endTime;

    ClientList clientList;

public:
    //Constructores
    Agent();
    Agent(const Agent&);

    ~Agent();
    
    //Getters
    std::string getEmployeeNumber() const;
    int getExtraHours() const;

    Name getName() const;

    std::string getExtensionNumber() const;
    std::string getSpecialty() const;

    Time getStartTime() const;
    Time getEndTime() const;
    
    ClientList& getClientList();

    std::string toString() const;
    int extensionNumberToInt() const;

    //Setters
    void setExtensionNumber (const std::string&);
    void setSpeciality (const std::string&);
    void setName (const Name&);
    void setEmployeeNumber (const std::string&);
    void setExtraHours (const int&);
    void setStartTime (const Time&);
    void setEndTime (const Time&);

    //Operadores relacionales
    Agent& operator = (const Agent&);

    bool operator == (const Agent&) const;
	bool operator != (const Agent&) const;
	bool operator < (const Agent&) const;
	bool operator <= (const Agent&) const;
	bool operator > (const Agent&) const;
	bool operator >= (const Agent&) const;

    //Operadores de flujo
    friend std::ostream& operator << (std::ostream&, const Agent&);
	friend std::ostream& operator >> (std::ostream&, Agent&);
};

#endif // __AGENT_H__