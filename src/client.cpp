//Librerias de compilador
#include<iostream>
//Librerias de Usuarioa
#include"client.hpp"

using namespace std;

//Constructor Normal
Client::Client() {}  // E4

//Constructor Copia
Client::Client (const Client& c) {}  // E4

//Getters
//Get de Hora de Atención
Time Client::getTimeAtention() const { // E4
    return timeAtention;
}

//Get de Duración de Llamada
Time Client::getAtentionDuration() const { // E4
    return atentionDuration;
}

//Setters
//Set de Peimer Nombre
void Client::setTimeAtention(const Time& ta) { // E4
    timeAtention= ta;
}

//Set de Minuto
void Client::setAtentionDuration(const Time& ad) { // E4
    atentionDuration = ad;
}

//Impresión de Tiempo
string Client::toString() const {  // E4
    char timedata[64];
    for(int i = 0; i< 64; i++) {
        timedata[i] = NULL;
    }
    sprintf(timedata, "Call in Time: %s\nCall Duration: %s\n", timeAtention, atentionDuration);
    return timedata;
}

//Operador Asignación
Client& Client::operator = (const Client& c) {
    timeAtention = c.timeAtention;
    atentionDuration = c.atentionDuration;

    return *this;
}

//Operador Igualdad
bool Client::operator == (const Client& t) const {
    return toString() == t.toString();
}

//Operador Es Diferente
bool Client::operator != (const Client& t) const {
    return toString() != t.toString();
}

//Operador Menor Que
bool Client::operator < (const Client& t) const {
    return toString() < t.toString();
}

//Operador Menor o Igual
bool Client::operator <= (const Client& t) const {
    return *this < t || *this == t;
}

//Operador Mayor Que
bool Client::operator > (const Client& t) const {
    return !(*this <= t);
}

//Operador Mayor o Igual
bool Client::operator >= (const Client& t) const {
    return !(*this < t);
}
