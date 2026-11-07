#include <iostream>
#include <string>//для удобства работы со строками подключаем библиотеку
#include <clocale>
#include <cctype> //для isdigit и isalpha подключаем библиотеку
#include <windows.h> // для getline подключаем библиотеку
using namespace std;

struct mass {bool f = true; string s;}; //создаём структуру для слов

int main(){
    setlocale(LC_ALL,".65001");
    string s; int k = 0, fix = 0, j = 0;
    getline(cin,s);//ввод строки
    bool flags = false, flage = false;//флажки для первого и последнего пробела
    int n = size(s);
    if(s[0] == ' ') flags = true;
    if(s[n] == ' ') flage = true;
    mass* m = new mass[30](); //массив для слов

    for(int i = 0; i < n; ++i){
        if(s[i] != ' ') m[j].s += s[i];
        else ++j;} //выделяем слова из строки по пробелу

    for(int i = 0; i <= j; ++i){
        for(char c : m[i].s){
            if(!isalpha(static_cast<char>(c)) && !isdigit(static_cast<char>(c))) m[i].f = false; //проверяем символы
            if(!m[i].f) break; //меняем флажок
        }
    }

    cout << "Начало строки -'";
    s.clear(); s = ""; //чистим старую строку
    int i;
    if(flags){cout << " "; i = 1;} // проверка для старта 
    else i = 0;

    for(i; i <= j; ++i){ //Вывод строки
        if(m[i].f){
            cout << m[i].s;
            if(i != j) cout << " ";
        }
    }
    if(flage) cout << " ";
    cout << "'- конец строки";
    return 0;
}