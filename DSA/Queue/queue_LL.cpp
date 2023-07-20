//implementation of queue using linked list

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node*next;
};

node*create(){
    node*nn=new node();
    cout<<"Enter data in node:";
    cin>>nn->data;
    nn->next=NULL;
}

//function for pushing node at end

void push(node*head){
    node * nn =create();
    if(head==NULL){
        head=nn;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nn;
}

node*pop(node*head){
    if(head==NULL){
        return NULL;
    }
    node*temp=head;
    head=head->next;
    delete(temp);
    return head;
}

void display(node*head){
    if(head==NULL){
        cout<<"queue is empty"<<endl;
    }
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"\n";
}

int main(){

    node*head=create();
    cout<<"head node created"<<endl;
    cout<<"Enter number of node to push in queue:";
    int num;
    cin>>num;
    cout<<endl;
    for(int i=0;i<num;i++){
        push(head);
    }
    cout<<"displying queue after inserting "<<num<<" node in it "<<endl;
    display(head);

    cout<<"deleting element from queue"<<endl;
    cout<<endl;
    cout<<"queue after poping element "<<endl;
    display(pop(head));

    return 0;
}


