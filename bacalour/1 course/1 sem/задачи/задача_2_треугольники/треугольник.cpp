#include <iostream>
using namespace std;

int main()
{
    int n,p,z; cin >> n; p = n; z = n - p;

    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <= z; j++)
            cout << ' ';
        for(int j = 1; j <= p; j++)
            cout <<'*';
        p--; z++; cout << endl;
    }
    return 0;
}