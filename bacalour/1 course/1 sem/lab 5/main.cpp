#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL,".65001");
    int row, col, s = 0; cout << "Введите количество столбцов и строк через пробел: "; cin >> row >> col;
    int** m = new int*[row]; //массив для ввода
    for(int i = 0; i < row; ++i) m[i] = new int[col](); //расширяем массив для ввода до двумерного
    int* res = new int[col]; //массив для результата
    memset(res, 0, col * sizeof(int)); //обнуляем все элементы массива

    for(int i = 0; i < row; ++i){ //осуществляем ввод элементов массива
        cout << "Введите " << i+1 << " строку: ";
        for(int j = 0; j < col; ++j){
            cin >> m[i][j];
            }
    }

    for(int j = 0; j < col-1; ++j){
        for(int i = 0; i < row - 1 - j; ++i) res[j] += m[i][j]; //считаем сумму для j столбца
    }

    for(int j = 0; j < col - 1; ++j) cout << "Сумма " << j+1 << \
    " столбца согласно условию равна: " << res[j] << endl; //вывод суммы для столбика
    cout << "Максимальная сумма равна: " << *max_element(res, res + col); //вывод максимальной суммы

    return 0;
}