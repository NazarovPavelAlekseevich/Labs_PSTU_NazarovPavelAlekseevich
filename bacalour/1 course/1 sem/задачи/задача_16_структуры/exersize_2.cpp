#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct man{
    string FIO;
    int days;
    int salary;
    int benifit;
    void result(){
        cout << "Для " << FIO << " заработная плата составляет: " << days * salary + benifit;
    }
};

int main(){
    setlocale(LC_ALL, ".65001");
    system("chcp 1251>nul");
    man s;
    cout << "Введите ФИО сотрудника: ";
    getline(cin, s.FIO);
    cout << "Введите количество отработанных дней: ";
    cin >> s.days;
    cout << "Введите зарплату: ";
    cin >> s.salary;
    cout << "Введите размер премии: ";
    cin >> s.benifit;
    cout << "Зарплата " << s.FIO << " равна: ";
    s.result();
    return 0;
}