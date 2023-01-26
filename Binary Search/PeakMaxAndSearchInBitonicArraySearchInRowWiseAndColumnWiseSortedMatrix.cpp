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

int peak_elem(int arr[],int n)
{
    int start=0;
    int end=n-1;
    int mid;
    while(start<=end){
        mid=end+(start-end)/2;
        if(mid>0 && mid<n-1){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]<arr[mid+1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        else if(mid==0){
            if(arr[0]>arr[1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if(arr[n-1]>arr[n-2]){
                return (n-1);
            }
            else{
                return (n-2);
            }
        }
    }
}

int Search_in_bitonic(int arr[],int n,int key){
    int peak=peak_elem(arr,n);
    int idx1=binary_search(arr,0,peak-1,key);
    int idx2=binary_search(arr,peak+1,n,key);
    return idx1+idx2+1;
}

int main()
{
    //Find peak element in an array 
    int arr[]={5,10,20,15};
    cout<<peak_elem(arr,4)<<endl;
    //Bitonic array means an array which has only one maxima (hence maximum element in bitonic array is its peak element)
    //Search in bitonic array 
    //Before peak and after peak everything is sorted
    //Hence, we need to first find peak, then apply binary search in both sides, one will return -1 and other will return index 
    cout<<Search_in_bitonic(arr,4,10)<<endl;
    
    //Search in row wise and column wise sorted array 
    
    cout<<"Type in the number of rows"<<endl;
    int n;
    cin>>n;
    cout<<"Type in the number of columns"<<endl;
    int m;
    cin>>m;
    cout<<"Type in the key you want to search"<<endl;
    int key;
    cin>>key;
    int two[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>two[i][j];
        }
    }
    int i=0;
    int j=m-1;
    while(i>=0 && i<n && j>=0 && j<m){
        if(two[i][j]<key){
            i++;
        }
        else if(two[i][j]>key){
            j--;
        }
        else{
            cout<<i<<" "<<j<<endl;
            break;
        }
    }
    
    return 0;
}
