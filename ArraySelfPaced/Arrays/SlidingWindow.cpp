#include <bits/stdc++.h>

using namespace std;

int max3sumsubarray(int arr[],int n,int k){
    int maxsum=0;
    int curr_sum=0;
    for(int i=0;i<k;i++){
        curr_sum+=arr[i];
    }
    maxsum=max(maxsum,curr_sum);
    for(int i=k;i<n;i++){
        curr_sum+=arr[i]-arr[i-k];
        maxsum=max(curr_sum,maxsum);
    }
    return maxsum;
}

bool CheckWhetherSubarrayWithGivenSum(int arr[],int n,int target){
    int s=0;
    int sum=arr[0];
    for(int e=1;e<n;e++){
        while(s<e-1 && sum>target){
            sum-=arr[s];
            s++;
        }
        if(sum==target){
            return true;
        }
        if(e<n){
            sum+=arr[e];
        }
    }
    return false;
}

void mbonacci(int n){
    vector <int> v(n+1,-1);
    v[0]=0;
    v[1]=1;
    v[2]=2;
    for(int i=3;i<n;i++){
        v[i]=v[i-1]+v[i-2]+v[i-3];
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
int main()
{
    //Sliding Window Technique
    //Take subarray of 3 (consecutive) and then return the max sum subarray 
    int arr[]={1,8,30,-5,20,7};
    cout<<max3sumsubarray(arr,6,3)<<endl;
    //Given an array with non negative integers, check if there is a subarray with given sum 
    int arr1[]={1,4,20,3,10,5};
    cout<<CheckWhetherSubarrayWithGivenSum(arr1,6,33)<<endl;
    //Print the mbonacci series 
    mbonacci(5);
    return 0;
}
