#include <bits/stdc++.h>

using namespace std;

void merge(int arr[],int l,int m,int h){
    int n1=m-l+1; //The value should be (m-l+1) not (l-m+1) //Thanks to chatGPT
    int n2=h-m;
    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=arr1[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        k++;
        j++;
    }
    
}

int lumotoPartition(int arr[],int l,int h){
    int i=l-1;
    int j;
    int pivot=arr[h];
    for(int j=l;j<=(h-1);j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
            // j++;No need to write j++ here as it is being already incremented by for loop 
        }
    }
    swap(arr[i+1],arr[h]); //not (arr[i+1],pivot) -- chatGPT
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = lumotoPartition(arr, low, high);
        quickSort(arr, low, pivot - 1); //pivot-1 ..... Not pivot --chatGPT
        quickSort(arr, pivot + 1, high);
    }
}


void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void mergesort(int arr[],int l,int h){
    if(l>=h){
        return;
    }
    else{
        int mid=(l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main()
{
    //Merge sort and Quick Sort 
    int arr[]={1,3,2,6,4,5,7,2};
    quickSort(arr,0,7);
    printarr(arr,8);
    return 0;
}
