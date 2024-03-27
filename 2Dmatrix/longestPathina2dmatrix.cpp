#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int longestIncreasingPath(vector<vector<int>> &matrix, vector<vector<int>> &cache, int n, int m, int i, int j)
{
    if (cache[i][j] > 0)
        return cache[i][j];

    int maxi = 0;
    for (vector<int> direction : directions)
    {
        int x = direction[0] + i;
        int y = direction[1] + j;

        if (x > -1 && y > -1 && x < n && y < m && matrix[x][y] > matrix[i][j])
        {
            int longest = longestIncreasingPath(matrix, cache, n, m, x, y);
            maxi = max(maxi, longest);
        }
    }
    cache[i][j] = maxi + 1;
    return cache[i][j];
}

int longestIncreasingPath(vector<vector<int>> &mat, int n, int m)
{
    if (mat.size() == 0)
    {
        return 0;
    }

    int longestPath = 0;
    vector<vector<int>> cache(n, vector<int>(m)); // n - rows and m columns.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int longest = longestIncreasingPath(mat, cache, n, m, i, j);
            longestPath = max(longestPath, longest);
        }
    }
    return longestPath;
}

int main()
{

    vector<vector<int>> v = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}};

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}