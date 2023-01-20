#include <bits/stdc++.h>

using namespace std;
void PrintArr(int arr[],int n){
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void RemZeroToEnd(int arr[],int n){
    int ct=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[ct],arr[i]);
            ct++;
        }
    }
}

void PrintLeadersOfArr(int arr[],int n){
    for(int i=0;i<n;i++){
        bool isLead=true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                isLead=false;
            }
        }
        if(isLead){
            cout<<arr[i]<<" ";
        }
    }
    cout<<arr[n-1]<<endl;
}

void PrintLeadersOfArrOptimized(int arr[], int n){
    int lead=arr[n-1];
    cout<<arr[n-1]<<" ";
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[n-1]){
            lead=arr[i];
            cout<<arr[i]<<" ";
        }
    }
    
}
int main()
{   
    //Move ALl Zeroes to the end of the array 
    //Print all the leaders of the given array 
    int arr[]={10,8,0,0,12,0};
    RemZeroToEnd(arr,6);
    PrintArr(arr,6);
    cout<<endl;
    int arr2[]={7,10,4,3,6,5,2};
    PrintLeadersOfArr(arr2,6);
    cout<<endl;
    PrintLeadersOfArrOptimized(arr2,6);
    

    return 0;
}
