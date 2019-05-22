//Level order traversal using queue
#include<iostream>
#include<queue>

using namespace std;


struct Node{
    int data;
    struct Node *left,*right;
    Node(int da){
    data=da;
    left=NULL;
    right=NULL;
    }
};


void lvlorder(struct Node* root){
    struct Node *temp;
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }

    }
}



struct Node* insert(struct Node* root,int key)
{
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
 }
}

int main(){

int n,c=0;
cout<<"\nEnter no of nodes ";
cin>>n;
struct Node *root=NULL;
while(n>0){
    if(c==0)
    {
        cin>>c;
        root=insert(root,c);
        c++;
    }
    else{
        cin>>c;
        insert(root,c);
    }


    n--;
}


lvlorder(root);
return 0;
}
