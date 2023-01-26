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
int reverse_binary_search(int arr[],int start,int end,int key){
    if(start<=end){
        int mid=end+(start-end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            return binary_search(arr,start,mid-1,key);
        }
        else{
            return binary_search(arr,mid+1,end,key);
        }
    }
    return -1;
}

int binary_search_unknown_order(int arr[],int n,int key){
    if(arr[0]<=arr[n-1]){
        return binary_search(arr,0,n,key);
    }
    else{
        return reverse_binary_search(arr,0,n,key);
    }
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

int last_occ(int arr[],int n,int key){
     int start=0;
    int end=n-1;
    int ans=-1;
    int mid;
    while(start<=end){
        mid=end+(start-end)/2;
        if(arr[mid]==key){
            ans=mid;
            start=mid+1;
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

int number_of_sorted_rotations(int arr[],int n){
    int start=0;
    int end=n-1;
    int mid;
    while(start<=end){
        if(arr[start]<=arr[end]){
            return start;
        }
        mid=end+(start-end)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;
        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
            return mid;
        }
        else if(arr[mid]<=arr[end]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
}

int search_in_sorted_rotated_array(int arr[], int n, int key) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[low] <= arr[mid]) {
            if (key >= arr[low] && key <= arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (key >= arr[mid] && key <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
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

char next_alpha(char arr[],int n,char key){
   int start=0;
    int end=n-1;
    int mid;
    int ans='#';
    while(start<=end){
        mid=end+(start-end)/2;
        if(arr[mid]==key){
            start=mid+1;
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
int main()
{
    //Write binary search for sorted array 
    //Write binary search for reverse sorted array 
    int arr[]={10,9,8,7,3};
    cout<<reverse_binary_search(arr,0,5,7)<<endl; //Note that end to be substituted here should be number of elems and not (n-1)
    //Write binary search for a sorted array but we don't know what is the order of the sorting (ascends or descends)
    cout<<binary_search_unknown_order(arr,5,7)<<endl;
    //Find first occurence of the element in sorted array 
    int arr1[]={1,1,2,2,3,3,3,4,4,5,6,7,7,7};
    cout<<first_occ(arr1,14,7)<<endl;
    cout<<last_occ(arr1,14,7)<<endl;
    //Count the number of times a sorted array has bee rotated?
    int arr2[]={15, 18, 2, 3, 6, 12};
    cout<<number_of_sorted_rotations(arr2,6)<<endl;
    //Find an element in sorted rotated array.
    cout<<search_in_sorted_rotated_array(arr2,6,3)<<endl;
    //find floor of an element in a sorted array 
    int arrn[]={1,3,7,9,11,22};
    cout<<floorelem(arrn,6,20)<<endl;
    cout<<ceilelem(arrn,6,10)<<endl;
    //Next alphabetical element in sorted alphabetical array 
    char arrp[]={'a','g','j','m'};
    char key='k';
    cout<<next_alpha(arrp,4,key)<<endl;
    return 0;
}
