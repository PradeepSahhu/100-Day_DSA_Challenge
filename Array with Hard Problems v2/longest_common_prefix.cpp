#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
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