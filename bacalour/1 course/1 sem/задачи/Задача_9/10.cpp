#include <iostream>
using namespace std;
int main(){
    int k; cin >> k;
    int* m = new int[k]();
    for(int i = 0; i < k; ++i) cin >> m[i];

    for(int i = 1; i < k; ++i){
        bool f = false;
        for(int j = 0; j < i && !f; ++j){
            if(m[j] > m[i]){
                int temp = m[i];
                for(int h = i; h > j; --h) m[h] = m[h-1];
                m[j] = temp;
                f = true;
            }
        }
    }

    for(int i = 0; i < k; ++i) cout << m[i] << " ";
    delete[] m;
    return 0;
}