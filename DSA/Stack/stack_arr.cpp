#include<bits/stdc++.h>
using namespace std;
#define size 5
int Stack[size];
int top=-1;

void Push(){
    int val;
    cout<<"Enter data in stack : ";
    cin>>val;
    Stack[++top]=val;
}

bool isempty(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return true;
    }
    return false;
}

void Pop(){
    if(isempty()){
        cout<<"stack is empty can't pop it out "<<endl;
    }
    top--;
}
void Top(){
    cout<<"Top of stack is : "<<Stack[top]<<endl;
}

void Size(){
    cout<<"size of stack is : "<<top+1<<endl;
}

int main()
{
    cout<<"pushing elements in stack "<<endl;
    Push();
    Push();
    Push();
    Push();
    Top();
    cout<<endl;
    cout<<"poping elements in stack "<<endl;
    Pop();
    cout<<endl;
    Size();
    Top();
    


    return 0;
}