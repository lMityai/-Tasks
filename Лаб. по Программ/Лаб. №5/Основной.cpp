
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "cstdlib"
#include "Header.h"

int main()
{
    ifstream fin("train.csv");
    vector <string> vec_str;
    string str;
    while (getline(fin, str, '\r'))
    {
        if (str.size() > 0)
            vec_str.push_back(str);
    }
    fin.close();

    int sum = 0, 
        sum1 = 0, 
        sum2 = 0, 
        sum3 = 0, 
        women = 0, 
        men = 0, 
        Cherbourg = 0, 
        Queenstown = 0, 
        Southampton = 0, 
        all_women = 0, 
        all_men = 0;
    vector<int> ves;
    double num_women = 0.0, num_men = 0.0, age = 0;

    for (int i = 1; i < vec_str.size(); i++) {
        LIVE a = help(vec_str[i]);
        if (a.survival == 1) {
            sum++;
            if (a.sex == "male") {
                men++;
            }
            else women++;

            switch (a.pclass) {
            case 1:
                sum1++;
                break;
            case 2:
                sum2++;
                break;
            case 3:
                sum3++;
                break;
            }
        }
        if (a.age < 18) {
            ves.push_back(a.id);
        }
        if (a.embarked == "C") {
            Cherbourg++;
        }
        if (a.embarked == "S") {
            Southampton++;
        }
        if (a.embarked == "Q") {
            Queenstown++;
        }
        if (a.sex == "male") {
            all_men++;
            num_men += a.age;
        }
        else {
            all_women++;
            num_women += a.age;
        }
        age += a.age;
    }

    string strin;
    if (Cherbourg > Southampton) {
        if (Cherbourg > Queenstown) {
            strin = "Cherbourg";
        }
        else strin = "Queenstown";
    }
    else
    {
        if (Southampton > Queenstown) {
            strin = "Southampton";
        }
        else strin = "Queenstown";
    }
    ofstream file("Файл вывода.txt");
    file << "Общее число выживших:" << sum << endl;
    file << "1 класс:" << sum1 << endl;
    file << "2 класс:" << sum2 << endl;
    file << "3 класс:" << sum3 << endl;
    file << "Женщин:" << women << endl;
    file << "Мужчин:" << men << endl;
    file << "Средний возраст пассажира:" << age / vec_str.size() << endl;
    file << "Средний женский возраст:" << num_women / all_women << endl;
    file << "Средний мужской возраст:" << num_men / all_men << endl;
    file << "Штат в котором село больше всего пассажиров:" << strin << endl;
    file << "Идентификатор несовершеннолетних:";
    for (int i = 0; i < ves.size(); i++) {
        if (i == ves.size() - 1) {
            file << ves[i] << ".";
            file.close();
            return 0;
        }
        file << ves[i] << ", ";
    }
}
