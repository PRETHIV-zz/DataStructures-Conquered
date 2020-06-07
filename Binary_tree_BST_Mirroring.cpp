#include <iostream> 
#include<queue>
using namespace std; 
struct Node{ 
    int data; 
    struct Node *left,*right; 
    Node(int d){
        data=d; 
        left=NULL; 
        right=NULL; 
        
    } }; 
    
struct Node* insert(struct Node* root,int key){ 
    if(root==NULL){
        return new Node(key); 
    } 
    else{ 
        if(key<=root->data){ 
            root->left=insert(root->left,key); 
        } 
        else{ 
            root->right=insert(root->right,key); 
        } 
        return root; 
    } 
} 

void inorder(struct Node* root){ 
    if(root==NULL){ 
        return; 
    } else{ 
        inorder(root->left); 
        cout<<" "<<root->data; 
        inorder(root->right); 
    } } 
    
void mirror(struct Node* root){
    queue<struct Node*> q;
    q.push(root);
    
    while(!q.empty()){
        struct Node *temp=q.front();
        q.pop();
        
        struct Node *t1=temp->right;
        temp->right=temp->left;
        temp->left=t1;
        
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        
    }
    
}

int main(){ 
    int n; 
    cout<<"Enter no of nodes u want to insert"; 
    cin>>n; 
    struct Node *tree=NULL; 
    while(n>0){ 
        int key; 
        cout<<"\nEnter the data for node "; 
        cin>>key; 
        tree=insert(tree,key); 
        n--; 
    } 
    cout<<"Inorder \n"; 
    inorder(tree); 
    mirror(tree);
    cout<<endl;
    inorder(tree);
    return 0; 
}
