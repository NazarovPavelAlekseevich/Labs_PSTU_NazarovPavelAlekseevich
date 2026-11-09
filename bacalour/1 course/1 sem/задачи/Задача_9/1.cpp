#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    string s; getline(cin,s);
    if(s.size() > 5) s[0] = 'X';
    else s[s.size() - 1] = 'X';
    for(int i = s.size() - 1; i >= 0; --i) cout << s[i];
    return 0;
}