//Librer�as del compilador
#include <iostream>
//Librer�as de usuario
#include "agent.hpp"

using namespace std;

//Constructor normalito
Agent::Agent() {
    //No coloco los Strings causa de que estos ya se inicalizan vac�os.
    extraHours = NULL;
}

//Constructor un poco menos normalito
Agent::Agent (const Agent& a) : extensionNumber(a.extensionNumber), specialty(a.specialty), employeeNumber(a.employeeNumber), extraHours(a.extraHours), name(a.name), startTime(a.startTime), endTime(endTime) {}

//Getters
//Get De N�mero de empleado
string Agent::getEmployeeNumber() const {
    return employeeNumber;
}

//Get de N�mero de Extensi�n
string Agent::getExtensionNumber() const {
    return extensionNumber;
}

//Get de Especialidad
string Agent::getSpecialty() const {
    return specialty;
}

//Get de Horas Extra
int Agent::getExtraHours() const {
    return extraHours;
}

//Get de la clase Nombre
Name Agent::getName() const {
    return Name();
}

//Get de la clase Tiempo para conseguir la hora de Entrada
Time Agent::getStartTime() const {
    return Time();
}

//Get de la clase Tiempo para conseguir la hora de Salida
Time Agent::getEndTime() const {
    return Time();
}

//Get de la lista de clientes
ClientList& Agent::getClientList() {}

//Impresi�n de toda la informaci�n del Agente
string Agent::toString() const {
    char agentInfo[256];
    for(int i = 0; i < 256; i++) {
        agentInfo[i] = NULL;
    }
    sprintf(agentInfo, "Nombre: %s\nEspecialidad: %s\nN�Empleado: %i\nN�Extensi�n: %s\nHora de Entrada: %s\nHora de Salida: %s\nHoras Extra: %i\nLista de Clientes Atendidos:\n%s\n\n", name, specialty, employeeNumber, extensionNumber, startTime, endTime, extraHours,clientList);
    return agentInfo;
}

int Agent::extensionNumberToInt() const
{
    int en = stoi(extensionNumber);
    return en;
}

//Set de N�mero de Extensi�n
void Agent::setExtensionNumber(const string& exn) {
    extensionNumber = exn;
}

//Set de Especialidad
void Agent::setSpeciality(const string& s) {
    specialty = s;
}

//Set de Nombre
void Agent::setName(const Name& n) {
    name = n;
}

//Set de N�mero de Empleado
void Agent::setEmployeeNumber(const string& en) {
    employeeNumber = en;
}

//Set de Horas Extras
void Agent::setExtraHours(const int& exh) {
    extraHours = exh;
}

//Set de Hora de inicio
void Agent::setStartTime(const Time& st) {
    startTime = st;
}

//Set de Hora de salida
void Agent::setEndTime(const Time& et) {
    endTime = et;
}

//Operador Asignaci�n
Agent& Agent::operator = (const Agent& a) {
    extensionNumber = a.extensionNumber;
    specialty = a.specialty;
    employeeNumber = a.employeeNumber;
    extraHours = a.extraHours;
    name = a.name;
    startTime = a.startTime;
    endTime = a.endTime;

    return *this;
}

//Operador Igualdad
bool Agent::operator == (const Agent& a) const {
    return employeeNumber == a.employeeNumber;
}

//Operador Es Diferente
bool Agent::operator != (const Agent& a) const {
    return !(*this == a);
}

//Operador Menor Que
bool Agent::operator < (const Agent& a) const {
    return employeeNumber < a.employeeNumber;
}

//Operador Menor o Igual
bool Agent::operator <= (const Agent& a) const {
    return *this < a || *this == a;
}

//Operador Mayor Que
bool Agent::operator > (const Agent& a) const {
    return !(*this <= a);
}

//Operador Mayor o Igual
bool Agent::operator >= (const Agent& a) const {
    return !(*this < a);
}
