#include <bits/stdc++.h>

using namespace std;

struct MyStack{
  queue <int> q1;
  queue <int> q2;
  void pop(){
      q1.pop();
  }
  void push(int x){
      while(!q1.empty()){
          q2.push(q1.front());
          q1.pop();
      }
      q1.push(x);
      while(!q2.empty()){
          q1.push(q2.front());
          q2.pop();
      }
  }
  int top(){
      return q1.front();
  }
  
};


int main() {
   //Implement a stack using queue 
   MyStack s;
   s.push(1);
   s.push(2);
   s.push(3);
   cout<<s.top()<<endl;
    return 0;
}
