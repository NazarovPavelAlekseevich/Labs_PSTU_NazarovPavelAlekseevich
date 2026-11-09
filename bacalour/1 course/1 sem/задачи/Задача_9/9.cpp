#include <iostream>
using namespace std;
int main(){
    int k; cin >> k; int* m = new int[k]();
    for(int i = 0; i < k; ++i) cin >> m[i];

    for(int i = 0; i < k; ++i){
        int min = m[i], y = i;
        for(int j = i+1; j < k; ++j) if(m[j] < min){min = m[j]; y = j;}
        m[y] = m[i]; m[i] = min;
    }

    for(int i = 0; i < k; ++i) cout << m[i] << " ";
    return 0;
}