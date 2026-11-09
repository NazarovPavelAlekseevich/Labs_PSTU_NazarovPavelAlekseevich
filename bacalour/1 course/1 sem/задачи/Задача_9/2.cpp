#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    string s; getline(cin,s);
    s.replace(0,1,"Hello world!!!");
    for(int i = 0; i < s.size(); ++i) cout << s[i];
    s.replace(0,100,"Hello world!!!");
    cout << endl;
    for(int i = 0; i < s.size(); ++i) cout << s[i];
    s.replace(0,0,"Hello world!!!");
    cout << endl;
    for(int i = 0; i < s.size(); ++i) cout << s[i];
    return 0;
}