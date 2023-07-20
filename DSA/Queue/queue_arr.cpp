#include<bits/stdc++.h>
using namespace std;
#define N 5
int front=-1;
int rear=-1;

//function to insert elements into the queue
void enqueue(int * arr,int data){
    //rear at last index of an array
    if(rear==N-1){
        cout<<"queue is full"<<endl;
    }
    //array is empty
    else if(front==-1 && rear==-1){
        front=0;rear=0;
        arr[rear]=data;
    }
    //some elements are there in array
    else{
        rear++;
        arr[rear]=data;
    }
}

void dequeue(int * arr){
    //if queue is empty
    if(front==-1 && rear==-1){
        cout<<"Queue is empty can't delete "<<endl;
    }
    else if(front==rear){
        front=rear=1;
    }
    else{
        cout<<"deleted element : "<<arr[front]<<endl;
        front++;
    }
}

//function to display elements from queue
void display(int* arr){
    //array is empty
    if(front==-1 && rear==-1){
        cout<<"queue is empty"<<endl;
    }
    //an array have elements in it.
    else{
        for(int i=front;i<rear+1;i++){
            cout<<arr[i]<<" ";
        }
    }
}

// function to take data each time
int return_data(){
    int data;
    cout<<"enter data for enqueue operation : ";
    cin>>data;
    return data;
}

int main(){
    int arr[N]; 
    enqueue(arr,return_data());
    enqueue(arr,return_data());
    enqueue(arr,return_data());
    cout<<"queue after enqueue operation"<<endl;
    display(arr);
    cout<<endl;
    cout<<"calling dequeue operation "<<endl;
    dequeue(arr);
    cout<< "queue after dequeue operation "<<endl;
    display(arr);
    return 0;
}