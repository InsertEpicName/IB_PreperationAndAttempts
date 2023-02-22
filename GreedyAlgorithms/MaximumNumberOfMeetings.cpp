
#include <bits/stdc++.h>

using namespace std;

bool mycmpForMaxMeetings(pair <int,int> &a, pair <int,int> &b){
    return a.second<b.second;
}

int Maxmeetings(vector <pair<int,int>> &v){
    sort(v.begin(),v.end(),mycmpForMaxMeetings);
    int res=1;
    int prev=0;
    int n=v.size();
    cout<<"1"<<" ";
    for(int curr=1;curr<n;curr++){
        if(v[curr].first>=v[prev].second){
            res++;
            prev=curr;
            cout<<(curr+1)<<" ";
        }
    }
    cout<<endl;
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
    
    //Question 4: Find maximum number of meetings that can be taken place in a room given a vector of pairs
    //The first entry of each pair tells the start time and second entry tells the ending time 
    
    
    //Approach: We will obviously try our ending time to be as minimum as possible so that we can have
    //next meetings (as much as possible because there are limited hours in a day)
    
    
    vector <pair<int,int>> v={{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
    
    cout<<Maxmeetings(v)<<endl;
    
    return 0;
}
