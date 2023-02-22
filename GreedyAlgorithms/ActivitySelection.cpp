
#include <bits/stdc++.h>

using namespace std;

bool mycmp(pair <int,int> &a, pair <int,int> &b){
    return a.second<b.second;
}

int ActivitySelection(vector<pair<int,int>>&v){
    sort(v.begin(),v.end(),mycmp);
    int res=1;
    int prev=0;
    int n=v.size();
    for(int curr=1;curr<n;curr++){
        if(v[curr].first>=v[prev].second){
            res++;
            prev=curr;
        }
    }
    return res;
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
    
    //Question 2: Activity selection problem 
    //Given a vector of pairs which includes the start and finish time in each entry 
    //Find the number of maximum independent activities performed 
    vector <pair<int,int>> v={{3,8},{2,4},{1,3},{25,30}};
    cout<<ActivitySelection(v);
    
    return 0;
}
