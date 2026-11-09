#include <iostream>
using namespace std;
int main(){
    int* k = new int; cin >> *k;
    int* m = new int[*k]();
    for(int i = 0; i < *k; ++i) cin >> m[i];
    for(int i = 0; i < *k; ++i){
        for(int j = *k; j > i; --j){
            if(m[i] > m[j]){
                int temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
        }
    }
    for(int i = 0; i < *k; ++i) cout << m[i] << " ";
    delete[] m; delete k;
    return 0;
}