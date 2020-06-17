 #ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
using namespace std;
struct LIVE
{
    int id = 0;
    bool survival = 0;//Выживание 0=нет 1=да
    int pclass = 0;//Пассажирский Класс (1,2,3)
    string name = "";//Имя
    string sex = "";//пол
    double age = 0;//возраст
    int sibsp = 0; //Количество братьев и сестер / супругов на борту
    int parch = 0;//Количество родителей / детей на борту
    string ticket = "";//Номер Билета
    double fare = 0;//стоимость пассажирского тарифа
    string cabin = "";//Каюта
    string embarked = "";//порт посадки на борт судна (C = Шербур; Q = Квинстаун; S = Саутгемптон)
};
LIVE help(string str) {
    LIVE human;
    string temp[13];
    int i = 0;
    for (int j = 0; j < 13; j++) {
        while (str[i] != ',' && str[i] != '\0') {
            temp[j] += str[i];
            i++;
        }
        i++;
    }
    human.id = atoi(temp[0].c_str());
    human.survival = atoi(temp[1].c_str());
    human.pclass = atoi(temp[2].c_str());
    human.name = temp[3] + " " + temp[4];
    human.sex = temp[5];
    human.age = atoi(temp[6].c_str());
    human.sibsp = atoi(temp[7].c_str());
    human.parch = atoi(temp[8].c_str());
    human.ticket = temp[9];
    human.fare = atof(temp[10].c_str());
    human.cabin = temp[11];
    human.embarked = temp[12];
    return human;
    #endif
}