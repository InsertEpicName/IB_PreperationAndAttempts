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

node *insertAtBeginningOfCircularLL(node *head,int key){
    node *insert=new node (key);
    if(head==NULL){
        insert->next=insert;
        return insert;
    }
    node *temp=head->next;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=insert;
    insert->next=head;
    return insert;
}

node *deleteKthNodeFromCLL(node *head,int k){
    // if(k==1){
    //     //Write deleteheadfunction 
    // }
    
    node *temp=head;
    for(int i=0;i<k-2;i++){
        temp=temp->next;
    }
    node *curr=temp->next;
    temp->next=temp->next->next;
    delete curr;
    return head;
}
void printLL(node *head){
    cout<<(head->data)<<endl;
    node *i=head->next;
    for(; i!=head;i=i->next){
        cout<<(i->data)<<endl;
    }
    
}

int main()
{   node *head=new node (10);
    node *temp1=new node (20);
    node *temp2=new node (30);
    node *temp3=new node (40);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=head;
    printLL(insertAtBeginningOfCircularLL(insertAtBeginningOfCircularLL(deleteKthNodeFromCLL(head,2),5),3));

    return 0;
}
