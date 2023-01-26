#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[],int n,int k,int mx){
    int stud=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>mx){
            stud++;
            sum=arr[i];
        }
    }
    if(stud>k){
        return false;
    }
    return true;
}

int distribution(int arr[],int n,int k){
    int start=INT_MIN;
    for(int i=0;i<n;i++){
        start=max(start,arr[i]);
    }
    int end=0;
    for(int i=0;i<n;i++){
        end+=arr[i];
    }
    int mid;
    int ans=-1;
    while(start<=end){
        mid=end+(start-end)/2;
        if(isValid(arr,n,k,mid)==true){
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
    //Write a function that allocates minimum number of pages to n number of students where we are given an array of size n. 
    //Every element of the array represents the number of pages in it 
    //The distribution needs to be continous.
    //The maximum number of pages distributes should be minimum
    //Return the maximum number of pages of the partition found
    int arr[]={10,20,30,40};
    int k=2;
    cout<<distribution(arr,4,2)<<endl;
    return 0;
}
