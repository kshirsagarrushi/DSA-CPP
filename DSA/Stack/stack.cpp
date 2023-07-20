//implementation of stack using linked list
// basically stack follow criteria of LIFO i.e Last in first out.

//operations that can be performed in stack
// 1.push 
// 2.pop
// 3.top

// you can only insert and delete new node at top of stack

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node*next;
};

node*create(){
    node*nn=new struct node();
    cout<<"Enter data in new node : ";
    cin>>nn->data;
    nn->next=NULL;
    return nn;
}

node*push(node*head){
    node*nn=create();
    nn->next=head;
    head=nn;
    return head;
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

int top(node*head){
    return head->data;
}
void display(node*head){
    if(head==NULL){
        return;
    }
    else{
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
    cout<<"\n";
}

int main(){

    node*head=create();
    cout<<"head node created"<<endl;
    cout<<"data in stack"<<endl;
    display(head);

    node*new_head=push(head);
    display(new_head);

    // cout<<"\n after poping one node"<<endl;
    // display(pop(new_head));

    cout<<"top of stack is "<<top(new_head);


    return 0;
}