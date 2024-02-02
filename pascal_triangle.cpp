#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// There are three types of problems in c++.

/* Pascal Triangle example.

      1                   ---> 1st rowth
    1   1                ---> 2nd rowth
    1 2 1            ---> 3rd rowth
   1 3 3 1              -----> 4th rowth
  1 4 6 4 1             ----> 5th rowth
 1 5 10 10 5 1          ----> 6th rowth.
1 6 15 20 15 6 1

|
|
1st column etc..




 1. Given n and r & we have to find the element at that (n)row-th and (r)column.

 example row = 5 & col = 3.

 to solve this problem we use. nCr =    [ n! / r! * (n-r)! ] where n = row-1 & r = col-1 of given row.

 n = 5-1 & r = 3-1

 i.e 4! / 2! * 2! = 4 * 3 * 2/ 2 * 2 = 6.

 or 4 * 3 / 2! = 6.


*/

// int nCr(int n, int r) // combination formula.
// {
//     long long res = 1;

//     for (int i = 0; i < r; i++)
//     {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// Second Type of Problem.

// used to print any given row.

//!. Observations 1st row have 1 element, 2nd row have 2 element , 3rd row have 3 elements and hence nth row have n elements.
/*






*/

// void pascal_row_printing(int n)
// {
//     for (int i = 0; i < n; i++)
//     {

//         cout << nCr(n - 1, i) << " ";
//     }
//     // for (int i = 1; i <= n; i++)
//     // {

//     //     cout << nCr(n - 1, i-1) << " ";
//     // }
// }

//! Print the whole row till numRows.
int nCr(int n, int r)
{

    int result = 1;
    for (int i = 0; i < r; i++)
    {
        result = result * (n - i);
        result = result / (i + 1);
    }
    return result;
}

vector<int> rowForm(int n)
{
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(nCr(n - 1, i - 1));
    }
    return ans;
}

vector<vector<int> > generate(int numRows)
{

    vector<vector<int> > v;

    for (int i = 1; i <= numRows; i++)
    {

        v.push_back(rowForm(i));
    }

    return v;
}




//! more optimised approach.

vector<int> rowFormation(int n)
{

    int result = 1;
    vector<int> v;
    v.push_back(result);

    for (int i = 1; i < n; i++)
    {
        result = result * (n - i);
        result = result / i;
        v.push_back(result);
    }
    return v;
}

int main()
{
    // cout << "Enter the row " << endl;
    // int row;
    // cin >> row;
    // cout << "Enter the column " << endl;
    // int col;
    // cin >> col;

    // cout << nCr(row - 1, col - 1);

    // pascal_row_printing(5);
    vector<int> ans = rowFormation(6);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}