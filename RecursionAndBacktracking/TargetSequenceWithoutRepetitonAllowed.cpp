#include <bits/stdc++.h>
using namespace std;

void PrintSubsequences(int arr[],int n,int target,int ind,vector<vector<int>>&ans,vector<int>&ds){
    if(ind>=n){
        if(target==0){
        ans.push_back(ds);
        }
        return;
    }
    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        PrintSubsequences(arr,n,target-arr[ind],ind+1,ans,ds);
        ds.pop_back();
    }
    PrintSubsequences(arr,n,target,ind+1,ans,ds);
}

int main(){
    //Write a program to print all the sets that add up to give sum k, the elements can repeat too
    
    vector<vector<int>>ans;
    vector<int>ds;
    int arr[]={1,2,3};
    PrintSubsequences(arr,3,4,0,ans,ds);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
