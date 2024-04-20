#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();



void recursionSolution(vector<vector<int>> &ans,vector<int> &ds,int index, int target, vector<int> combination){


  if(target==0){
    ans.push_back(ds);
    return;
  }


    for(int i = index;i<combination.size();i++){
        if(i>index && combination[i]==combination[i-1])continue;
        if(combination[i]>target) break;
        ds.push_back(combination[i]);
        recursionSolution(ans,ds,i+1,target-combination[i],combination);
        ds.pop_back();
    }


}



void recursionCombination(vector<vector<int>> &ans,vector<int> &ds,vector<int> combinations,int index,int target){


  if(target==0){
    ans.push_back(ds);
    return;
  }


  for(int i = index;i<combinations.size();i++){

    if(i>index && combinations[i]==combinations[i-1]) continue;
    if(combinations[i]>target) break;

    ds.push_back(combinations[i]);
    recursionCombination(ans,ds,combinations,i+1,target-combinations[i]);

    ds.pop_back();
  }


}


vector<int> combinationSum(vector<int> &combination, int target){


    sort(combination.begin(),combination.end());

    vector<int> ds;
    vector<vector<int>> ans;

    recursionSolution(ans,ds,0,target,combination);

    return ds;
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