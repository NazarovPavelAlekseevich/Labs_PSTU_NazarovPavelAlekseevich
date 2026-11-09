#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    string s; getline(cin,s);
    cout << s.find('a');
    return 0;
}