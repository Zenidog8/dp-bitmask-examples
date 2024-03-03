#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

void generate_next_greater_permutation(std::vector<int> &assignment)
{
    std::next_permutation(assignment.begin(), assignment.end());
}

int assign(int N, vector<vector<int>> &cost)
{
    vector<int> assignment(N);
    iota(assignment.begin(), assignment.end(), 0);

    int res = (1 << 31) - 1;
    for (int j = 0; j < factorial(N); j++)
    {
        int total_cost = 0;
        for (int i = 0; i < N; i++)
        {
            total_cost = total_cost + cost[i][assignment[i]];
        }
        res = min(res, total_cost);
        generate_next_greater_permutation(assignment);
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> cost(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << assign(N, cost) << endl;
    return 0;
}
