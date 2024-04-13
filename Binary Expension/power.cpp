#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();


double myPow(double x, int n) {

    double ans = 1.0;

    long long nn = n;
    if(nn<0) nn = -1 * nn;

    while(nn){
        if(nn%2){

            ans = ans * x;
            nn = nn-1;
            
        }else{
        x = x * x;
            nn = nn/2;
            
        }
    }

    if(n<0) ans = (double)(1.0)/(double)(ans);

    return ans;

}

double pow(double x, int n){

    double ans = 1.0;

    int nn = n;


    if(n<0) nn = -1 * nn;

    while(nn>0){

        if(nn%2==1){
            ans = ans * x;
            nn = nn-1;
        }else{
            x = x*x;
            nn = nn/2;
        }
    }

    if(n<0) ans = (double)(1.0)/(double)(ans);

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