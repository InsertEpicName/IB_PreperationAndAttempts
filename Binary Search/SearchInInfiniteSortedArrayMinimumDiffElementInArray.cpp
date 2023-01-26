#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int start,int end,int key){
    if(start<=end){
        int mid=end+(start-end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            return binary_search(arr,start,mid-1,key);
        }
        else{
            return binary_search(arr,mid+1,end,key);
        }
    }
    return -1;
}

int first_occ(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    int ans=-1;
    int mid;
    while(start<=end){
        mid=end+(start-end)/2;
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

int floorelem(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    int mid;
    int ans=-1;
    while(start<=end){
        mid=end+(start-end)/2;
        if(arr[mid]==key){
            ans= mid;
        }
        else if(arr[mid]<key){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

int ceilelem(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    int mid;
    int ans=-1;
    while(start<=end){
        mid=end+(start-end)/2;
        if(arr[mid]==key){
            ans= mid;
        }
        else if(arr[mid]>key){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;    
}

int Search_in_Infinite_Array(int arr[],int key){
    int start=0;
    int end=1;
    while(key>arr[end]){ //Note that this loop will only execute till key be greater than arr[end] and will break if arr[end]>key
        end=2*end;
        start=end;
    }
    int idx=binary_search(arr,start,end,key);
    return idx;
}

int index_of_first_one_in_Infinite_binary_array(int arr[]){
    int start=0;
    int end=1;
    while(arr[end]<=1){
        int prev=end;
        end=2*end;
        start=prev;
    }
    int idx=first_occ(arr,end-start+1,1);
    return idx;
}

int min_abs_diff_key(int arr[],int n,int key){
    int diff1=abs(key-floorelem(arr,n,key));
    int diff2=abs(key-ceilelem(arr,n,key));
    if(diff1<diff2){
        return arr[floorelem(arr,n,key)];
    }
    else{
        return arr[ceilelem(arr,n,key)];
    }
} 

int main()
{
    //Find position of an element in an infinite sorted array (Write a function for it)
    int arr[]={2,3,4,5,6,7,8,9,10,11,13};
    cout<<Search_in_Infinite_Array(arr,10)<<endl;
    int bin[]={0,0,0,0,0,0,0,1,1,1,1,1};
    cout<<index_of_first_one_in_Infinite_binary_array(bin)<<endl;
    //Minimum diff element in an array.
    //Given a sorted array and a key, we need to find the element from which if we subtract the given key, the absolute diff is Minimum
    int arr3[]={4,6,10};
    cout<<min_abs_diff_key(arr3,3,7)<<endl;
    return 0;
}
