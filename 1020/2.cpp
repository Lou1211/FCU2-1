#include <iostream>
#include <math.h>

using namespace std;

void tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from " << a << " to " << c << endl;
    }
    else
    {
        tower(n - 1, a, c, b);
        cout << "Move disk " << n << " from " << a << " to " << c << endl;
        tower(n - 1, b, a, c);
    }
}

int main()
{
    int n, time;
    cin >> n;
    time = pow(2, n);
    time--;
    tower(n, 'A', 'B', 'C');
}