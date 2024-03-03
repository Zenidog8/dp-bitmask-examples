#include <bits/stdc++.h>
using namespace std;

#define TEST(n, pos) ((n) & (1 << (pos)))
#define SET(n, pos) ((n) | (1 << (pos)))
#define CLEAR(n, pos) ((n) & ~(1 << (pos)))
#define FLIP(n, pos) ((n) ^ (1 << (pos)))

int count_set_bits(int n)
{
    int count = 0;
    for (int i = 31; i >= 0; i--)
    {
        count += TEST(n, i) ? 1 : 0;
    }
    return count;
}

int assign(int n, vector<vector<int>> &cost, int *dp)
{
    for (int i = 0; i < (1 << n); i++)
    {
        dp[i] = (1 << 31) - 1;
    }
    dp[0] = 0;
    // mask represents the set of tasks that have been assigned
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int x = count_set_bits(mask);
        for (int j = 0; j < n; j++)
        {
            if (!TEST(mask, j))
            {
                dp[SET(mask, j)] = min(dp[SET(mask, j)], dp[mask] + cost[x][j]);
            }
        }
    }
    // dp contains the minimum cost of assigning all tasks subsets
    // 1 shifted to the left n times minus 1 is the mask that represents all n tasks assigned
    return dp[(1 << n) - 1];
}

int main()
{
    int N;
    cin >> N;
    int dp[1 << N];

    vector<vector<int>> cost(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << assign(N, cost, dp) << endl;
    return 0;
}
