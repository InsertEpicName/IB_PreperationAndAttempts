#include <bits/stdc++.h>

using namespace std;


int main() {
   //Given a number n. Print first n numbers {in increasing order} such that they contain the digits from the set {5,6}
   //5,6,55,56,65,66,....
    queue<string> q;
    int n;
    cin>>n;
    q.push("5");
    q.push("6");
   for(int i=0;i<n;i++){
    //   string ans="";
       q.push(q.front()+"5");
       q.push(q.front()+"6");
       cout<<q.front()<<endl;
       q.pop();
   }
    
    return 0;
}
