#include<iostream>
#include<queue>

//This is not a BST but it is a binary tree 

//U can insert any element in any place by specifying its parent node


//Duplicate elements can't be inserted at any place




using namespace std;


struct Node{
    int data;
    struct Node *left,*right;
    Node(int k)
    {
        data=k;
        left=NULL;
        right=NULL;
    }
};


struct Node* findnode(struct Node* root,int p)
{
 struct Node *temp;
 queue<struct Node*> q;
 q.push(root);
 while(!q.empty())
 {
     temp=q.front();
     q.pop();
     if(temp->data==p)
     {
      //   cout<<"\nFound\n";
         break;

     }
     if(temp->left!=NULL)
     {
         q.push(temp->left);
     }
     if(temp->right!=NULL)
     {
         q.push(temp->right);
     }
 }
 return temp;

}

void insert(struct Node* root,int p,int k)
{
    struct Node *parent=findnode(root,p);
    //cout<<"\nInsert "<<parent->data<<"\n";
    if(parent->left==NULL){
        parent->left=new Node(k);
        //cout<<"\nInserted at left"<<parent->left->data<<endl;
    }
    else{
        parent->right=new Node(k);
        //cout<<"\nInserted at right"<<parent->left->data<<endl;
    }
}



void lvlorder(struct Node* root)
{
    struct Node *temp;
    queue<struct Node*> q;
    q.push(root);
    cout<<endl;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    cout<<endl;

}

int main()
{
    int n;
    cout<<"\nEnter no of nodes u want to enter ";
    cin>>n;
    int c=0;
    struct Node *root=NULL;
    while(n>=1)
    {
            if(c==0)
            {
                c++;
                cout<<"\nEnter root";
                int k;
                cin>>k;
                root=new Node(k);
            }
            else{
                int p,k;
                cout<<"\n\nEnter parent and child";
                cin>>p>>k;
                insert(root,p,k);
            }
            n--;
    }


    lvlorder(root);

    return 0;
}
