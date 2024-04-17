#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
auto start = chrono::steady_clock::now();

// void subarraysWithSumK(int ind, vector<vector<int>>& ans,set<vector<int>>& seen, vector<int> ds,vector<int> arr,int n, long long s, long long sum ){

//     if(ind == n){
//         if(s==sum && seen.find(ds)==seen.end()){
//             ans.push_back(ds);
//             seen.insert(ds);
//         }
//         return;
//     }

//     ds.push_back(arr[ind]);
//     s+=arr[ind];
//     subarraysWithSumK(ind+1,ans,seen,ds,arr,n,s,sum);

//     s-=arr[ind];
//     ds.pop_back();
//    subarraysWithSumK(ind+1,ans,seen,ds,arr,n,s,sum);

// }

// vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
//     // Write your code here

//     vector<vector<int>> ans;
//     vector<int> ds;
//     set<vector<int>> seen;

//     int n = a.size();

//     subarraysWithSumK(0,ans,seen,ds,a,n,0,k);

//     return ans;
// }


void subsequence(int index,vector<vector<int>>& ans,vector<int> output,vector<int> &a,long long k , long long sum){

    if(sum == k){
        ans.push_back(output);
    }

    if(sum>k){
        while(sum>k && !output.empty()){
            sum-=output[0];
            output.erase(output.begin());
        }

        if(sum==k){
            ans.push_back(output);
        }
    }

    if(index = a.size()){
        return;
    }

    output.push_back(a[index]);
    sum+=a[index];

    subsequence(index+1,ans,output,a,k,sum);




}



vector< vector<int> > subsequence(vector<int> a, long long k){

    vector<vector<int >> ans;

    vector<int> output;

    subsequence(0,ans,output,a,k,0);
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