#include <bits/stdc++.h>

using namespace std;

int maxdiff(int arr[],int n){
    int diff=arr[1]-arr[0];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            diff=max(diff,arr[j]-arr[i]);
        }
    }
    return diff;
}

int maxdiffOptimized(int arr[],int n){
    int diff=arr[1]-arr[0];
    int mini=arr[0];
    for(int i=0;i<n;i++){
        mini=min(arr[i],mini);
        diff=max(diff,arr[i]-mini);
    }
    return diff;
}

void printarrFreq(int arr[],int n){
    int i=1;
    int freq=1;
    while(i<n){
        while(i<n && arr[i]==arr[i-1]){
            i++;
            freq++;
        }
        cout<<arr[i-1]<<" "<<freq<<endl;
        i++;
        freq=1;
    }
}

int maxprofit(int arr[],int start,int end){
    if(end<=start){
        return 0;
    }
    int prof=0;
    for(int i=start;i<end;i++){
        for(int j=i+1;j<end;j++){
            if(arr[j]>arr[i]){
                int curr_profit=arr[j]-arr[i]+maxprofit(arr,start,i-1) + maxprofit(arr,j+1,end);
                prof=max(prof,curr_profit);
            }
        }
    }
    return prof;
}

int maxprofitOptimized(int arr[],int n){
    int prof=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            prof+=arr[i]-arr[i-1];
        }
    }
    return prof;
}
int main()
{   
    //Maximum difference (a[j]-a[i]) such that j>i in an array a[]
    int arr[]={2,3,10,6,4,8,1};
    cout<<maxdiff(arr,7)<<endl;
    cout<<maxdiffOptimized(arr,7)<<endl;
    
    //Frequency of elements in sorted array without hashmaps and in O(n)
    int arr1[]={40,50,50,50};
    printarrFreq(arr1,4);
    
    //Given an array of stock prices, find the maximum achievable profit 
    int arr3[]={1,5,3,8,12};
    cout<<maxprofit(arr3,0,5)<<endl;
    cout<<maxprofitOptimized(arr3,5)<<endl;
    
    return 0;
}
