#include <iostream>
using namespace std;
int main(){
    setlocale(LC_ALL,".65001");
    int a,b; bool f = true;
    cin >> a;
    if(a != 0){
        cin >> b;
        if(a == b) f = false;
        while(f && (b != 0)){
            f = (a < b) && f;
            if(f){a = b; cin >> b;}
        }
        if(f) cout << "Последовательность удволетворяет условию";
        else cout << "последовательность не удволетворяет условию";
        return 0;
    }
    cout << "В последовательности нет элементов";
    return 0;
}