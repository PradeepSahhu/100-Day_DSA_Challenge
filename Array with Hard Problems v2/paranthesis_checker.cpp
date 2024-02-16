#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

bool isValid(string s)
{

    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {

                return false;
            }
            if (s[i] == ')')
            {
                if (st.top() != '(')
                {
                    return false;
                }
                st.pop();
            }
            else if (s[i] == '}')
            {
                if (st.top() != '{')
                {
                    return false;
                }
                st.pop();
            }
            else if (s[i] == ']')
            {
                if (st.top() != '[')
                {
                    return false;
                }
                st.pop();
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
}

int main()
{

    string paranthesis = "()";
    if (isValid(paranthesis))
    {
        cout << "Valid";
    }
    else
    {
        cout << "Not vallid";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}