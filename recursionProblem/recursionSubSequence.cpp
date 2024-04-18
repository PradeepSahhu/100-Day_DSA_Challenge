#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void recursionSubSequence(int index, vector<int> &ds,vector<int> nums,vector<vector<int>> &mainAns){

    if(index == nums.size()){

        vector<int> temp;

        for(auto it: ds){
            cout<<it<<" ";
            temp.push_back(it);
        }
        mainAns.push_back(temp);
        cout<<endl;
        return;
    }

//pick at that index.
    ds.push_back({nums[index]});
   
    recursionSubSequence(index+1,ds,nums,mainAns);

    // not pick at that index.
    ds.pop_back();

    recursionSubSequence(index+1,ds,nums,mainAns);


}


vector<vector<int>> subsequence(vector<int> nums){
    vector<int> ds;
    vector<vector<int>> mainAns;

    recursionSubSequence(0,ds,nums,mainAns);

    return mainAns;
}

int main()
{

    vector<int> ques = {2,1,3};

    vector<vector<int>> ans = subsequence(ques);

    cout<<"the size of int is"<<ans.size()<<endl;

    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }



//   Compilation Time code //
cout << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
return 0;
}