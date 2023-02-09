#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
struct MyStack{
    int cap;
    int top;
    int sz;
    node *head;
    MyStack(int x){
        cap=x;
        top=-1;
        head=new node(x);
        sz=1;
    }
    node *push(int x){
        node *temp=new node (x);
        if(head==NULL){
         return temp;   
        }
        temp->next=head;
        head=temp;
        sz++;
        return head;
    }
    node *pop(){
        int c=head->data;
        node *temp=head;
        head=head->next;
        delete(temp);
        sz--;
        return head;
    }
    int size(){
        return sz;
    }
    void peek(){
        cout<<(head->data)<<endl;
    }
    bool isEmpty(){
        return (head==NULL);
    }
};

int main()
{   MyStack s(10);
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
