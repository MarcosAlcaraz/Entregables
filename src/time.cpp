//Librerias de compilador
#include<iostream>
#include<chrono>
//Librerias de Usuario
#include "time.hpp"

using namespace std;

//Constructor Normal
Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}

//Constructor Menos Normal
Time::Time (const Time& t) : hour(t.hour), minute(t.minute), second(t.second) {}

//Getters
//Get de Hora
int Time::getHour() const {
    return hour;
}

//Get de Minuto
int Time::getMinute() const {
    return minute;
}

//Get de Segundo
int Time::getSecond() const {
    return second;
}

//Setters
//Set de Hora
void Time::setHour(const int& h) {
    hour = h;
}

//Set de Minuto
void Time::setMinute(const int& m) {
    minute = m;
}

//Set de segundo
void Time::setSecond(const int& s) {
    second = s;
}

//Impresión de Tiempo
string Time::toString() const {
    char time[9];
    for(int i = 0; i< 9; i++) {
        time[i] = NULL;
    }
    sprintf(time, "%i:%i:%i", hour, minute, second);
    return time;
}

//Operador Asignación
Time& Time::operator = (const Time& t) {
    hour = t.hour;
    minute = t.minute;
    second = t.second;

    return *this;
}

//Operador Igualdad
bool Time::operator == (const Time& t) const {
    return toString() == t.toString();
}

//Operador Es Diferente
bool Time::operator != (const Time& t) const {
    return toString() != t.toString();
}

//Operador Menor Que
bool Time::operator < (const Time& t) const {
    return toString() < t.toString();
}

//Operador Menor o Igual
bool Time::operator <= (const Time& t) const {
    return *this < t || *this == t;
}

//Operador Mayor Que
bool Time::operator > (const Time& t) const {
    return !(*this <= t);
}

//Operador Mayor o Igual
bool Time::operator >= (const Time& t) const {
    return !(*this < t);
}