#include <iostream>
#include <cmath>
using namespace std;

void f(double n){
    if(n < 0){cout << "n < 0"; return;}
    cout << "Квадратный корень из десятичного числа " << n << " равен: " << sqrt(n);
    return;
}

void f(int& m, int n){
    cout << "Число " << m << " в степени " << n << " равно: ";
    int res = 1;
    while(n > 0){
        if(n & 1) res *= m;
        m *= m;
        n >>= 1;
    }
    cout << res;
    return;
}

int main(){
    setlocale(LC_ALL,".65001");
    cout << "Выберите действие (Возведение в степень - 'a', корень числа - 'b'): ";
    char c; cin >> c;
    switch(c){
        case 'a': cout << "Введите через пробел возводимое в степень число и степень: "; int m,n; cin >> m >> n; f(m,n); break;
        case 'b': cout << "Введите число: "; double a; cin >> a; f(a); break;
        default: cout << "Ошибка ввода"; break;
    }
    return 0;
}