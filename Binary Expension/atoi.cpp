#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();



int myAtoi(string s) {
        int len = s.size();
        double num = 0;
        int i=0;
        while(s[i] == ' '){
            i++;
        }
        bool positive = s[i] == '+';
        bool negative = s[i] == '-';
        positive == true ? i++ : i;
        negative == true ? i++ : i;
        while(i < len && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i]-'0');
            i++;
        }
        num = negative ? -num : num;
        cout<<num<<endl;
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;
        cout<<num<<endl;
        return int(num);
    }

int myAtoi(string s) {

    int length = s.size();
    double num = 0;

    int i = 0;

    while(s[i] == ' '){
        i++;
    }

    bool positive = s[i] == '+';
    bool negative = s[i] == '-';

    positive==true?i++:i;
    negative==true?i++:i;

    while(i< length && s[i]>='0' && s[i]<='9'){
        num = num*10 + (s[i]-'0');
        i++;
    }

    // cout<<negative<<endl;

    num = (negative? -1*num : num);

    if(num >= INT_MAX) num = INT_MAX;
    if(num<-INT_MIN) num = INT_MIN;

 return int(num);


}



int main()
{

    string v = "-23";

    myAtoi(v);
//    cout<<typeid(v[0]-'0').name(); // to know the type of the variable in c++

//   Compilation Time code //
cout << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
return 0;
}