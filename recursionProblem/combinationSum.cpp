#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
auto start = chrono::steady_clock::now();



void recursionSolution(vector<vector<int>> &ans,vector<int> &ds,int index, int target, vector<int> combination){


    if(index==combination.size()){
        if(target==0){
            ans.push_back(ds);
            return;
        }else{
            return;
        }
    }


    // pick condition 

    

    // if(target-combination[index]>0){
    if(combination[index]<=target){
        ds.push_back(combination[index]);
        recursionSolution(ans,ds,index,target-combination[index],combination);
         ds.pop_back();
    }


    // non pick condition.

   
    recursionSolution(ans,ds,index+1,target,combination);





  

}


vector<int> combinationSum(vector<int> &combination, int target){

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