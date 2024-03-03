#include <iostream>
using namespace std;

#define TEST(n, pos) ((n) & (1 << (pos)))
#define SET(n, pos) ((n) | (1 << (pos)))
#define CLEAR(n, pos) ((n) & ~(1 << (pos)))
#define FLIP(n, pos) ((n) ^ (1 << (pos)))

void printBinary(int n)
{
    for (int i = 2; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
}

void printSet(int mask, char* elements)
{
    cout << " { ";
    for (int i = 0; i < (1 << 3); i++)
    {
        if (TEST(mask, i))
        {
            cout << elements[i] << " ";
        }
    }
    cout << "}" << endl;
}

int main()
{
    char elements[] = {'a', 'b', 'c'};
    for (int mask = 0; mask < (1 << 3); mask++)
    {
        printBinary(mask);
        printSet(mask, elements);
    };
    return 0;
}
