#include <iostream>
using namespace std;

#define TEST(n, pos) ((n) & (1 << (pos)))
#define SET(n, pos) ((n) | (1 << (pos)))
#define CLEAR(n, pos) ((n) & ~(1 << (pos)))
#define FLIP(n, pos) ((n) ^ (1 << (pos)))

void printBinary(int n, bool newline = true)
{
    cout << "<" << n << " = ";
    for (int i = 31; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << ">";
    if (newline)
    {
        cout << endl;
    }
}

int main()
{
    int mask = 0;
    for (int i = 0; i < 31; i++)
    {
        if (!(i % 2))
        {
            mask = SET(mask, i);
        };
    };
    cout << "Numeros pares: ";
    printBinary(mask);

    cout << "Numeros impares: ";
    printBinary(~0 ^ mask);
    return 0;
}
