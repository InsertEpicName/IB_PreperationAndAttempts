#include <bits/stdc++.h>
using namespace std;

void solve(int n,string &ans,vector <int> &fact, vector <int> &digit,int &k){
    if(n==1){
        ans+=to_string(digit.back());
        return;
    }
    int ind=k/fact[n-1]; //Find the index to be used 
    if(k%fact[n-1]==0){
        ind-=1;
    }
    ans+=to_string(digit[ind]); //Adding to answer string
    digit.erase(digit.begin()+ind); //Update the digit array as we used up one of the digit
    k=k-fact[n-1]*ind;
    solve(n-1,ans,fact,digit,k);
}


string kthPerm(int n, int k){
    vector <int> fact;
    string ans="";
    int j=1;
    fact.push_back(1); //For 0's factorial
    for(int i=1;i<=n;i++){
        j*=i;
        fact.push_back(j); //For all other's factorial
    }
    vector <int> digit;
    for(int i=1;i<=n;i++){
        digit.push_back(i);
    }
    solve(n,ans,fact,digit,k);
    return ans;
}

int main(){
    cout<<kthPerm(3,5)<<endl;
    return 0;
}
