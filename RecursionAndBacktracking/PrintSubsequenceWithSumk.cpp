#include <bits/stdc++.h>
using namespace std;

void PrintSubsequences(int arr[],int n,int sum,int k,int ind,vector<vector<int>>&ans,vector<int>&ds){
    if(ind>=n){
        if(sum==k){
        ans.push_back(ds);
        }
        return;
    }
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    PrintSubsequences(arr,n,sum,k,ind+1,ans,ds);
    ds.pop_back();
    sum-=arr[ind];
    PrintSubsequences(arr,n,sum,k,ind+1,ans,ds);
}

int main(){
    //Write a program to print all the subsequences of an array 
    vector<vector<int>>ans;
    vector<int>ds;
    int arr[]={1,2,3};
    PrintSubsequences(arr,3,0,3,0,ans,ds);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
