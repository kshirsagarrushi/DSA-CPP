#include<bits/stdc++.h>
using namespace std;
queue<int> q1,q2;

//push function using two queues
// void Push(int data){
//     q2.push(data);
//     while(!q1.empty()){
//         q2.push(q1.front());
//         q1.pop();
//     }
//     swap(q1,q2);
// }


//push function using one queue
void Push(int data){
    q1.push(data);
    for(int i=0;i<q1.size()-1;i++){
        q1.push(q1.front());
        q1.pop();
    }
}

void Pop(){
    q1.pop();
}
void Size(){
    q1.size();
}

int main()
{
    Push(3);
    Push(4);
    Push(5);
    Push(1);

    // Pop();
    cout<<q1.front();
    return 0;
}