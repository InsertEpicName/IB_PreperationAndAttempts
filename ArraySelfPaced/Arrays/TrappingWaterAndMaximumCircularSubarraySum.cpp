#include <bits/stdc++.h>

using namespace std;

int watertrapped(int arr[],int n){
    int res=0;
    for(int i=1;i<n-1;i++){
        int lmax=arr[i];
        for(int j=0;j<=i;j++){
            lmax=max(lmax,arr[j]);
        }
        int rmax=arr[i];
        for(int j=i+1;j<n;j++){
            rmax=max(rmax,arr[j]);
        }
        res+=min(lmax,rmax)-arr[i]; //Minimum should be used
    }
    return res;
}

int watertrappedPreComputedAndOptimized(int arr[],int n){
    int res=0;
    int lmax[n];
    lmax[0]=arr[0];
    for(int i=1;i<n;i++){
        lmax[i]=max(arr[i],lmax[i-1]); //maximum of arr[i] and lmax of the left 
    }
    int rmax[n];
    rmax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i]=max(arr[i],rmax[i+1]); //maximum of arr[i] and rmax of the right  
    }
    for(int i=1;i<n;i++){
        res+=min(lmax[i],rmax[i])-arr[i];
    }
    return res;
}

int maxCircularSum(int arr[],int n){
    int res=arr[0];
    for(int i=0;i<n;i++){
        int curr_sum=arr[i];
        int max_sum=arr[i];
        for(int j=1;j<n;j++){
            int idx=(i+j)%n; //Starts from i+1 and goes till i-1 (circular)
            curr_sum+=arr[idx];
            max_sum=max(max_sum,curr_sum);
        }
        res=max(res,max_sum);
    }
    return res;
}


int kadane(int arr[],int n){
    int res=arr[0];
    int curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];
        curr_sum=max(curr_sum,arr[i]);
        res=max(curr_sum,res);
    }
    return res;
}

int maxCircularSumOptimized(int arr[],int n){
    
    int maxnormal=kadane(arr,n);
    if(maxnormal<0){
        return maxnormal;
    }
    int arr_sum=0;
    for(int i=0;i<n;i++){
        arr_sum+=arr[i];
        arr[i]=-arr[i];
    }
    int inverted_max=kadane(arr,n);
    int res=arr_sum+inverted_max;
    res=max(res,maxnormal);
    return res;
}

int main()
{
    //Trapping Rain Water Problem 
    int arr[]={3,0,1,2,5};
    cout<<watertrappedPreComputedAndOptimized(arr,5)<<endl;
    
    //Maximum circular sum subarray 
    int arr1[]={5,-2,3,4};
    cout<<maxCircularSum(arr1,4)<<endl;
    cout<<maxCircularSumOptimized(arr1,4)<<endl;
    return 0;
}
