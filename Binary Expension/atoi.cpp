#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int main()
{

    string v = "03";
//    cout<<typeid(v[0]-'0').name(); // to know the type of the variable in c++

//   Compilation Time code //
cout << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
return 0;
}