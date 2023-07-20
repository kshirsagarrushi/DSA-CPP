//implemenation of linked linked list

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*next;
};

//function to create new node
node* create(){
    node * nn=new node();
    cout<<"Enter data in node: ";
    cin>>nn->data;
    nn->next=nn;
    return nn;
}

//function to insert node at end
void insertEnd(node*head){
    node*nn=create();
    if(head==NULL){
        head=nn;
    }
    else{
        node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=nn;
        nn->next=head;
    }

}

//function to insert node at start of linked list
node* insertStart(node*head){
    node*nn=create();
    if(head==NULL){
        head=nn;
    }else{
        node * temp=head;
        nn->next=head;
        head=nn;
    }
    return head;
}

//function to insert element at given position
void insertPos(node*head, int pos){
    node*nn=create();
    node*temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    nn->next=temp->next;
    // nn->prev=temp;
    temp->next=nn;
}

//function to delete node from end of linked list
void deleteEnd(node*head){
    if(head==NULL){
        return;
    }
    else{
        node*temp1,*temp2;
        temp1=head->next;
        temp2=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        delete(temp1);
        temp2->next=NULL;
    }
}

//function to delete element from start of list
node* deleteStart(node*head){
    node*temp=head;
    head=head->next;
    delete(temp);
    // head->prev=NULL;
    return head;
}

//function to display linked list
void display(node *head){
    if(head==NULL){
        return;
    }
    else{
        node*temp=head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        while(temp!=head);
        cout<<"\n";
    }
}

int main(){

    node*head=create();
    cout<<"Head node created"<<endl;
    cout<<"linked list"<<endl;
    display(head);
    
    cout<<"Inserting node at the end of the list"<<endl;
    insertEnd(head);
    display(head);
    
    cout<<"Inserting node at first of node "<<endl;
    display(insertStart(head));
    

    // cout<<"linked list after inserting node at end of list"<<endl;
    // display(head);

    // cout<<"deleting from end of linked list "<<endl;
    // deleteEnd(head);
    // cout<<"linked list after deleting last node "<<endl;
    // display(head);

    // cout<<"deleting from first of linked list "<<endl;
    // cout<<"linked list after deleting last node "<<endl;
    // display(deleteStart(head));

    // int pos;
    // cout<<"Enter at which position you want to insert new node : ";
    // cin>>pos;

    // insertPos(head,pos);
    // display(head);


    return 0;
}