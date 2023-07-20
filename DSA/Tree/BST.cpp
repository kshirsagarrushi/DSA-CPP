#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertIntoBST(node* root, int data) {
    if (root == NULL) {
        root = new node(data);
        return root;
    }
    if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }
    return root; // Return the modified root after insertion
}

void takeInput(node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//search function in recursive way
bool recSearchBST(node* root, int x) {
    if (root == NULL) {
        return false;
    }
    if (root->data == x) {
        return true;
    }
    if (root->data < x) {
        return recSearchBST(root->right, x);
    } else {
        return recSearchBST(root->left, x);
    }
}

//search function in iterative way
bool itSearchBST(node*root,int data){
    if(root==NULL){
        return false;
    }
    node*temp=root;
    while(temp!=NULL){
        if(temp->data=data){
            return true;
        }
        if(temp->data<data){
            return itSearchBST(temp->right,data);
        }else{
            return itSearchBST(temp->left,data);
        }
    }
}

//min function to find minimum node value in BST

node* min(node*root){
    if(root==NULL){
        return;
    }
    node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

//max function to find maximum value in BST
node* max(node*root){
    if(root==NULL){
        return;
    }
    node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

node* deleteFromBST(node*root,int data){
    if(root==NULL){
        return root;
    }
    if(root->data==data){
        //0 child
        if(root->left ==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }
        //1 child
        //left child
        if(root->data!=NULL && root->right==NULL){
            node*temp=root->left;
            delete(root);
            return temp;
        }
        //right child
        if(root->data==NULL && root->right!=NULL){
            node*temp=root->right;
            delete(root);
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=min(root->left)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }

    }
    if(root->data<data){
        root->right=deleteFromBST(root->right,data);
        return root;
    }
    else{
        root->left=deleteFromBST(root->left,data);
        return root;
    }
}

int main() {
    node* root = NULL;
    cout << "Enter data to create BST " << endl;

    takeInput(root);

    cout << "printing data in bst" << endl;
    inorder(root);
    cout<<endl;

    // itSearchBST(root, 5) ? cout<<"yes":cout<<"No";

    min(root);
    cout<<endl;
    max(root);
    
    return 0;
}

//inorder predecessor : largest node from left subtree of that node
//inorder successor : smallest node from right subtree of that node