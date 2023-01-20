#include <bits/stdc++.h>

using namespace std;

int consecutiveOnes(int arr[],int n){
    int ct=0;
    int curr=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            curr=0;
        }
        else{
            curr++;
        }
        ct=max(curr,ct);
    }
    return ct;
}

int maximumsumsubarray(int arr[],int n){
    int maxs=0;

    for(int i=0;i<n;i++){
            int sum=arr[i];
        for(int j=i+1;j<n;j++){
            sum+=arr[j];
            maxs=max(maxs,sum);
        }
    }
    return maxs;
}

int maximumsumsubarrayUsingKadane(int arr[],int n){
    int maxs=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        sum=max(sum,arr[i]); //Very Very Important Step 
        maxs=max(maxs,sum);
    }
    return maxs;
}
int main()
{   
    //Find number of consecutive ones 
    int arr[]={0,1,1,0,1,1,1};
    cout<<consecutiveOnes(arr,7)<<endl;
    //Maximum Sum subarray 
    int arr1[]={2,3,-8,7,-1,2,3};
    cout<<maximumsumsubarray(arr1,7)<<endl;
    cout<<maximumsumsubarrayUsingKadane(arr1,7)<<endl;
    return 0;
}
