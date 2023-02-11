#include <bits/stdc++.h>

using namespace std;

//Recursive reverse of queue
void revque(queue <int> &q){
    if(q.empty()){
        return;
    }    
    int x=q.front();
    q.pop();
    revque(q);
    q.push(x);
    
}

//Iterative reversal of queue
void Iterative(queue <int> &q){
    stack <int>s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
int main() {
   //Implement a stack using queue 
   queue <int> q;
   q.push(1);
   q.push(2);
   q.push(3);
   revque(q);
   while(!q.empty()){
       cout<<q.front()<<" ";
       q.pop();
   }
   Iterative(q);
   cout<<endl;
   while(!q.empty()){
       cout<<q.front()<<" ";
       q.pop();
   }
    return 0;
}
