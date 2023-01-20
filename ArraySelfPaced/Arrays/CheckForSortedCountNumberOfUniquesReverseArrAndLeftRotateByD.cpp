#include <bits/stdc++.h>

using namespace std;

bool isSortedArr(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

void revarr(int arr[],int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        swap(arr[s++],arr[e--]);
    }
}

int removeDups(int arr[],int n){
    int arr1[n];
    arr1[0]=arr[0];
    int ct=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr1[ct]){
            ct++;
            arr1[ct]=arr[i];
        }
        else{
            continue;
        }
    }
    return ct+1;
}

int removeDupsOptimized(int arr[],int n){
    int ct=0; 
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[ct]){
            ct++;
        }
        else{
            continue;
        }
    }
    return ct+1;
}

void leftRot(int arr[],int n){
    int last=arr[0];
    for(int i=0;i<n;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=last;
}

void leftRotByD(int arr[],int n,int d){
    int p=1;
    while(p<=d){
        leftRot(arr,n);
        p++;
    }
}

int main()
{   
    //Check to see whether array sorted or not
    //Reverse an array 
    //Remove dups and return new size
    //Left rotate one time
    // left rotate by d elements
    int arr[]={1,2,3,4,5,6,7,8,8};
    cout<<isSortedArr(arr,9)<<endl;
    revarr(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<removeDups(arr,9)<<endl;
    cout<<removeDupsOptimized(arr,9)<<endl;
    leftRotByD(arr,9,2);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
