#include<iostream>
#include<queue>

//Hi this is Prethiv "SO CALLED THE C PROGRAMMER"

//This is not a BST but it is a binary tree

//U can insert any element in any place by specifying its parent node


//Duplicate elements can't be inserted at any place




using namespace std;

/*Using structure i am specifying node u can do it using class also if u r familiar with that*/

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

/*
  find node function returns the desired node with its key matching argument p.
  
  i am using level order traversal to find where the node matches with the data p
  
  if the found is found i am breaking the loop
  
  and return the desired node
  
*/



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


/*
    This binary tree insertion differs froom BST insertion in BST u insert data based on < than or greater than value
    but in binary tree u just insert element based on parent value (Edge kind of insertion)
    
    in insert function we have three arguments one specifying root of the tree , Its parent node data value and inserting node data value
    
    using findnode function i am finding the parent node by passing root and parent node data value
    
    once the parent is found i am checking first left side is null or not if null insert st the left
    else insert at right
    
    
*/

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



/*
  I am using queue for level order traversal
  
  I am pushing the root element into the queue
  
  loop until the queue gets empty 
  
  on every iteration get the front element of the queue and store it in a temporary node
  print that temporary node data and pop the front node out of the queue
  
  check if the left and rigth side of temporary node is not null if it is not a null value then insert the node into the loop
  
  
*/


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


/*
 Findlast function returns the last node in tree 
  eg:
          90
          / \
         89  78
        / \
      12  34
      Tree 1
      
      in Tree 1 Last node is 78
      
  eg:
          89
         /  \
        67   90
            /
           56
         Tree 2
         
         In tree2 Last node is 56
      
      
*/

struct Node* findlast(struct Node* root){
    struct Node *temp=root;
    struct Node *prev;
    while(temp!=NULL){
        if(temp->right!=NULL){
                prev=temp;
            temp=temp->right;
            if(temp->left==NULL && temp->right==NULL){
                    prev->right=NULL;
                break;
            }
                continue;
        }
        if(temp->left!=NULL){
            prev=temp;
            temp=temp->left;
            if(temp->left==NULL && temp->right==NULL){
                prev->left=NULL;
                break;
            }
            continue;
        }
    }
    return temp;
}



/*
  Delete node function takes two arguments one is the root of the tree and the other is data of the node to be deleted
  
  First I am finding the lastnode from the tree
  
  Then using findnode function i am finding the node to be deleted
  
  I am just storing the last node value in del node
  
  then detaching the lastnode from the tree
  
  This detaching logic is shown In findlast function itself

*/
void deletenode(struct Node* root,int dnode){
    struct Node *lastnode=findlast(root);
    struct Node *del=findnode(root,dnode);
    del->data=lastnode->data;


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

    cout<<"Enter the node u want to delete";
    cin>>n;

    deletenode(root,n);


    lvlorder(root);

    return 0;
}
