#include<iostream>


using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

int solve(struct Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return root->data+max(solve(root->left),solve(root->right));
    }
}


int main(){
    struct Node *root=new Node(4);
    root->left=new Node(7);
    root->right=new Node(1);
    root->left->left=new Node(6);
    root->left->left->right=new Node(1);
    root->left->right=new Node(3);
    root->left->right->left=new Node(1);
    root->left->right->right=new Node(3);
    root->right->left=new Node(20);
    root->right->right=new Node(3);
    cout<<"\nThe maximum possible Traversal COst is "<<solve(root);
    return 0;
}
