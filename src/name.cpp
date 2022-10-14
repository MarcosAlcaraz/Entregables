//Librerias de compilador
#include<iostream>
//Librerias de Usuario
#include "name.hpp"

using namespace std;

//Constructor Normal
Name::Name() {}

//Constructor Menos Normal
Name::Name (const Name& n) {}

//Getters
//Get de Primer Nombre
string Name::getFirstName() const {
    return firstName;
}

//Get de Segundo Nombre
string Name::getSecondName() const {
    return secondName;
}

//Get de Apellido Materno
string Name::getMothersLastName() const {
    return mothersLastName;
}

//Get de Apellido Paterno
string Name::getLastName() const {
    return lastName;
}

//Setters
//Set de Peimer Nombre
void Name::setFirstName(const string& fn) {
    firstName= fn;
}

//Set de Minuto
void Name::setSecondName(const string& sn) {
    secondName = sn;
}

//Set de segundo
void Name::setMothersLastName(const string& mln) {
    mothersLastName = mln;
}

//Set de segundo
void Name::setLastName(const string& ln) {
    lastName = ln;
}

//Impresión de Tiempo
string Name::toString() const {
    char Name[64];
    for(int i = 0; i< 64; i++) {
        Name[i] = NULL;
    }
    sprintf(Name, "%s %s %s %s", mothersLastName, lastName, firstName, secondName);
    return Name;
}

//Operador Asignación
Name& Name::operator = (const Name& n) {
    firstName = n.firstName;
    secondName = n.secondName;
    mothersLastName = n.mothersLastName;
    lastName = n.lastName;

    return *this;
}

//Operador Igualdad
bool Name::operator == (const Name& t) const {
    return toString() == t.toString();
}

//Operador Es Diferente
bool Name::operator != (const Name& t) const {
    return toString() != t.toString();
}

//Operador Menor Que
bool Name::operator < (const Name& t) const {
    return toString() < t.toString();
}

//Operador Menor o Igual
bool Name::operator <= (const Name& t) const {
    return *this < t || *this == t;
}

//Operador Mayor Que
bool Name::operator > (const Name& t) const {
    return !(*this <= t);
}

//Operador Mayor o Igual
bool Name::operator >= (const Name& t) const {
    return !(*this < t);
}