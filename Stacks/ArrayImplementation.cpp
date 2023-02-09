#include <bits/stdc++.h>

using namespace std;

struct MyStack{
int top;
int *arr;
int cap;
MyStack(int c){
    cap=c;
    top=-1;
    arr= new int[c];
}
void push(int x){
    if(top==cap-1){
        cout<<"StackOverFlow"<<endl;
    }
    else{
        top++;
        arr[top]=x;
        cout<<"Inserted "<<x<<" into stack successfully"<<endl;
    }
}
void pop(){
    if(top==-1){
        cout<<"Stack is Empty. Nothing to pop"<<endl;
    }
    else{
        int x=arr[top];
        top--;
        cout<<"Element "<<x<<" has been popped out"<<endl;
    }
}

void peek(){
    if(top==-1){
        cout<<"Nothing to peek, stack is empty"<<endl;
    }
    else{
        cout<<arr[top]<<endl;
    }
}
void size(){
    cout<<(top-1)<<endl;
}
bool isEmpty(){
    return (top==-1);
}
};

int main()
{ 
    MyStack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    while(!s.isEmpty()){
        s.peek();
        s.pop();
    }
    
    

    return 0;
}
