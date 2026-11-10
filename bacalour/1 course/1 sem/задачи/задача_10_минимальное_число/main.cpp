#include <iostream>
using namespace std;
int main(){
    int n; cin >> n; int* m = new int[n]();
    for(int i = 0; i < n; ++i) cin >> m[i];
    int min = m[0], k = 1, ind = 0;
    for(int i = 0; i < n; ++i){
        if(m[i] < min){
            min = m[i];
            k = 1;
            ind = i;
        }
        else if(m[i] == min) ++k;
    }
    cout << min << " " << ind << " " << ind + 1 << " " << k;
    return 0;
}