#include <iostream>
#include <cstdarg>
using namespace std;
template<typename T>
inline T f(T k, ...){
    T sum = 0;
    va_list args;
    va_start(args, k);
    for(int i = 0; i < k; ++i) sum += va_arg(args, T);
    va_end(args);
    return sum;
}
int main(){
    int a[3]; double b[2];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1];
    int i1 = 3; double i2 = 2;
    cout << f(i1, a[0], a[1], a[2]) << endl;
    cout << f(i2, b[0],b[1]);
    return 0;
}