#include <iostream>
#include <vector>

std::vector<int> fib_results(31, -1);

int memoizedOperations = 0;

int dpFibonacci(int n)
{
    memoizedOperations++;

    if (n <= 1)
        return n;

    if (fib_results[n] != -1)
        return fib_results[n];

    fib_results[n] = dpFibonacci(n - 1) + dpFibonacci(n - 2);
    return fib_results[n];
}

int operations = 0;

int fibonacci(int n)
{
    operations++;

    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    std::cout << "Fibonacci: " << fibonacci(30) << std::endl;
    std::cout << "Operations: " << operations << std::endl;

    std::cout << "Fibonacci optimized: " << dpFibonacci(30) << std::endl;
    std::cout << "Operations: " << memoizedOperations << std::endl;
    return 0;
}
