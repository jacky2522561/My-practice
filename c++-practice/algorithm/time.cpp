#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int factorial = 1;
        for (int j = 1; j <= i; j++)
        {
            factorial *= j;
        }
        s += factorial;
    }
    cout << s << endl;
    cout << "Time used = " << clock() / CLOCKS_PER_SEC<< endl;

    return 0;
}
