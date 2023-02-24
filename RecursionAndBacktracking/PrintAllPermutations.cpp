#include <bits/stdc++.h>
using namespace std;

void PrintAllPermutations(vector<int>&arr,int n,int ind,vector<vector<int>>&ans){
    if(ind>=n){
        ans.push_back(arr);
    }
    for(int i=ind;i<n;i++){
        swap(arr[i],arr[ind]);
        
        PrintAllPermutations(arr,n,ind+1,ans);
        swap(arr[i],arr[ind]);
    }
}

int main(){
    //Write a program to print all the permutations of a given array 
    
    vector<vector<int>>ans;
    vector<int>ds;
    vector<int> arr={1,2,3};
    PrintAllPermutations(arr,3,0,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
