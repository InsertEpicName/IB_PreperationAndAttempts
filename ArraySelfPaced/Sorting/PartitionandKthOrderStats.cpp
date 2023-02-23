#include <bits/stdc++.h>

using namespace std;

int partition(int arr[],int start, int end){
    int pivot=end;
    int i=start-1;
    for(int j=i;j<=pivot-1;j++){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return (i+2);
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int KthSmallest(int arr[],int start,int end,int k){
    if(start==end){
        if(start==k){
            return arr[start];
        }
        else{
            return -1;
        }
    }
    else{
        int pi=partition(arr,start,end);
        if(pi==k){
            return arr[pi];
            
        }
        else if(pi<k){
           return KthSmallest(arr,pi+1,end,k);
        }
        else{
           return KthSmallest(arr,start,pi-1,k);
        }
    }
}

int main()
{
    int arr[]={ 10, 7, 8, 9, 1, 5};
    // partition(arr,0,5);
    // printarr(arr,6);
    //Now find the kth smallest element using this partition function 
    cout<<KthSmallest(arr,0,5,2)<<endl;
    return 0;
}
