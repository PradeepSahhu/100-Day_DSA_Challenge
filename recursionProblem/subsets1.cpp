#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// powerset approach using bit manipulation.

vector<int> subsetSum(vector<int> &num){
	

    int n = num.size();
    vector<int> temp;
   


    int x = (1<<n);


    for(int i = 0;i<x;i++){
        int ans = 0;

        for(int j = 0;j<n;j++){
            if(i & (1<<j)){
                ans+=num[j];
            }

        }
        temp.push_back(ans);
    }

    sort(temp.begin(),temp.end());

    return temp;


}

//using picking and not picking mechanism.


void recursionPicking(int index,int sum, vector<int> num,vector<int> &ds){

    if(index==num.size()){
        ds.push_back(sum);
        return;
    }

    //picking.
    

    sum+=num[index];
    recursionPicking(index+1,sum,num,ds);

    sum-=num[index];
    recursionPicking(index+1,sum,num,ds);
}

vector<int> subsetSum(vector<int> &num){


    vector<int> ds;


    recursionPicking(0,0,num,ds);

    return ds;

}


int main()
{
    // cout<<(2 & (1<<1))<<endl;


    vector<int> num = {2,1,3};

   vector<int> ans =  subsetSum(num);

//    cout<<ans.size()<<endl;

   for(int i = 0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }




//   Compilation Time code //
cout << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
return 0;
}