#include <iostream>
using namespace std;
int main(){
    setlocale(LC_ALL, ".65001");
    int n, j = 1, m, x, k = 1;
    cin >> n; cin >> m;
    for(int i = 2; i <= n; ++i){
        cin >> x;
        if(x >= m){
            if(x == m) ++k;
            else{m = x; k = 1; j = i;}
        }
    }
    cout << m << "  - максимальный, количество: " << k << " индекс: " << j;
    return 0;
}