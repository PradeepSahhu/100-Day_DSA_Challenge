#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

#include <bits/stdc++.h>


//! Taking so much time.
void generateString(int n, vector<string> &temp, string str, int N)
{
    if (n == 0)
    {
        return;
    }

    if (str.back() == '0')
    {
        string str2 = str;
        str2.push_back('0');

        if (str2.size() == N)
        {
            temp.push_back(str2);
        }
        generateString(n - 1, temp, str2, N);

        string str3 = str;
        str3.push_back('1');

        if (str3.size() == N)
        {
            temp.push_back(str3);
        }

        generateString(n - 1, temp, str3, N);
    }
    if (str.back() == '1')
    {
        string str4 = str;
        str4.push_back('0');

        if (str4.size() == N)
        {
            temp.push_back(str4);
        }

        generateString(n - 1, temp, str4, N);
    }

    return;
}

vector<string> generateString(int N)
{
    // Write your code here.

    vector<string> temp;
    string one = "1";
    string zero = "0";

    if (N == 1)
    {
        temp.push_back(zero);
        temp.push_back(one);
        return temp;
    }

    generateString(N, temp, zero, N);
    generateString(N, temp, one, N);

    return temp;
}



void rec(int N, vector<string> &temp, int index, string s){


    if(index==N){
        temp.push_back(s);
        return;
    }

    if(s[index-1]=='0'){
        rec(N,temp,index+1,s+'0');
        rec(N,temp,index+1,s+'1');
    }else{
        rec(N,temp,index+1,s+'0');
    }


}



vector<string> generateString(int N){
    vector<string> ans;

    rec(N,ans,1,"0");
    rec(N,ans,1,"1");

    return ans;
}

int main()
{

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}