#include <bits/stdc++.h>

using namespace std;

int firstocc(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]== key && arr[mid-1]!=arr[mid]){
            return mid;
        }
        else if(arr[mid]>key || arr[mid-1]==arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}
int lastocc(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]== key && arr[mid+1]!=arr[mid]){
            return mid;
        }
        else if(arr[mid]<key || arr[mid+1]==arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}

int sqrtint(int n){
    int s=1;
    int e=n;
    int mid;
    int ans=1;
    while(s<=e){
        mid=(s+e)/2;
        if(mid*mid==n){
           ans=mid;
        }
        else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

void searchininfisorted(int arr[],int target){
    int s=0;
    while(arr[i]<target){
        
        i+=2;
        
    }
    int ans=binary_search(arr[],arr[i-2],arr[i]);//or even binary_search(arr[],arr[i-2],arr[i-1])
}
int main()
{   
    //First and last occurence indexes in sorted array 
    int arr[]={1,2,2,3,4,5,5,5,5,6,7};
    cout<<firstocc(arr,11,5)<<endl;
    cout<<lastocc(arr,11,5)<<endl;
    //Integral value of square root 
    cout<<sqrtint(101)<<endl;
    //Search in infinite sized sorted array 
    
    return 0;
}

