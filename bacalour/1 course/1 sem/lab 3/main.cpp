#include <iostream> //подключаем библиотеку iostresm.h
#include <cmath> //подключаем библиотеку cmath.h для нахождения arctg
#include <clocale> //подключаем библиотеку clocale.h
using namespace std;//используем пространство имён std

int main(){
    setlocale(LC_ALL, ".65001");//локализируем
    cout << "Введите a и b через пробел: ";
    double a,b; cin >> a >> b;//вводим параметры a и b
    double k = (b-a)/10, n = 30, se = 0, sn = 0, cur;
    /* k - это шаг в цикле
    n = количество элементов для суммы 30 элементов
    se и sn - суммы для первого и второго условий */

    double& x = a;//для удобства ссылка на а

    for(x; x <= b; x += k){ // перебор чисел от a до b с шагом k
        cout << "X = " << x << "   "; //вывод текущего х
        cur = ( pow( x , (2*n + 1) ) ) / (4 * n * n -1); // текущее значение суммы

        if(n > 0){sn += cur; n--;}//увеличение sn
        if(x > 0.1 && x < 1) se += cur;//увеличение se

        //вывод текущих сумм:
        cout << "Xn = " << sn << "   ";
        cout << "Xe = " << se << "   ";
        cout << "Y = " << ( (1 + x*x)/2 ) * atan(x) - x/2 << endl;
    }

    //вывод результатов:
    cout << endl << "Результаты:" << endl;
    cout << "Сумма для условия n <= 30 = " << sn << endl;
    cout << "Сумма для условия 0.1 < x < 1 = " << se << endl;
    return 0;
}