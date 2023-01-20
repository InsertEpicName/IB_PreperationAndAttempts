#include <bits/stdc++.h>

using namespace std;

int Largest(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int secondLargest(int arr[],int n){
    int max=Largest(arr,n);
    int secmax=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>secmax && arr[i]!=max){
            secmax=arr[i];
        }
    }
    return secmax;
}

int secmaxOptimized(int arr[],int n){
    int res=-1; int max=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[max]){
            res=max;
            max=i;
        }
        else if(arr[i]!=arr[max]){
            if(res==-1 || arr[i]>arr[res]){
                res=i;
            }
        }
    }
    return res;
}

int main()
{   
    //Largest and second Largest element in an array 
    int arr[]={1,2,3,4,5,6,7,8,12,10};
    cout<<Largest(arr,10)<<endl;
    cout<<secondLargest(arr,10)<<endl;
    cout<<secmaxOptimized(arr,10)<<endl;

    return 0;
}
