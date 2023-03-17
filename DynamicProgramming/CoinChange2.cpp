#include <bits/stdc++.h>

using namespace std;

int func(int amount,vector <int> &coins){
    if(amount==0)return 0;
    int ans=INT_MAX;
    for(int coin: coins){
        if(amount-coin>=0){
        ans=min(ans+0LL,func(amount-coin,coins)+1LL);
    }}
    return ans;
}

int ans(int amount,vector <int> &coins){
    int an=func(amount,coins);
    return an==INT_MAX?-1:an;
}

int main()
{
    //Coin change 2 leetcode 
    vector <int> coins={2};
    cout<<ans(3,coins)<<endl;

    return 0;
}
