#include <iostream>
using namespace std;

struct Advertising{
    double show;
    double percentOfTupe;
    double profit;
    double func(){
        return show * percentOfTupe * profit;
    }
};

int main(){
    setlocale(LC_ALL,".65001");
    Advertising s;
    cout << "Введите количество показанных объявлений: ";
    cin >> s.show;
    cout << "Введите процент постетителей, которые нажали на объявление: ";
    cin >> s.percentOfTupe;
    cout << "Введите сколько заработано в среденм от нажатия: ";
    cin >> s.profit;
    cout << "Доход: ";
    cout << s.func();
    return 0;
}