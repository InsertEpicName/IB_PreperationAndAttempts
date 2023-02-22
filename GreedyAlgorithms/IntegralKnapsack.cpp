
#include <bits/stdc++.h>

using namespace std;

int integralKnapsack(int arr[],int n,int sum){
    int coins=0;
    for(int i=0;i<n;i++){
        while(arr[i]<=sum){
            coins++;
            sum-=arr[i];
        }
    }
    return coins;
}

int main()
{
    //Greedy Algorithms 
    //These Algorithms are generally used when we are dealing with optimization problem (maximum/minimum etc.)
    
    //First question is of integral knapsack, in which we are trying to get a given sum of money using given value of coins
    //ex-> generate 52 using 10,5,2,1 coins and use least coins, hence we use 5 10's and 1 2's
    
    //Note that the Greedy Algorithms do not always work.. 
    //Example if we want the sum 20 using 18,10 and 1 ==> greedy will tell 1 18 and 2 1's that is 3 coins
    //But in minimum case, actually we require 2 10's 
    
    //General code of greedy is as follows
    
    // greedy(arr,n){
    //     for(int i=0 to n-1){
    //         if(arr[i] is feasible){
    //             sol+=arr[i];
    //         }
    //     }
    // }
    // return sol;
    
    
    //question 1: Generate the given sum of money using only given coins (the coins will be given in the form of array)
        
    int coins[]={10,5,2,1};
    int sum=52; //Example
    cout<<integralKnapsack(coins,4,52)<<endl;
    
    return 0;
}
