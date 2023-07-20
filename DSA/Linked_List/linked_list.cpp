//singly linked list implementation

#include<bits/stdc++.h>
using namespace std;

//blueprint of node
struct node{
    int data;
    struct node* next;
};

//function to create new node
struct node* create(){
    struct node*nn=new struct node();
    cout<<"Enter data in Node : ";
    cin>>nn->data;
    nn->next=NULL;
    return nn;
}

//insert function for insertion of node at last
void insertEnd(node * head){
   struct node* nn=create();
    if(head==NULL){
        head=nn;
    }
    else{
        struct node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }
}

//insert at before first node
node* insertStart(node*head){
    node*temp=head;
    node*nn=create();
    head=nn;
    nn->next=temp;
    return head;
}

//function to insert node at given position
void insertPos(node*head,int pos){
    node*temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    node*nn=create();
    nn->next=temp->next;
    temp->next=nn;
}

//delete function for deletion of last node
void deleteEnd(node* head){
    node*temp1=head->next;
    node*temp2=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    delete(temp1);
    temp2->next=NULL;
}

//function to delete first node of linked list
node * deleteFirst(node* head){
    if(head==NULL){
        return NULL;
    }
    node*temp=head;
    head=head->next;
    temp->next=NULL;
    delete(temp);
    return head;// we have return new head pointer because earlier this head containes address first node in linked list but we have updated this address to the address of 2nd node in linked list. that's why we need to return head pointer unlike in deleteEnd function where head is not moving from its starting node temporaray node does all changes.
}

//function to delete at given position
void deletePos(node*head,int pos,int size){
    // it can delete last positioned node also.
    node*temp1=head->next;
    node*temp2=head;
    for(int i=1;i<pos-1 && i<size;i++){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp2->next=temp1->next;
    delete(temp1);
}

//To get size of linked list
int sizeOfLinkedList(node*head){
    node*temp=head;
    int cnt=0;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

//display function
void display(node * head){
    struct node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"\n";
}

node*reverseLinkedList(node * head){
    node*a=NULL,*c=head->next;
    while(head!=NULL){
        c=head->next;
        head->next=a;
        a=head;
        head=c;
    }
    return a;
}


int main(){

    node * head=create();
    int n;
    cout<<"Head node created "<<endl;
    cout<<"Enter number of node you want to insert in list : ";
    cin>>n;
    cout<<"inserting nodes in linked list ...."<<endl;
    for(int i=0;i<n;i++){
        insertEnd(head);
    }
    cout<<"linked list"<<endl;
    display(head);


    // cout<<"deleting last node from linked list:"<<endl;
    // deleteEnd(head);
    // cout<<"linked list after deleting last node "<<endl;
    // display(head);


    // cout<<"deleting first node of linked list"<<endl;
    // node* new_head=deleteFirst(head);
    // cout<<"linked list after deletion of first node"<<endl;
    // display(new_head);


    // int size=sizeOfLinkedList(head);
    // cout<<"size of linked list is : " <<size<<endl;
    // cout<<"Enter position you want to delete : ";
    // int pos;
    // cin>>pos;
    // cout<<"deleting node of given position: "<<endl;
    // deletePos(head,pos,size);
    // cout<<"linked after deleting a node at position "<<pos<<endl;
    // display(head);

    // cout<<"Inserting element at before first node "<<endl;
    // display(insertStart(head));

    // cout<<"Inserting node at given position "<<endl;
    // cout<<"Enter position you want to insert : ";
    // int pos;
    // cin>>pos;
    // insertPos(head,pos);
    // cout<<"\n";
    // display(head);

    //reversing linked list
    display(reverseLinkedList(head));
    return 0;
}