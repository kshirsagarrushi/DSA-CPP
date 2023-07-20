#include<bits/stdc++.h>
using namespace std;

//for push operation you have to follow below rules
// s1->s2
//x->s1
//s2->s1

//for pop operation you have to follow below rules
//s1.pop()

struct Queue{
    stack<int>input,output;

    // function to push elements into queue
    void push(int data){
        //pop out all elements from input stack and push into output stack
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }

        //push givend data into input stack
        input.push(data);

        //now push all elements from output stack into input stack
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    //function to pop elements from queue
    int Pop(){
        if(input.empty()){
            cout<<"queue is empty "<<endl;
            exit(0);
        }
        int val=input.top();
        input.pop();
        return val;
    }

    //return topmost element in queue
    int top(){
        if(input.empty()){
            cout<<"queue is empty"<<endl;
        }
        return input.top();
    }

    //to display elements from queue
    void display(){
        stack<int>dis;
        if(input.empty()){
            cout<<"queue is empty"<<endl;
        }
        while(!input.empty()){
            cout<<input.top()<<" ";
            dis.push(input.top());
            input.pop();
        }
        while(!dis.empty()){
            input.push(dis.top());
            dis.pop();
        }
    }

};

int main(){

    Queue q;
    cout<<"queue before push operation "<<endl;
    q.display();
    cout<<endl;
    cout<<"pushing elements in queue "<<endl;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    cout<<"queue after push operation "<<endl;
    q.display();
    cout<<endl;
    cout<<"poping elements from queue "<<endl;
    q.Pop();
    cout<<"queue after pop operation "<<endl;
    q.display();
    return 0;
}