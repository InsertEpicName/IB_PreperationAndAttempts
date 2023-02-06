#include <bits/stdc++.h>

using namespace std;

//Node for Doubly LL 
struct node{
    int data;
    node *next;
    node *prev;
    node (int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};

node *insertAtBegginingofDLL(node *head,int key){
    node *p=new node (key);
    if(head==NULL){
        return p;
    }
    else{
        head->prev=p;
        p->next=head;
        return p;
    }
}

node *DeleteHeadOfDLL(node *head){
    if(head==NULL){
        return NULL;
    }
    else{
        node *temp=head->next;
        delete head;
        return temp;
    }
}
node *insertAtTheEndofDLL(node *head,int key){
    node *temp=head;
    node *p=new node (key);
    if(head==NULL){
        return p;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
    return head;
}


node *ReverseADLL(node *head){
        node *temp=NULL;
        node *curr=head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        while(curr!=NULL){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }
        curr->prev=curr->next;
        curr->next=NULL;
        return curr;
}

void printDLL(node *head){
    if(head==NULL){
        return;
    }
    cout<<(head->data)<<endl;
    printDLL(head->next);
}
int main()
{
    node *head=new node (10);
    head->next=new node (20);
    head->next->next=new node (30);
    head->next->next->next= new node (40);
    // printDLL(insertAtBegginingofDLL(insertAtTheEndofDLL(DeleteHeadOfDLL(head),50),0));
    printDLL(ReverseADLL(head));    
    
    return 0;
}
