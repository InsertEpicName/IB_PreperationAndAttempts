#include <bits/stdc++.h>

using namespace std;

int ChocolateDist(int arr[],int n,int k){
    sort(arr,arr+n);
    int diff=arr[k-1]-arr[0];
    for(int i=0;i+k-1<n;i++){
        diff=min(diff,arr[i+k-1]-arr[i]);
    }
    return diff;
}

void DNFAlgoSort012(int arr[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid++],arr[low++]);
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high--]);
        }
    }
}

void printarr(int arr[],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    //Chocolate distribution problem 
    int arr[]={7,3,2,4,9,12,56};
    cout<<ChocolateDist(arr,7,3)<<endl;
    int arr1[]={0,2,1,2,1,0,0,1,2};
    DNFAlgoSort012(arr1,9);
    printarr(arr1,9);
    return 0;
}
