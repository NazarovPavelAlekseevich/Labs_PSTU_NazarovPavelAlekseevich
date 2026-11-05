#include <iostream>
using namespace std;
int main(){
    setlocale(LC_ALL, ".65001");
    int n, k; cout << "Введите размер массива: "; cin >> n;
    int* m = new int[n];//создаём массив в динамической памяти для удобства работы
    cout << "Введите массив через пробел: ";
    for(int i = 0; i < n; ++i) cin >> m[i];//Вводим массив
    cout << "Введите индекс числа, с которго вывести массив (нумерация с 1): "; cin >> k; --k;
    for(int i = n+k+n; i > k-2+n; --i) cout << m[i%n] << " "; cout << endl;//Выводим массив

    int* mn = new int[n-2];//новый массив меньший предыдущего на 2
    for(int i = 1; i < n-1; ++i) mn[i-1] = m[i];//заносим элементы в массив без первого и последняго
    n-=2;//уменьшаем размер
    delete[] m; m = new int[n]; copy(mn, mn+n, m); delete[] mn;//копируем новый массив в старый, удаляем старый

    for(int i = k; i < n+k+2; ++i) cout << m[i%n] << " "; cout << endl;//Выводим новый массив

    return 0;
}