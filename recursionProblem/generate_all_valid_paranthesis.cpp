#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

    void res(int n, int openN, int closeN, vector<string> &temp,string &str){


    if(str.size()==2*n){
        temp.push_back(str);
        return;
    }

    // if(openN==n && closeN==n){
    //     return;
    // }

    if(openN<n){
        str+='(';
        res(n,openN+1,closeN,temp,str);
        str.pop_back();
    }

    if(closeN<openN){
        str+=')';
        res(n,openN,closeN+1,temp,str);
        str.pop_back();
    }
}
vector<string> generateParenthesis(int n){

    string str = "";
    vector<string>temp;

    int openN = 0;
    int closeN=0;

    res(n,openN,closeN,temp,str);
    return temp;

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