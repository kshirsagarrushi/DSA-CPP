#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node*root){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    root= new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data;
    root->right=buildTree(root->right);
    return root;
}

void leverOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        
        if(temp=NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{

            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

        
    }
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

int main(){

    node*root=NULL;
    //creating a tree
    root=buildTree(root);

    //level order
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout<<"printing level order traversal : "<<endl;
    // leverOrderTraversal(root);

    //inorder traversal
    // cout<<"printing inorder traversal : "<<endl;
    // inorder(root);

    //preorder traversal
    // preorder(root);

    //postorder traversal
    postorder(root);

    return 0;
}