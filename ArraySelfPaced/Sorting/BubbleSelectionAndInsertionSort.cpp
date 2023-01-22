#include <bits/stdc++.h>

using namespace std;

void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        
        if(swapped==false)
        {
            break;
        }
    }
}

void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[min],arr[i]);
        }
    }
}


void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
        arr[j+1]=arr[j];
        j--;
        }
        
        arr[j+1]=key;
    }    
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    //Bubble selection and insertion sort 
    int arr[]={1,3,2,6,4,5,7,2};
    insertionSort(arr,8);
    printarr(arr,8);

    return 0;
}
