#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void inlinedata(){
    FILE* f = fopen("f1.txt", "w");
    int n;
    cout << "Сколько строк в файле? ";
    (cin >> n).ignore();                 // съели '\n' после числа

    char str[256] = "";
    for (int i = 0; i < n; ++i) {
        cin.getline(str, sizeof(str));   // без scanf и без cin.ignore
        fputs(str, f);
        fputc('\n', f);                  // строка записывается как строка
    }
    fclose(f);
}

bool oneWord(const char* s) {
    for (int i = 0; s[i] != '\0'; ++i)
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' || s[i] == '\f')
            return false;
    return true;
}

void copy() {
    FILE* f1 = fopen("f1.txt", "r");
    FILE* f2 = fopen("f2.txt", "w");
    char m[256];

    while (fgets(m, sizeof(m), f1)) {
        m[strcspn(m, "\n")] = '\0';      // отсекаем '\n'
        if (m[0] != '\0' && oneWord(m)){
            fputs(m, f2);
            fputc('\n', f2);
        }
    }
    fclose(f1); fclose(f2);
}

void read(const char* name) {
    FILE* f = fopen(name, "r");
    if (!f) return;
    char m[256];
    while (fgets(m, sizeof(m), f)) fputs(m, stdout);
    fclose(f);
}

void maxc() {
    FILE* f = fopen("f1.txt", "r");

    const char* delims = " \t\n\r";
    const char* cons = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    char buf[256];
    int word = 0, bestWord = 0, bestCnt = -1;
    while (fgets(buf, sizeof(buf), f)) {
        for (char* p = strtok(buf, delims); p; p = strtok(NULL, delims)) {
            ++word;
            int cnt = 0;
            for (char* q = p; *q; ++q) if (strchr(cons, *q)) ++cnt;
            if (cnt > bestCnt) { bestCnt = cnt; bestWord = word; }
        }
    }
    fclose(f);
    if (bestWord)
        cout << "Слово №" << bestWord << " (согласных: " << bestCnt << ")\n";
    else
        cout << "Слов в файле нет\n";
}

int main() {
    setlocale(LC_ALL, ".65001");
    inlinedata();
    copy();
    cout << "f2:\n"; read("f2.txt"); cout << endl;
    maxc();
    return 0;
}