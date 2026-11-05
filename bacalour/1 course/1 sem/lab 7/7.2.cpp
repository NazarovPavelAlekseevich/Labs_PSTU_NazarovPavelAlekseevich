#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;
int octf(int c){
    int res = 0, pos = 0;
    while(c > 0){res += (c % 10) * pow(8, pos); ++pos; c/=10;}
    return res;
}
void func(int count, ...){
    va_list arg; va_start(arg, count);
    for(int i = 0; i < count; ++i){
        int ch = va_arg(arg, int);
        int res = octf(ch);
        if(res != 0) cout << ch << " в 10-СС " << res << endl;
    }
    va_end(arg);
    return;
}
int main(){
    setlocale(LC_ALL,".65001");
    int n; 
    cout << "Введите количество значений (не более 10): "; cin >> n; int m[10];
    cout << "Введите числа в 8-СС через пробел: ";
    for(int i = 0; i < n; ++i) cin >> m[i];
    func(n, m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9]);
    return 0;
}