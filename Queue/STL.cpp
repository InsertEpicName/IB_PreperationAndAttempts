#include <bits/stdc++.h>

using namespace std;



int main() {
   queue <int> q;
   q.push(5);
   q.push(6);
   q.push(8);
//   q.pop();
   while(!q.empty()){
       cout<<q.front()<<" ";
       cout<<q.size()<<" ";
       q.pop();
   }
   
    return 0;
}
