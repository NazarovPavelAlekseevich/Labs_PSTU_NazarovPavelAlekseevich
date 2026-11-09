#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main(){
    string s; getline(cin,s);
    s.insert(1, "AAAAA");
    for(int i = 0; i < s.size(); ++i) cout << s[i];
    //s.insert(100, "AAAAA"); ERROR
    //for(int i = 0; i < s.size(); ++i) cout << s[i];
    return 0;
}