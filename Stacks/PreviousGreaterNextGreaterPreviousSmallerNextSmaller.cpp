#include <bits/stdc++.h>

using namespace std;

void PreviousGreaterElem(int arr[],int n){
    stack <int> s;
    s.push(arr[0]);
    cout<<"-1 ";
    for(int i=1;i<n;i++){
        int elem=arr[i];
        while(!s.empty() && s.top()<=elem){
            s.pop();
        }
        int pge=s.empty()?-1:s.top();
        cout<<pge<<" ";
        s.push(arr[i]);
    }
}

void NextGreaterElement(int arr[],int n){
    stack <int> s;
    vector <int> v;
    s.push(arr[n-1]);
    v.push_back(-1);
    for(int i=n-2;i>=0;i--){
        int elem=arr[i];
        while(!s.empty() && s.top()<=elem){
            s.pop();
        }
        int nge=s.empty()?-1:s.top();
        v.push_back(nge);
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

void previousSmallerElement(int arr[],int n){
    stack <int> s;
    s.push(arr[0]);
    for(int i=1;i<n;i++){
        int elem=arr[i];
        while(!s.empty() && s.top()>=elem){
            s.pop();
        }
        int pse=s.empty()?-1:s.top();
        cout<<pse<<" ";
        s.push(arr[i]);
    }
}

void nextSmallerElement(int arr[],int n){
    stack <int> s;
    s.push(arr[n-1]);
    vector <int> v;
    v.push_back(-1);
    for(int i=n-2;i>=0;i--){
    int elem=arr[i];
    while(!s.empty() && s.top()>=elem){
        s.pop();
    }
    int nse=s.empty()?-1:s.top();
    v.push_back(nse);
    s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}


int main()
{
        int arr[]={5,15,10,8,6,12,4,18};
        PreviousGreaterElem(arr,8);
        cout<<endl;
        NextGreaterElement(arr,8);
        cout<<endl;
        previousSmallerElement(arr,8);
        cout<<endl;
        nextSmallerElement(arr,8);
        

    return 0;
}
