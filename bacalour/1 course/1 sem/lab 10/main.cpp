#include <iostream>
#include <string>//библиотека для работы со строками
#include <windows.h>// библиотека для getline
using namespace std;
int main(){
    setlocale(LC_ALL, ".65001");
    cout << "           Задача 7.1" << endl;
    int n, k = 0; cout << "Введите количество элементов массива: ";
    cin >> n;
    cin.ignore();//чтобы избежать ошибок ввода
    string* m = new string[n]();
    for(int i = 0; i < n; ++i) {
        cout << i+1 << " строка: "; 
        getline(cin, m[i]);//Ввод
    }

    for(int i = 0; i < n - 1; ++i){
        bool f = false;//Флажок для повторов
        for(int j = i + 1; j < n; ++j){
            if(m[i] == m[j] && m[i] != "\0") {m[j] = "\0"; ++k; f = true;}
        }
        if(f) m[i] = "\0"; //замена
    }

    string* nm = new string[n-k]();
    for(int i = 0, j = 0; i < n && j < n-k; ++i){
        if(m[i].size()){ //проверка на пустоту
            nm[j] = m[i];
            ++j;
        }
    }

    delete[] m;
    m = nm; nm = nullptr;
    for(int i = 0; i < n - k; ++i) cout << m[i] << endl;
    delete[] m; m = nullptr; // обнуление массива

    cout << endl << "           Задача 7.2" << endl;
    cout << "Введите количество элементов массива: ";
    cin >> n;
    cin.ignore();
    m = new string[n]();
    for(int i = 0; i < n; ++i) {
        cout << i+1 << " строка: "; 
        getline(cin, m[i]);
    }
    cout << "Сколько элементов нужно удалить: "; cin >> k;
    if (k > n) k = n;
    nm = new string[n-k]();

    for(int i = 0; i < n-k; ++i) nm[i] = m[i];
    delete[] m;
    m = nm;
    nm = nullptr;
    for(int i = 0; i < n-k; ++i) cout << m[i] << endl;
    delete[] m;
    m = nullptr;

    return 0;
}