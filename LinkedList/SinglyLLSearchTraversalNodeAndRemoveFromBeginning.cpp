#include <bits/stdc++.h>

using namespace std;

struct node{
  int data;
  node* next;
  node (int x){
      next=NULL;
      data=x;
  }
};

void printll(node *head){
    if(head==NULL){
        return;
    }
    cout<<(head->data)<<endl;
    printll(head->next);
}

node *Deletefirstnode(node *head){
    if(head==NULL){
        return NULL;
    }
    node *temp=head->next;
    delete head;
    return temp;
}

//Recursive searching in singly LL

int search(node *head,int key){
    if(head==NULL){
        return -1;
    }
    if(head->data==key){
        return 1;
    }
    else{
        int res=search(head->next,key);
        if(res==-1)return -1;
        else return (res+1);
    }
    
}

int main()
{
    //Linked List practise 
    node *head=new node (10);
    node *temp1=new node(20);
    node *temp2=new node (30);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=new node (40);
    printll(Deletefirstnode(head));
    // cout<<search(head,20);
    
    return 0;
}
