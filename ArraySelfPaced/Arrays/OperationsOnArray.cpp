#include <bits/stdc++.h>

using namespace std;

int search (int arr[],int n, int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}

int insert(int arr[],int n, int k, int idx){
    // if(cap==n){
    //     return n;
    // }
    for(int i=n;i>=idx;i--){
        arr[i]=arr[i-1];
    }
    
    //Important to note the line 18 
    arr[idx]=k;
    n++;
    return n;
    
}

int del (int arr[],int n,int idx){
    for(int i=idx;i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;
    return n; 
}
int main()
{   
    int arr[6]={2,3,4,5};
    insert(arr,4,2,2);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    del(arr,5,2);
    cout<<endl;
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
