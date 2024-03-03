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

    cout << "Original number: " << mask << " ";
    printBinary(mask);

    mask = SET(mask, 17);
    mask = SET(mask, 21);
    cout << "Bit set: " << mask << " ";
    printBinary(mask);

    mask = CLEAR(mask, 21);
    cout << "Bit clear: " << mask << " ";
    printBinary(mask);

    mask = FLIP(mask, 8);
    cout << "Bit flip: " << mask << " ";
    printBinary(mask);

    cout << "Bit test: " << (TEST(mask, 17) ? "yes" : "no") << endl;
    cout << "Bit test: " << (TEST(mask, 21) ? "yes" : "no") << endl;

    return 0;
}
