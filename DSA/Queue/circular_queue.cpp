//implementation of circular queue using array

#include<iostream>
using namespace std;
#define N 5
int front=-1;
int rear=-1;
int queue[N];

//function to insert elements into queue
void enqueue(int data){
    if((rear+1)%N==front){
        cout<<"\nQueue is full "<<endl;
    }
    else if(rear==-1 && front==-1){
        rear=front=0;
        queue[rear]=data;
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=data;
    }
}

void dequeue(){
    if(rear==-1 && front==-1){
        cout<<"\nQueue is empty "<<endl;
    }
    //if only one element is there in queue
    else if(front==rear){
        front=rear=-1;
    }
    else{
        cout<<"\ndequeued element : "<<queue[front]<<endl;
        front=(front+1)%N;
    }
}

void display(){
    int i=front;
    if(rear==-1 && front==-1){
        cout<<"\nQueue is empty "<<endl;
    }
    else{
        while(i!=rear){
            cout<<queue[i]<<" ";
            i=(i+1)%N;
        }
    }
    cout<<queue[rear];
}

void peak(){
    if(rear==-1 && front==-1){
        cout<<"\nQueue is empty "<<endl;
    }else{
        cout<<"\n Peak element is : "<<queue[front]<<endl;
    }
}

int main()
{
    cout<<"inserting elements in queue"<<endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    enqueue(60);
    display();
    peak();
    return 0;
}


