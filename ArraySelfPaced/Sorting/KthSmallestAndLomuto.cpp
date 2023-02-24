#include <iostream>

using namespace std;

int LumotoPartition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

int KthSmallest(int arr[],int n,int k){
    int l=0;
     int r=n-1;
     while(l<r){
         int pi=LumotoPartition(arr,l,r);
         if(pi==k-1){
             return arr[pi];
         }
         else if(pi<k-1){
             l=pi+1;
         }
         else{
             r=pi-1;
         }
         
     }
}
int main()
{
     int arr[]={2,3,1,6,4};
     //Finding KthSmallest using LumotoPartition
     cout<<KthSmallest(arr,5,4);
    
    return 0;
}
