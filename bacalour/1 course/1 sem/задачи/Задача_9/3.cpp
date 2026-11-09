#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    string s; getline(cin,s);
    s.erase(0,100);
    for(int i = 0; i < s.size(); ++i) cout << s[i];
    return 0;
}